/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbari <mbari@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 12:09:44 by mbari             #+#    #+#             */
/*   Updated: 2022/01/06 12:12:41 by mbari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOR
#define ITERATOR


namespace ft
{
	template <class Category, class T, class Distance = ptrdiff_t,
		class Pointer = T*, class Reference = T&>
  	class iterator {
		typedef T			value_type;
		typedef Distance	difference_type;
		typedef Pointer		pointer;
		typedef Reference	reference;
		typedef Category	iterator_category;
	};
}

#endif
