/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbari <mbari@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 12:09:44 by mbari             #+#    #+#             */
/*   Updated: 2022/01/06 16:40:59 by mbari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOR
#define ITERATOR

#include <iostream>
#include <string>

namespace ft
{
	template <	class Category,				// Category to which the iterator belongs to.
				class T,					// Type of elements pointed by the iterator.
				class Distance = ptrdiff_t, // Type to represent the difference between two iterators.
				class Pointer = T*,			// Type to represent a pointer to an element pointed by the iterator.
				class Reference = T&		// Type to represent a reference to an element pointed by the iterator.
			>
  	class iterator
	{
		typedef T			value_type;			// The type of the element the iterator can point to.
		typedef Distance	difference_type;	// Type to express the result of subtracting one iterator from another.
		typedef Pointer		pointer;			// The type of a pointer to an element the iterator can point to.
		typedef Reference	reference;			// The type of a reference to an element the iterator can point to.
		typedef Category	iterator_category;	// The iterator category. It can be one of iterator types.
	};

	template <class Iterator>
	class iterator_traits
	{
		typedef typename Iterator::difference_type difference_type;
		typedef typename Iterator::value_type value_type;
		typedef typename Iterator::pointer pointer;
		typedef typename Iterator::reference reference;
		typedef typename Iterator::iterator_category iterator_category;
	};

	template <class T>
	class iterator_traits<T*>
	{
		typedef ptrdiff_t difference_type;
		typedef T value_type;
		typedef T* pointer;
		typedef T& reference;
		typedef std::random_access_iterator_tag iterator_category;
	};
}

#endif
