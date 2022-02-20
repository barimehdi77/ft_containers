/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbari <mbari@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 12:09:44 by mbari             #+#    #+#             */
/*   Updated: 2022/02/20 01:13:40 by mbari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAPITERATOR_HPP
#define MAPITERATOR_HPP

#include <iostream>
#include <string>

/*namespace ft
{
	template <	class Category,					// Category to which the iterator belongs to.
				class T,						// Type of elements pointed by the iterator.
				class Distance = ptrdiff_t, 	// Type to represent the difference between two iterators.
				class Pointer = T*,				// Type to represent a pointer to an element pointed by the iterator.
				class Reference = T&			// Type to represent a reference to an element pointed by the iterator.
			>
  	struct iterator
	{
		typedef T			value_type;			// The type of the element the iterator can point to.
		typedef Distance	difference_type;	// Type to express the result of subtracting one iterator from another.
		typedef T*			pointer;			// The type of a pointer to an element the iterator can point to.
		typedef Reference	reference;			// The type of a reference to an element the iterator can point to.
		typedef Category	iterator_category;	// The iterator category. It can be one of iterator types.
	};

	template <class Iterator>
	struct iterator_traits
	{
		typedef typename Iterator::difference_type		difference_type;
		typedef typename Iterator::value_type			value_type;
		typedef typename Iterator::pointer				pointer;
		typedef typename Iterator::reference			reference;
		typedef typename Iterator::iterator_category	iterator_category;
	};

	template <class T>
	struct iterator_traits<T*>
	{
		typedef ptrdiff_t						difference_type;
		typedef T								value_type;
		typedef T*								pointer;
		typedef T&								reference;
		typedef std::bidirectional_iterator_tag	iterator_category;
	};

	template <class T>
	struct iterator_traits<const T*>
	{
		typedef ptrdiff_t						difference_type;
		typedef T								value_type;
		typedef T*								pointer;
		typedef T&								reference;
		typedef std::bidirectional_iterator_tag	iterator_category;
	};
	template<class T>
	class MapIter : public iterator<std::random_access_iterator_tag, T>
	{
		public:
			typedef T													iterator_type;
			typedef typename iterator_traits<T>::iterator_category		iterator_category;
			typedef typename iterator_traits<T>::value_type				value_type;
			typedef	typename iterator_traits<T>::difference_type		difference_type;
			typedef typename iterator_traits<T>::pointer				pointer;
			typedef typename iterator_traits<T>::reference				reference;

		private:
			iterator_type	_it;

		public:
			MapIter(): _it(nullptr) {};
			explicit	MapIter( iterator_type x ): _it(x) {};
			template <class Iter>
			MapIter ( const MapIter<Iter>& vec_it ): _it(vec_it.base()) {};

			iterator_type	base() const							{ return (this->_it); };
			reference		operator*() const						{ return (*this->_it); };
			MapIter			operator+( difference_type n ) const	{ return (MapIter(this->_it + n)); };
			MapIter			operator-( difference_type n ) const	{ return (MapIter(this->_it - n)); };
			MapIter&		operator++()							{++this->_it; return (*this); };					// pre-increment
			MapIter			operator++(int)							{ MapIter temp(*this); ++(*this); return (temp); }; // post-increment
			MapIter&		operator--()							{--this->_it; return (*this); };					// pre-decrement
			MapIter			operator--(int)							{ MapIter temp(*this); --(*this); return (temp); };	// post-decrement
			MapIter&		operator+=( difference_type n )			{ this->_it += n; return (*this); };
			MapIter&		operator-=( difference_type n )			{ this->_it -= n; return (*this); };
			pointer			operator->()							{ return (&(operator*())); };
			reference		operator[]( difference_type n ) const	{ return (*(this->_it + n)); };
	};

	template <class Iterator>
	bool operator== (const MapIter<Iterator>& lhs, const MapIter<Iterator>& rhs) { return (lhs.base() == rhs.base()); };
	template <class Iterator>
	bool operator!= (const MapIter<Iterator>& lhs, const MapIter<Iterator>& rhs) { return (lhs.base() != rhs.base()); };
	template <class Iterator>
	bool operator<  (const MapIter<Iterator>& lhs, const MapIter<Iterator>& rhs) { return (lhs.base() < rhs.base()); };
	template <class Iterator>
	bool operator<= (const MapIter<Iterator>& lhs, const MapIter<Iterator>& rhs) { return (lhs.base() <= rhs.base()); };
	template <class Iterator>
	bool operator>  (const MapIter<Iterator>& lhs, const MapIter<Iterator>& rhs) { return (lhs.base() > rhs.base()); };
	template <class Iterator>
	bool operator>=  (const MapIter<Iterator>& lhs, const MapIter<Iterator>& rhs) { return (lhs.base() >= rhs.base()); };

	template <class Iterator>
	MapIter<Iterator> operator+ (typename MapIter<Iterator>::difference_type n, const MapIter<Iterator>& vec_it)
	{ return (MapIter<Iterator>( vec_it + n)); };
	template <class Iterator>
	typename MapIter<Iterator>::difference_type operator- (const MapIter<Iterator>& lhs, const MapIter<Iterator>& rhs)
	{ return (lhs.base() - rhs.base()); };

	template<class T>
	class reverse_iterator : public iterator<std::random_access_iterator_tag, T>
	{
		public:
			typedef T													iterator_type;
			typedef typename iterator_traits<T>::iterator_category		iterator_category;
			typedef typename iterator_traits<T>::value_type				value_type;
			typedef	typename iterator_traits<T>::difference_type		difference_type;
			typedef typename iterator_traits<T>::pointer				pointer;
			typedef typename iterator_traits<T>::reference				reference;

		private:
			iterator_type	_it;

		public:
			reverse_iterator(): _it(nullptr) {};
			explicit	reverse_iterator( iterator_type x ): _it(x) {};
			template <class Iter>
			reverse_iterator ( const reverse_iterator<Iter>& rev_it ): _it(rev_it.base()) {};

			iterator_type			base() const							{ return (this->_it); };
			reference				operator*() const						{ return (*this->_it); };
			reverse_iterator		operator+( difference_type n ) const	{ return (reverse_iterator(this->_it - n)); };
			reverse_iterator		operator-( difference_type n ) const	{ return (reverse_iterator(this->_it + n)); };
			reverse_iterator&		operator++()							{--this->_it; return (*this); };								// pre-increment
			reverse_iterator		operator++(int)							{ reverse_iterator temp(*this); --(*this); return (temp); };	// post-increment
			reverse_iterator&		operator--()							{++this->_it; return (*this); };								// pre-decrement
			reverse_iterator		operator--(int)							{ reverse_iterator temp(*this); ++(*this); return (temp); };	// post-decrement
			reverse_iterator&		operator+=( difference_type n )			{ this->_it -= n; return (*this); };
			reverse_iterator&		operator-=( difference_type n )			{ this->_it += n; return (*this); };
			pointer					operator->()							{ return (&(operator*())); };
			reference				operator[]( difference_type n ) const	{ return (*(this->_it + n)); };
	};

	template <class Iterator>
	bool operator== (const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs) { return (lhs.base() == rhs.base()); };
	template <class Iterator>
	bool operator!= (const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs) { return (lhs.base() != rhs.base()); };
	template <class Iterator>
	bool operator<  (const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs) { return (lhs.base() < rhs.base()); };
	template <class Iterator>
	bool operator<= (const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs) { return (lhs.base() <= rhs.base()); };
	template <class Iterator>
	bool operator>  (const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs) { return (lhs.base() > rhs.base()); };
	template <class Iterator>
	bool operator>=  (const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs) { return (lhs.base() >= rhs.base()); };



	template <class Iterator>
	reverse_iterator<Iterator> operator+ (typename reverse_iterator<Iterator>::difference_type n, const reverse_iterator<Iterator>& rev_it)
	{ return (reverse_iterator<Iterator>( rev_it - n)); };
	template <class Iterator>
	typename reverse_iterator<Iterator>::difference_type operator- (const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs)
	{ return (lhs.base() - rhs.base()); };

};


*/
#endif
