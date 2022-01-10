/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbari <mbari@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 12:09:44 by mbari             #+#    #+#             */
/*   Updated: 2022/01/10 14:30:16 by mbari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOR
#define ITERATOR

#include <iostream>
#include <string>

namespace ft
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
		typedef std::random_access_iterator_tag	iterator_category;
	};

	template <class T>
	struct iterator_traits<const T*>
	{
		typedef ptrdiff_t						difference_type;
		typedef T								value_type;
		typedef T*								pointer;
		typedef T&								reference;
		typedef std::random_access_iterator_tag	iterator_category;
	};

	template<class T>
	class VecIter : public iterator<std::random_access_iterator_tag, T>
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
			VecIter(): _it(nullptr) {};
			explicit	VecIter( iterator_type x ): _it(x) {};
			template <class Iter>
			VecIter ( const VecIter<Iter>& vec_it ): _it(vec_it.base()) {};

			iterator_type	base() const							{ return (this->_it); };
			reference		operator*() const						{ return (*this->_it); };
			VecIter			operator+( difference_type n ) const	{ return (VecIter(this->_it + n)); };
			VecIter			operator-( difference_type n ) const	{ return (VecIter(this->_it - n)); };
			VecIter&		operator++()							{++this->_it; return (*this); };					// pre-increment
			VecIter			operator++(int)							{ VecIter temp(*this); ++(*this); return (temp); }; // post-increment
			VecIter&		operator--()							{--this->_it; return (*this); };					// pre-decrement
			VecIter			operator--(int)							{ VecIter temp(*this); --(*this); return (temp); };	// post-decrement
			VecIter&		operator+=( difference_type n )			{ this->_it += n; return (*this); };
			VecIter&		operator-=( difference_type n )			{ this->_it -= n; return (*this); };
			pointer			operator->()							{ return (&(operator*())); };
			reference		operator[]( difference_type n ) const	{ return (*(this->_it + n)); };
	};


};



#endif
