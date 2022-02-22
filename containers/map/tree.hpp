/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbari <mbari@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 14:35:25 by mbari             #+#    #+#             */
/*   Updated: 2022/02/22 22:19:19 by mbari            ###   ########.fr       */
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
		typedef typename allocator_type::reference			reference;
		typedef typename allocator_type::const_reference	const_reference;
		typedef typename allocator_type::difference_type	difference_type;
		typedef typename allocator_type::pointer			pointer;
		typedef typename allocator_type::const_pointer		const_pointer;
		typedef typename allocator_type::size_type			size_type;
		typedef ft::MapIter<pointer>							iterator;
		typedef ft::MapIter<const_pointer>					const_iterator;
		// typedef ft::reverse_iterator<pointer>				reverse_iterator;
		// typedef ft::reverse_iterator<const_pointer>			const_reverse_iterator;
		// typedef typename allocator_type::template rebind<Node_type>::other allocater_node;

	private:
		allocator_type								_alloc;
		value_compare								_comp;
		Node_type*									_root;
		Node_type*									_end;
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

	private:
		void	_inOrder(Node_type* node)
		{
			if (node != nullptr)
			{
				_inOrder(node->left);
				this->_alloc.deallocate(node, 1);
				_inOrder(node->right);
			}
		};
		int		_Height(Node_type* temp)
		{
			if (temp == nullptr)
				return (0);
			return (temp->height);
		};

		int _getBalanceFactor(Node_type* N)
		{
			if (N == NULL)
				return 0;
			return (_Height(N->left) - _Height(N->right));
		}

		Node_type* leftRotate(Node_type* x)
		{
			Node_type* y = x->right;
			Node_type* T2 = y->left;
			Node_type* p = x->parent;
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

		Node_type* rightRotate(Node_type* y)
		{
			Node_type* x = y->left;
			Node_type* T2 = x->right;
			Node_type* p = y->parent;
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

		Node_type* RightLeftRotate(Node_type* node)
		{
			node->right = rightRotate(node->right);
			return (leftRotate(node));
		};

		Node_type* LeftRightRotate(Node_type* node)
		{
			node->left = leftRotate(node->left);
			return (rightRotate(node));
		};


		Node_type*	_reBalance(Node_type* node)
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

		Node_type*	_insert(Node_type* temp, Node_type* newNode)
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

		Node_type*	_remove(Node_type* root, T key)
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
					Node_type* temp = root->right;
					this->_alloc.deallocate(root, 1);
					return (temp);
				}
				else if (root->right == nullptr)
				{
					Node_type* temp = root->left;
					this->_alloc.deallocate(root, 1);
					return (temp);
				}
				else
				{
					Node_type* MaxValue = _Max(root->left);
					root->key = MaxValue->key;
					root->left = _remove(root->left, MaxValue->key);
				}
			}
			_ReSetHeight(root);
			_reBalance(root);
			return (root);
		};

		Node_type* _search(Node_type* temp, T key)
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

		Node_type* _Min(Node_type* temp)
		{
			while (temp->left != nullptr)
				temp = temp->left;
			return (temp);
		};

		Node_type* _Max(Node_type* temp)
		{
			while (temp->right != nullptr)
				temp = temp->right;
			return (temp);
		};

		void		_ReSetHeight(Node_type* temp)
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

		Node_type*	Min()
		{
			Node_type * tmp = this->_root;

			while (tmp->left)
				tmp = tmp->left;
			return (tmp);
		};

		Node_type* Max()
		{
			Node_type* tmp = this->_root;

			while (tmp->right)
				tmp = tmp->right;
			return (tmp);
		};

		Node_type* search(T key)
		{
			if (this->_root == this->_end)
				return (nullptr);
			else
				return (_search(this->_root, key));
		};

		Node_type* successor(Node_type* node)
		{
			if (node->right != nullptr)
				return (_Min(node->right));

			Node_type* temp = node->parent;
			while (temp != nullptr && node == temp->right)
			{
				node = temp;
				temp = temp->parent;
			}
			return (temp);
		};
		Node_type* predecessor(Node_type* node)
		{
			if (node->left != nullptr)
				return (_Max(node->left));

			Node_type* temp = node->parent;
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

		void printTree(Node_type* root, Trunk *prev, bool isLeft)
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
