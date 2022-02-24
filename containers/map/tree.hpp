/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbari <mbari@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 14:35:25 by mbari             #+#    #+#             */
/*   Updated: 2022/02/24 02:44:01 by mbari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #define COUNT 10
#include "../../colors.hpp"
#include "iterator.hpp"
template <class T>
struct Node
{
	public:
		T		key;
		Node*	parent;
		Node*	left;
		Node*	right;
		int		height;

	public:
		Node(T key): key(key), left(nullptr), right(nullptr), parent(nullptr) , height(1) {};
};

template <class T, class Compare = std::less<T>, class Allocator = std::allocator<Node<T> > >
class Tree
{
	public:
		typedef T											value_type;
		typedef Compare										value_compare;
		typedef Allocator									allocator_type;
		typedef Node<value_type>							Node_type;
		typedef Node_type*									Node_ptr;

		/***********************************************************/
		/*                                                         */
		/*                                                         */
		/*             Make sure to change the rebind              */
		/*                    of std::allocator                    */
		/*               when you add the map class                */
		/*                                                         */
		/*                                                         */
		/***********************************************************/
		typedef typename allocator_type::template rebind<T>::other allocater_node;
		typedef typename allocater_node::reference			reference;
		typedef typename allocater_node::const_reference	const_reference;
		typedef typename allocater_node::difference_type	difference_type;
		typedef typename allocater_node::pointer			pointer;
		typedef typename allocater_node::const_pointer		const_pointer;
		typedef typename allocater_node::size_type			size_type;
		typedef ft::TreeIter<pointer, Node_ptr>				iterator;
		typedef ft::TreeIter<const_pointer, Node_ptr>		const_iterator;
		// typedef ft::reverse_iterator<pointer>				reverse_iterator;
		// typedef ft::reverse_iterator<const_pointer>			const_reverse_iterator;

	private:
		allocator_type								_alloc;
		value_compare								_comp;
		Node_ptr									_root;
		Node_ptr									_end;
		int											_size;

	public:
		Tree(const value_compare &compare = value_compare(), const allocator_type& alloc = allocator_type()): _size(0)
		{
			this->_alloc = alloc;
			this->_comp = compare;
			this->_end = this->_alloc.allocate(1);
			this->_root = this->_end;
		};
		~Tree()
		{
			_inOrder(this->_root);
			this->_alloc.deallocate(this->_end, 1);
		};

	public:
		iterator		begin()				{ return (iterator(this->Min())); };
		const_iterator	begin() const		{ return (const_iterator(this->Min())); };
		iterator		end()				{ return (iterator(this->_end)); };
		const_iterator	end()				{ return (const_iterator(this->_end)); };

	private:
		void	_inOrder(Node_ptr node)
		{
			if (node != nullptr)
			{
				_inOrder(node->left);
				this->_alloc.deallocate(node, 1);
				_inOrder(node->right);
			}
		};
		int		_Height(Node_ptr temp)
		{
			if (temp == nullptr)
				return (0);
			return (temp->height);
		};

		int _getBalanceFactor(Node_ptr N)
		{
			if (N == NULL)
				return 0;
			return (_Height(N->left) - _Height(N->right));
		}

		Node_ptr leftRotate(Node_ptr x)
		{
			Node_ptr y = x->right;
			Node_ptr T2 = y->left;
			Node_ptr p = x->parent;
			y->left = x;
			x->right = T2;
			if (p)
			{
				if (p->left == x)
					p->left = y;
				else
					p->right = y;
			}
			y->parent = x->parent;
			x->parent = y;
			if (T2 != nullptr)
				T2->parent = x;
			x->height = std::max(_Height(x->left), _Height(x->right)) + 1;
			y->height = std::max(_Height(y->left), _Height(y->right)) + 1;
			return y;
		};

		Node_ptr rightRotate(Node_ptr y)
		{
			Node_ptr x = y->left;
			Node_ptr T2 = x->right;
			Node_ptr p = y->parent;
			x->right = y;
			y->left = T2;
			if (p)
			{
				if (p->right == y)
					p->right = x;
				else
					p->left = x;
			}
			x->parent = y->parent;
			y->parent = x;
			if (T2 != nullptr)
				T2->parent = y;
			y->height = std::max(_Height(y->left), _Height(y->right)) + 1;
			x->height = std::max(_Height(x->left), _Height(x->right)) + 1;
			return x;
		};

		Node_ptr RightLeftRotate(Node_ptr node)
		{
			node->right = rightRotate(node->right);
			return (leftRotate(node));
		};

		Node_ptr LeftRightRotate(Node_ptr node)
		{
			node->left = leftRotate(node->left);
			return (rightRotate(node));
		};


		Node_ptr	_reBalance(Node_ptr node)
		{
			int	balanceFactor = _getBalanceFactor(node);
			if (balanceFactor > 1)
			{
				if (_getBalanceFactor(node->left) >= 0)
					return (rightRotate(node));
				else
					return (LeftRightRotate(node));
			}
			else if (balanceFactor < -1)
			{
				if (_getBalanceFactor(node->right) <= 0)
					return (leftRotate(node));
				else
					return (RightLeftRotate(node));
			}
			return (node);
		};

		Node_ptr	_insert(Node_ptr temp, Node_ptr newNode)
		{
			if (temp == nullptr)
				return (newNode);
			if (!this->_comp(temp->key, newNode->key))
				temp->left = _insert(temp->left, newNode);
			else if (this->_comp(temp->key, newNode->key))
				temp->right = _insert(temp->right, newNode);
			else
				return (temp);
			_ReSetHeight(temp);
			temp = _reBalance(temp);
			return (temp);
		};

		Node_ptr	_remove(Node_ptr root, T key)
		{
			if (root == nullptr) return (nullptr);
			// else if (key < root->key)
			else if (this->_comp(key, root->key))
				root->left = _remove(root->left, key);
			else if (this->_comp(key, root->key))
				root->right = _remove(root->right, key);
			else
			{
				if (root->left == nullptr)
				{
					Node_ptr temp = root->right;
					this->_alloc.deallocate(root, 1);
					return (temp);
				}
				else if (root->right == nullptr)
				{
					Node_ptr temp = root->left;
					this->_alloc.deallocate(root, 1);
					return (temp);
				}
				else
				{
					Node_ptr MaxValue = _Max(root->left);
					root->key = MaxValue->key;
					root->left = _remove(root->left, MaxValue->key);
				}
			}
			_ReSetHeight(root);
			_reBalance(root);
			return (root);
		};

		Node_ptr _search(Node_ptr temp, T key)
		{
			if (temp == nullptr)
				return (nullptr);

			if (temp->key == key)
				return (temp);
			else if (this->_comp(key, temp->key))
				return (_search(temp->left, key));
			else if (!this->_comp(key, temp->key))
				return (_search(temp->right, key));

			return (nullptr);
		};

		Node_ptr _Min(Node_ptr temp)
		{
			while (temp->left != nullptr)
				temp = temp->left;
			return (temp);
		};

		Node_ptr _Max(Node_ptr temp)
		{
			while (temp->right != nullptr)
				temp = temp->right;
			return (temp);
		};

		void		_ReSetHeight(Node_ptr temp)
		{
			if (!temp->left && !temp->right)
				temp->height = 1;
			else if (temp->left == nullptr)
				temp->height = 1 + temp->right->height;
			else if (temp->right == nullptr)
				temp->height = 1 + temp->left->height;
			else
				temp->height = 1 + std::max(temp->right->height, temp->left->height);
		};


	public:
		void	insert(T key)
		{
			Node_type * newnode = this->_alloc.allocate(1);
			this->_alloc.construct(newnode, key);
			if (this->_root == this->_end)
			{
				this->_root = newnode;
				this->_root->parent = this->_end;
				this->_end->left = this->_root;
			}
			else
				this->_root = _insert(this->_root, newnode);
		};

		void	remove(T key)
		{
			this->_root = _remove(this->_root, key);
		};

		Node_ptr	Min()
		{
			Node_type * tmp = this->_root;

			while (tmp->left)
				tmp = tmp->left;
			return (tmp);
		};

		Node_ptr Max()
		{
			Node_ptr tmp = this->_root;

			while (tmp->right)
				tmp = tmp->right;
			return (tmp);
		};

		Node_ptr search(T key)
		{
			if (this->_root == this->_end)
				return (nullptr);
			else
				return (_search(this->_root, key));
		};

		Node_ptr successor(Node_ptr node)
		{
			if (node->right != nullptr)
				return (_Min(node->right));

			Node_ptr temp = node->parent;
			while (temp != nullptr && node == temp->right)
			{
				node = temp;
				temp = temp->parent;
			}
			return (temp);
		};
		Node_ptr predecessor(Node_ptr node)
		{
			if (node->left != nullptr)
				return (_Max(node->left));

			Node_ptr temp = node->parent;
			while (temp != this->_end && node == temp->left)
			{
				node = temp;
				temp = temp->parent;
			}
			return (temp);
		};

		T	get_Key() const { return (this->_root->key); };
		T	get_height() const { return (this->_root->height); };

		private: /*             Private Functions for printing The tree                         */

		struct Trunk
		{
			Trunk *prev;
			std::string str;

			Trunk(Trunk *prev, std::string str)
			{
				this->prev = prev;
				this->str = str;
			}
		};

		// Helper function to print branches of the binary tree
		void showTrunks(Trunk *p)
		{
			if (p == nullptr) {
				return;
			}

			showTrunks(p->prev);
			std::cout << p->str;
		};

		void printTree(Node_ptr root, Trunk *prev, bool isLeft)
		{
			if (root == nullptr) {
				return;
			}

			std::string prev_str = "    ";
			Trunk *trunk = new Trunk(prev, prev_str);

			printTree(root->right, trunk, true);

			if (!prev) {
				trunk->str = "———";
			}
			else if (isLeft)
			{
				trunk->str = ".———";
				prev_str = "   |";
			}
			else {
				trunk->str = "`———";
				prev->str = prev_str;
			}

			showTrunks(trunk);
			std::cout << RED "{ " << root->key.first << " | " << root->key.second << " } "<< RESET;
			if (root->parent != nullptr)
				std::cout << " {P: " << root->parent->key.first << "} H: " << root->height << GREEN " FB: " << _getBalanceFactor(root) << RESET<< std::endl;
			else
				std::cout << " {P: NULL" << "} H: " << root->height  << GREEN " FB: " << _getBalanceFactor(root) << RESET << std::endl;

			// std::cout << GREEN << "ROOT Parent : " << this->_root->parent->key.first << RESET << std::endl;
			if (prev) {
				prev->str = prev_str;
			}
			trunk->str = "   |";

			printTree(root->left, trunk, false);
		};



		public: /*             print function                         */
			void	print() { printTree(this->_root, nullptr, false); };

};
