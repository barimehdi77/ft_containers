/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbari <mbari@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 14:35:25 by mbari             #+#    #+#             */
/*   Updated: 2022/02/12 22:38:48 by mbari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #define COUNT 10
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
		Node(T key): key(key), left(nullptr), right(nullptr), parent(nullptr) , height(0) {};
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



	private:
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
					this->_insert(temp->left, newNode);
			}
			else
			{
				if (temp->right == nullptr)
				{
					temp->right = newNode;
					temp->right->parent = temp;
				}
				else
					this->_insert(temp->right, newNode);
			}
		};

		Node<T>*	_remove(Node<T>* root, T key)
		{
			if (root == nullptr) return (nullptr);
			else if (key < root->key)
				root->left = this->_remove(root->left, key);
			else if (key > root->key)
				root->right = this->_remove(root->right, key);
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
					Node<T>* MaxValue = this->_Max(root->left);
					root->key = MaxValue->key;
					root->left = this->_remove(root->left, MaxValue->key);
				}
			}
			return (root);
		};

		Node<T>* _search(Node<T>* temp, T key)
		{
			if (temp == nullptr)
				return (nullptr);

			if (temp->key == key)
				return (temp);
			else if (temp->key > key)
				return (this->_search(temp->left, key));
			else if (temp->key < key)
				return (this->_search(temp->right, key));

			return (nullptr);
		}
		Node<T>* _Min(Node<T>* temp)
		{
			while (temp->left != nullptr)
				temp = temp->left;
			return (temp);
		}
		Node<T>* _Max(Node<T>* temp)
		{
			while (temp->right != nullptr)
				temp = temp->right;
			return (temp);
		}

		int		setSubTreeHeight(Node<T>* temp)
		{
			if (temp == nullptr)
				return -1;

			if (temp->left)
				temp->left->height = this->setSubTreeHeight(temp->left);
			if(temp->right)
				temp->right->height = this->setSubTreeHeight(temp->right);

			if (temp->left == nullptr && temp->right == nullptr)
				return (1);

			if (temp->left == nullptr)
				return (1 + temp->right->height);
			else if (temp->right == nullptr)
				return (1 + temp->left->height);
			else
				return (1 + std::max(temp->right->height, temp->left->height));
		}

		void	setHeight()
		{
			this->_Root->height = setSubTreeHeight(this->_Root);
		}


	public:
		void	insert(T key)
		{
			Node<T> * newnode = new Node<T>(key);
			if (!this->_Root)
				this->_Root = newnode;
			else
				this->_insert(this->_Root, newnode);
			this->setHeight();
		};

		void	remove(T key)
		{
			this->_Root = this->_remove(this->_Root, key);
			this->setHeight();
		}

		Node<T>*	Min()
		{
			Node<T> * tmp = this->_Root;

			while (tmp->left)
				tmp = tmp->left;
			return (tmp);
		}

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
				return (this->_search(this->_Root, key));
		}

		Node<T>* successor(Node<T>* node)
		{
			if (node->right != nullptr)
				return (this->_Min(node->right));

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
				return (this->_Max(node->left));

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
				trunk->str = "═══";
			}
			else if (isLeft)
			{
				trunk->str = "╔═══";
				prev_str = "   ║";
			}
			else {
				trunk->str = "╚═══";
				prev->str = prev_str;
			}

			showTrunks(trunk);
			std::cout << " " << root->key;
			if (root->parent != nullptr)
				std::cout << " {P: " << root->parent->key << "} H: " << root->height << std::endl;
			else
				std::cout << " {P: NULL" << "} H: " << root->height << std::endl;

			if (prev) {
				prev->str = prev_str;
			}
			trunk->str = "   ║";

			printTree(root->left, trunk, false);
		}



		public: /*             print function                         */
			void	print() { printTree(this->_Root, nullptr, false); };

};

