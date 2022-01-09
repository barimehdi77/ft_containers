/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbari <mbari@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 12:04:04 by mbari             #+#    #+#             */
/*   Updated: 2022/01/09 19:34:34 by mbari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef VECTOR_HPP
# define VECTOR_HPP

#include <string>
#include <iostream>

namespace ft
{
	template < class T, class Allocator = std::allocator<T> >
	class vector
	{
		protected:
			typedef T											value_type;
			typedef typename allocator_type::reference			reference;
			typedef typename allocator_type::const_reference	const_reference;
			typedef typename allocator_type::difference_type	difference_type;
			typedef typename allocator_type::pointer			pointer;
			typedef typename allocator_type::const_pointer		const_pointer;
			typedef type
		public:
			typedef Allocator									allocator_type;
			typedef typename allocator_type::size_type			size_type;
	};
}


# endif
