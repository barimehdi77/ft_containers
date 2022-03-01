/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbari <mbari@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 14:35:25 by mbari             #+#    #+#             */
/*   Updated: 2022/03/01 18:54:59 by mbari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #define COUNT 10
#ifndef TREE_HPP
#define TREE_HPP

#include "../../colors.hpp"
#include "iterator.hpp"

namespace ft
{
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

	template <class T, class Compare, class Allocator>
	class Tree
	{
		public:
			/***********************************************************/
			/*                                                         */
			/*             typedef all template parameters             */
			/*                                                         */
			/***********************************************************/
			typedef T															value_type;
			typedef Compare														value_compare;
			typedef Allocator													allocator_type;

		private:
			/***********************************************************/
			/*                                                         */
			/*              typedef member Types of Nodes              */
			/*                                                         */
			/***********************************************************/
			typedef typename allocator_type::template rebind<Node<T> >::other	allocator_node;
			typedef typename allocator_node::reference							node_reference;
			typedef typename allocator_node::const_reference					node_const_reference;
			typedef typename allocator_node::difference_type					node_difference_type;
			typedef typename allocator_node::pointer							node_pointer;
			typedef typename allocator_node::const_pointer						node_const_pointer;
			typedef typename allocator_node::size_type							node_size_type;
			typedef Node<value_type>											Node_type;
			typedef Node_type*													Node_ptr;

		public:
			/***********************************************************/
			/*                                                         */
			/*          typedef member Types of Tree iterator          */
			/*                                                         */
			/***********************************************************/
			typedef typename allocator_type::reference							reference;
			typedef typename allocator_type::const_reference					const_reference;
			typedef typename allocator_type::difference_type					difference_type;
			typedef typename allocator_type::pointer							pointer;
			typedef typename allocator_type::const_pointer						const_pointer;
			typedef typename allocator_type::size_type							size_type;
			typedef ft::TreeIter<pointer, Node_ptr>								iterator;
			typedef ft::TreeIter<const_pointer, Node_ptr>						const_iterator;
			// typedef ft::reverse_iterator<pointer>								reverse_iterator;
			// typedef ft::reverse_iterator<const_pointer>							const_reverse_iterator;


		private:
			/***********************************************************/
			/*                                                         */
			/*          Declare all attributes needed in Tree          */
			/*                                                         */
			/***********************************************************/
			allocator_node								_alloc;
			value_compare								_comp;
			Node_ptr									_root;
			Node_ptr									_end;
			int											_size;

		public:
			/***********************************************************/
			/*                                                         */
			/*             Tree constructor and distructor             */
			/*                                                         */
			/***********************************************************/
			Tree(const value_compare &compare = value_compare(), const allocator_type& alloc = allocator_type()): _size(0)
			{
				this->_alloc = alloc;
				this->_comp = compare;
				this->_end = this->_alloc.allocate(1);
				this->_root = this->_end;
			};
			~Tree()
			{
				if (this->_root != this->_end)
					_inOrder(this->_root);
				this->_alloc.deallocate(this->_end, 1);
			};

		public: /*             Iterators                         */
			iterator		begin()				{ return (iterator(this->Min())); };
			const_iterator	begin() const		{ return (const_iterator(this->Min())); };
			iterator		end()				{ return (iterator(this->_end)); };
			const_iterator	end() const			{ return (const_iterator(this->_end)); };

		public: /*             Capacity                         */
			bool empty() const { return (this->_size == 0); };
			size_type size() const { return (this->_size); };
			size_type	max_size()	const	{ return (std::min<size_type>(std::numeric_limits<size_type>::max() / sizeof(Node_type), std::numeric_limits<difference_type>::max())); };

		private:
			void	_inOrder(Node_ptr node)
			{
				if (node != nullptr && node != this->_end)
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

			Node_ptr _leftRotate(Node_ptr x)
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

			Node_ptr _rightRotate(Node_ptr y)
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

			Node_ptr _RightLeftRotate(Node_ptr node)
			{
				node->right = _rightRotate(node->right);
				return (_leftRotate(node));
			};

			Node_ptr _LeftRightRotate(Node_ptr node)
			{
				node->left = _leftRotate(node->left);
				return (_rightRotate(node));
			};


			Node_ptr	_reBalance(Node_ptr node)
			{
				int	balanceFactor = _getBalanceFactor(node);
				if (balanceFactor > 1)
				{
					if (_getBalanceFactor(node->left) >= 0)
						return (_rightRotate(node));
					else
						return (_LeftRightRotate(node));
				}
				else if (balanceFactor < -1)
				{
					if (_getBalanceFactor(node->right) <= 0)
						return (_leftRotate(node));
					else
						return (_RightLeftRotate(node));
				}
				return (node);
			};

			Node_ptr	_insert(Node_ptr temp, Node_ptr newNode)
			{
				if (temp == nullptr || temp == this->_end)
					return (newNode);
				if (!this->_comp(temp->key.first, newNode->key.first))
				{
					temp->left = _insert(temp->left, newNode);
					if (temp->left == newNode)
						newNode->parent = temp;
				}
				else if (this->_comp(temp->key.first, newNode->key.first))
				{
					temp->right = _insert(temp->right, newNode);
					if (temp->right == newNode)
						newNode->parent = temp;
				}
				else
					return (temp);
				_ReSetHeight(temp);
				temp = _reBalance(temp);
				return (temp);
			};

			Node_ptr	_remove(Node_ptr root, T key)
			{
				if (root == nullptr || root == this->_end) return (nullptr);
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
						--this->_size;
						return (temp);
					}
					else if (root->right == nullptr)
					{
						Node_ptr temp = root->left;
						this->_alloc.deallocate(root, 1);
						--this->_size;
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
				if (temp == nullptr || temp == this->_end)
					return (nullptr);

				if (temp->key.first == key.first)
					return (temp);
				else if (this->_comp(key.first, temp->key.first))
					return (_search(temp->left, key));
				else if (!this->_comp(key.first, temp->key.first))
					return (_search(temp->right, key));

				return (nullptr);
			};

			// Node_ptr _Min(Node_ptr temp)
			// {
			// 	while (temp->left != nullptr)
			// 		temp = temp->left;
			// 	return (temp);
			// };

			// Node_ptr _Max(Node_ptr temp)
			// {
			// 	while (temp->right != nullptr)
			// 		temp = temp->right;
			// 	return (temp);
			// };

			void		_ReSetHeight(Node_ptr temp)
			{
				if (!temp->left && !temp->right && temp->right == this->_end)
					temp->height = 1;
				else if (temp->left == nullptr)
					temp->height = 1 + temp->right->height;
				else if (temp->right == nullptr || temp->right == this->_end)
					temp->height = 1 + temp->left->height;
				else
					temp->height = 1 + std::max(temp->right->height, temp->left->height);
			};


		public:
			Node_ptr	insert(T key)
			{
				Node_type * newnode = this->_alloc.allocate(1);
				this->_alloc.construct(newnode, key);
				if (this->_root == this->_end)
				{
					this->_root = newnode;
					this->_root->parent = this->_end;
					this->_end->left = this->_root;
					++this->_size;
				}
				else
				{
					++this->_size;
					this->_root = _insert(this->_root, newnode);
				}
				Max()->right = this->_end;
				return (newnode);
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

				while (tmp->right && tmp->right != this->_end)
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

			// Node_ptr successor(Node_ptr node)
			// {
			// 	if (node->right != nullptr)
			// 		return (_Min(node->right));

			// 	Node_ptr temp = node->parent;
			// 	while (temp != nullptr && node == temp->right)
			// 	{
			// 		node = temp;
			// 		temp = temp->parent;
			// 	}
			// 	return (temp);
			// };
			// Node_ptr predecessor(Node_ptr node)
			// {
			// 	if (node->left != nullptr)
			// 		return (_Max(node->left));

			// 	Node_ptr temp = node->parent;
			// 	while (temp != this->_end && node == temp->left)
			// 	{
			// 		node = temp;
			// 		temp = temp->parent;
			// 	}
			// 	return (temp);
			// };

			T	get_Key() const { return (this->_root->key); };
			int	getSize() const { return (this->_size); };
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
				if (root == nullptr || root == this->_end)
					return;
				std::string prev_str = "    ";
				Trunk *trunk = new Trunk(prev, prev_str);
				// if (root->right != this->_end)
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

	template<class Node_ptr>
	Node_ptr _Min(Node_ptr temp)
	{
		while (temp->left != nullptr)
			temp = temp->left;
		return (temp);
	};
	template<class Node_ptr>
	Node_ptr _Max(Node_ptr temp)
	{
		while (temp->right != nullptr)
			temp = temp->right;
		return (temp);
	};

	template<class Node_ptr>
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

	template<class Node_ptr>
	Node_ptr predecessor(Node_ptr node)
	{
		if (node->left != nullptr)
			return (_Max(node->left));

		Node_ptr temp = node->parent;
		while (temp != node->end() && node == temp->left)
		{
			node = temp;
			temp = temp->parent;
		}
		return (temp);
	};

};


#endif
