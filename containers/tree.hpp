/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbari <mbari@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 14:35:25 by mbari             #+#    #+#             */
/*   Updated: 2022/01/27 14:43:15 by mbari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

template <class T>
struct Node
{
	private:
		T _key;

	public:
		Node* left;
		Node* right;

	public:
		Node(): _key(0), left(nullptr), right(nullptr) {};
		Node(T key): _key(key), left(nullptr), right(nullptr) {};
		Node(T key, const Node & l, const Node & r): _key(key), left(l), right(r) {};
		~Node() {};


	public:
		T get_Key() const { return (this->_key()); };
};


