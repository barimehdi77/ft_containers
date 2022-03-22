/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbari <mbari@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 12:09:44 by mbari             #+#    #+#             */
/*   Updated: 2022/03/22 23:52:30 by mbari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAPITERATOR_HPP
#define MAPITERATOR_HPP

#include <iostream>
#include <string>
#include "../reverse_iterator.hpp"
#include "tree.hpp"
#include "utils.hpp"

namespace ft
{
	template<class T, class Node_ptr>
	class TreeIter : public std::iterator<std::bidirectional_iterator_tag, T>
	{
		public:
			typedef T													iterator_type;
			typedef std::bidirectional_iterator_tag						iterator_category;
			typedef typename iterator_traits<T>::value_type				value_type;
			typedef	typename iterator_traits<T>::difference_type		difference_type;
			typedef typename iterator_traits<T>::pointer				pointer;
			typedef typename iterator_traits<T>::reference				reference;

		private:
			Node_ptr	_it;

		public:
			TreeIter(): _it(nullptr) {};
			explicit	TreeIter( Node_ptr x ): _it(x) {};
			template <class Iter>
			TreeIter ( const TreeIter<Iter, Node_ptr>& node_it ): _it(node_it.base()) {};

			Node_ptr		base() const							{ return (this->_it); };
			reference		operator*() const						{ return (this->_it->key); };
			TreeIter&		operator++()							{this->_it = successor(this->_it); return (*this); };		// pre-increment
			TreeIter		operator++(int)							{ TreeIter temp(*this); ++(*this); return (temp); };		// post-increment
			TreeIter&		operator--()							{this->_it = predecessor(this->_it); return (*this); };		// pre-decrement
			TreeIter		operator--(int)							{ TreeIter temp(*this); --(*this); return (temp); };		// post-decrement
			pointer			operator->()							{ return (&(operator*())); };
			reference		operator[]( difference_type n ) const	{ return (*(this->_it + n)); };
	};

	template <class T, class Node_ptr>
	bool operator== (const TreeIter<T, Node_ptr>& lhs, const TreeIter<T, Node_ptr>& rhs) { return (lhs.base() == rhs.base()); };
	template <class T, class Node_ptr>
	bool operator!= (const TreeIter<T, Node_ptr>& lhs, const TreeIter<T, Node_ptr>& rhs) { return (lhs.base() != rhs.base()); };
	template <class T, class Node_ptr>
	bool operator<  (const TreeIter<T, Node_ptr>& lhs, const TreeIter<T, Node_ptr>& rhs) { return (lhs.base() < rhs.base()); };
	template <class T, class Node_ptr>
	bool operator<= (const TreeIter<T, Node_ptr>& lhs, const TreeIter<T, Node_ptr>& rhs) { return (lhs.base() <= rhs.base()); };
	template <class T, class Node_ptr>
	bool operator>  (const TreeIter<T, Node_ptr>& lhs, const TreeIter<T, Node_ptr>& rhs) { return (lhs.base() > rhs.base()); };
	template <class T, class Node_ptr>
	bool operator>=  (const TreeIter<T, Node_ptr>& lhs, const TreeIter<T, Node_ptr>& rhs) { return (lhs.base() >= rhs.base()); };

};


#endif
