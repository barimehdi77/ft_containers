/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbari <mbari@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 12:04:04 by mbari             #+#    #+#             */
/*   Updated: 2022/01/11 18:03:48 by mbari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef VECTOR_HPP
# define VECTOR_HPP

#include "iterator.hpp"

#include <string>
#include <iostream>

namespace ft
{
	template < class T, class Allocator = std::allocator<T> >
	class vector
	{
		public:
			typedef T											value_type;
			typedef Allocator									allocator_type;
			typedef typename allocator_type::reference			reference;
			typedef typename allocator_type::const_reference	const_reference;
			typedef typename allocator_type::difference_type	difference_type;
			typedef typename allocator_type::pointer			pointer;
			typedef typename allocator_type::const_pointer		const_pointer;
			typedef typename allocator_type::size_type			size_type;
			typedef VecIter<pointer>							iterator;
			typedef VecIter<const_pointer>						const_iterator;

		private:
			value_type*											_vec;
			// pointer												_begin;
			// pointer												_end;
			size_type											_size;
			size_type											_capacity;

		public: /*             Iterators                         */
			iterator begin() { return (iterator(this->_vec)); };
			// const_iterator begin() { return (const_iterator(this->_begin)); };
			iterator end() { return (iterator(this->begin() + this->size())); };
			// const_iterator end() { return (const_iterator(this->_begin + this->size)); };
			// NOTE: Need rbegin() and rend()

		public:
			vector(): _vec(), _size(0), _capacity(0) {};
			// explicit vector (const allocator_type& alloc = allocator_type()): _vec(alloc) _size(size_type) _capacity(_size * 2) {};
			// explicit vector (	size_type n,
			// 					const value_type& val = value_type(),
            //      				const allocator_type& alloc = allocator_type()): _vec(alloc);


		public: /*             Capacity                         */
			size_type size() const { return (this->_size); };
			size_type max_size() const { return (allocator_type().max_size()); };
			size_type capacity() const { return (this->_capacity); };
			void reserve (size_type n)
			{
				if (n > this->capacity())
				{
					this->_capacity = n;
					value_type*		temp = allocator_type().allocate(n);
					for (int i = 0; i < this->size(); i++)
						allocator_type().construct(temp + i, this->_vec[i]);
					for (int i = 0; i < this->size(); i++)
						allocator_type().destroy(this->_vec + i);
					allocator_type().deallocate(this->_vec, this->size());
					this->_vec = temp;
				}
			};
			// void resize (size_type n, value_type val = value_type())
			// {
			// 	if (n < this->_size)
			// 	{

			// 	}
			// }

		public: /*             Modifiers                         */
			iterator insert (iterator position, const value_type& val)
			{
				difference_type diff = this->end() - position;
				iterator	it;
				if (this->_size == this->_capacity)
				{
					if (this->size() == 0)
						this->reserve(1);
					else
						this->reserve(this->capacity() * 2);
					// while (it != this->end() && it != _position)
					// 	it++;
					// if (it == this->end())
					// 	*(it - 1) = val;
					// else
					// 	*it = val;
					std::cout << "diff = " << diff << std::endl;

					// iterator new_pos = this->begin() + difference_type;
					// return (it);
				}
				it = this->end();
				while (diff != 0)
				{
					*(it) = *(it - 1);
					it--;
					diff--;
				}
				*(it) = val;
				++this->_size;
				return (it);
			};


	};
}


# endif
