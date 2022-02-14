/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbari <mbari@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 14:35:25 by mbari             #+#    #+#             */
/*   Updated: 2022/02/14 20:28:33 by mbari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #define COUNT 10
#include "../colors.hpp"
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
		// Node(): _key(0), left(nullptr), right(nullptr) {};
		Node(T key): key(key), left(nullptr), right(nullptr), parent(nullptr) , height(1) {};
		// Node (const Node& x) {*this = x; };
		// Node(T key, const Node & l, const Node & r): _key(key), left(l), right(r) {};
		~Node() {};
		// Node& operator= (const Node& x)


	// public:
	// 	T get_Key() const { return (this->_key); };
};


template <class T>
class Tree
{
	private:
		Node<T> * _Root = nullptr;



/*
	leftrotation
	node = mid->parent;
	mid->left = node;

	right rotation
	node = mid->parent;
	mid->right = node;
*/
	private:


		int		_Height(Node<T>* temp)
		{
			if (temp == nullptr)
				return (0);
			return (temp->height);
		};

		int _getBalanceFactor(Node<T>* N)
		{
			if (N == NULL)
				return 0;
			return (_Height(N->left) - _Height(N->right));
		}

		Node<T>* leftRotate(Node<T>* x)
		{
			Node<T>* y = x->right;
			Node<T>* T2 = y->left;
			Node<T>* p = x->parent;
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

		Node<T>* rightRotate(Node<T>* y)
		{
			Node<T>* x = y->left;
			Node<T>* T2 = x->right;
			Node<T>* p = y->parent;
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

		Node<T>* RightLeftRotate(Node<T>* node)
		{
			node->right = rightRotate(node->right);
			return (leftRotate(node));
		};

		Node<T>* LeftRightRotate(Node<T>* node)
		{
			node->left = leftRotate(node->left);
			return (rightRotate(node));
		};

		// void	_checkBalance(Node<T>* node)
		// {
		// 	int	balanceFactor = _getBalanceFactor(node);
		// 	if (balanceFactor > 1 || balanceFactor < -1)
		// 			_reBalance(node);
		// 	// if (node->parent == nullptr)
		// 	// 	return ;
		// 	// _checkBalance(node->parent);
		// };

		void	_reBalance(Node<T>* node)
		{
			int	balanceFactor = _getBalanceFactor(node);
			if (balanceFactor > 1)
			{
				if (_getBalanceFactor(node->left) >= 0)
					node = rightRotate(node);
				else
					node = LeftRightRotate(node);
			}
			else if (balanceFactor < -1)
			{
				if (_getBalanceFactor(node->right) <= 0)
					node = leftRotate(node);
				else
					node = RightLeftRotate(node);
			}
			if (node->parent == nullptr){
				this->_Root = node;
				node->parent = nullptr;
			}
		};

		void	_insert(Node<T>* temp, Node<T>* newNode)
		{
			if (temp->key > newNode->key)
			{
				if (temp->left == nullptr)
				{
					temp->left = newNode;
					temp->left->parent = temp;
				}
				else
					_insert(temp->left, newNode);
			}
			else
			{
				if (temp->right == nullptr)
				{
					temp->right = newNode;
					temp->right->parent = temp;
				}
				else
					_insert(temp->right, newNode);
			}
			// print();
			// _checkBalance(newNode);
			if (temp->key == 34 && newNode->key == 42)
				std::cout << "found" << std::endl;
			_ReSetHeight(temp);
			std::cout << "done inserting " << temp->key << std::endl;
			_reBalance(temp);
		};

		Node<T>*	_remove(Node<T>* root, T key)
		{
			if (root == nullptr) return (nullptr);
			else if (key < root->key)
				root->left = _remove(root->left, key);
			else if (key > root->key)
				root->right = _remove(root->right, key);
			else
			{
				if (root->left == nullptr)
				{
					Node<T>* temp = root->right;
					delete root;
					return (temp);
				}
				else if (root->right == nullptr)
				{
					Node<T>* temp = root->left;
					delete root;
					return (temp);
				}
				else
				{
					Node<T>* MaxValue = _Max(root->left);
					root->key = MaxValue->key;
					root->left = _remove(root->left, MaxValue->key);
				}
			}
			_ReSetHeight(root);
			_reBalance(root);
			return (root);
		};

		Node<T>* _search(Node<T>* temp, T key)
		{
			if (temp == nullptr)
				return (nullptr);

			if (temp->key == key)
				return (temp);
			else if (temp->key > key)
				return (_search(temp->left, key));
			else if (temp->key < key)
				return (_search(temp->right, key));

			return (nullptr);
		};

		Node<T>* _Min(Node<T>* temp)
		{
			while (temp->left != nullptr)
				temp = temp->left;
			return (temp);
		};

		Node<T>* _Max(Node<T>* temp)
		{
			while (temp->right != nullptr)
				temp = temp->right;
			return (temp);
		};

		void		_ReSetHeight(Node<T>* temp)
		{
		// 	while (temp)
		// 	{
				if (!temp->left && !temp->right)
					temp->height = 1;
				else if (temp->left == nullptr)
					temp->height = 1 + temp->right->height;
				else if (temp->right == nullptr)
					temp->height = 1 + temp->left->height;
				else
					temp->height = 1 + std::max(temp->right->height, temp->left->height);
			// 	temp = temp->parent;
			// }
		};


	public:
		void	insert(T key)
		{
			std::cout << "inserting " << key << std::endl;
			Node<T> * newnode = new Node<T>(key);
			if (!this->_Root)
				this->_Root = newnode;
			else
				_insert(this->_Root, newnode);
			// setHeight();
		};

		void	remove(T key)
		{
			this->_Root = _remove(this->_Root, key);
			// setHeight();
		}

		Node<T>*	Min()
		{
			Node<T> * tmp = this->_Root;

			while (tmp->left)
				tmp = tmp->left;
			return (tmp);
		};

		Node<T>* Max()
		{
			Node<T>* tmp = this->_Root;

			while (tmp->right)
				tmp = tmp->right;
			return (tmp);
		}

		Node<T>* search(T key)
		{
			if (this->_Root == nullptr)
				return (nullptr);
			else
				return (_search(this->_Root, key));
		}

		Node<T>* successor(Node<T>* node)
		{
			if (node->right != nullptr)
				return (_Min(node->right));

			Node<T>* temp = node->parent;
			while (temp != nullptr && node == temp->right)
			{
				node = temp;
				temp = temp->parent;
			}
			return (temp);
		}
		Node<T>* predecessor(Node<T>* node)
		{
			if (node->left != nullptr)
				return (_Max(node->left));

			Node<T>* temp = node->parent;
			while (temp != nullptr && node == temp->left)
			{
				node = temp;
				temp = temp->parent;
			}
			return (temp);
		}

		T	get_Key() const { return (this->_Root->key); };
		T	get_height() const { return (this->_Root->height); };

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
		}

		void printTree(Node<T>* root, Trunk *prev, bool isLeft)
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
			std::cout << " " RED << root->key << RESET;
			if (root->parent != nullptr)
				std::cout << " {P: " << root->parent->key << "} H: " << root->height << GREEN " FB: " << _getBalanceFactor(root) << RESET<< std::endl;
			else
				std::cout << " {P: NULL" << "} H: " << root->height  << GREEN " FB: " << _getBalanceFactor(root) << RESET << std::endl;

			if (prev) {
				prev->str = prev_str;
			}
			trunk->str = "   |";

			printTree(root->left, trunk, false);
		}

		// void printTree(Node<T>* root, std::string indent, bool last)
		// {
		// 	if (root != nullptr)
		// 	{
		// 		std::cout << indent;
		// 		if (last) {
		// 		std::cout << "R----";
		// 		indent += "   ";
		// 		} else {
		// 		std::cout << "L----";
		// 		indent += "|  ";
		// 		}
		// 		std::cout << root->key << std::endl;
		// 		printTree(root->left, indent, false);
		// 		printTree(root->right, indent, true);
		// 	}
		// }

		// void	print2DUtil(Node<T>* root, int space)
		// {
		// 	if (root == NULL)
		// 		return;
		// 	space += 10;
		// 	print2DUtil(root->right, space);
		// 	std::cout << std::endl;
		// 	for (int i = 10; i < space; i++)
		// 		std::cout << " ";
		// 	std::cout << "{" << root->key << "} " << root->height << "\n";
		// 	print2DUtil(root->left, space);
		// };



		public: /*             print function                         */
			void	print() { printTree(this->_Root, nullptr, false); };
			// void	print()
			// {
			// 	std::cout << "||||||||||||||||\n";
			// 	print2DUtil(this->_Root, 0);
			// 	std::cout << "||||||||||||||||\n\n";
			// };

};

