/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbari <mbari@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 12:04:04 by mbari             #+#    #+#             */
/*   Updated: 2022/03/25 00:55:01 by mbari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef VECTOR_HPP
# define VECTOR_HPP

#include "iterator.hpp"
#include "utils.hpp"

#include <string>
#include <iostream>
#include <algorithm>
#include <limits>

namespace ft
{
	template < class T, class Allocator = std::allocator<T> >
	class vector
	{
		public: /*             Member types                         */
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
			typedef ft::reverse_iterator<pointer>				reverse_iterator;
			typedef ft::reverse_iterator<const_pointer>			const_reverse_iterator;

		private: /*             My vector staff                         */
			allocator_type										_alloc;
			value_type*											_vec;
			size_type											_size;
			size_type											_capacity;

		public: /*             constructers                         */
			explicit vector (const allocator_type& alloc = allocator_type()): _alloc(alloc), _vec(nullptr), _size(0), _capacity(0) {};
			explicit vector (	size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type()):
					_alloc(alloc), _size(0), _capacity(0), _vec(nullptr)
			{ assign(n, val); };
			template <class InputIterator>
			vector (InputIterator first, InputIterator last,const allocator_type& alloc = allocator_type(), typename ft::enable_if<!is_integral<InputIterator>::value, bool>::type = true):
				_alloc(alloc), _size(0), _capacity(0), _vec(nullptr)
			{ assign(first, last); };
			vector (const vector& x): _vec(nullptr), _size(0), _capacity(0) { *this = x; };

		public: /*             destructor                         */
			~vector()
			{
				if (this->_vec != nullptr)
					clear();
			};

		public: /*             operator =                         */
			vector& operator= (const vector& x)
			{
				if (this != &x)
				{
					this->_alloc = x._alloc;
					assign(x.begin(), x.end());
					this->_size = x._size;
					this->_capacity = x._capacity;
				}
				return (*this);
			};


		public: /*             Iterators                         */
			iterator				begin()				{ return (iterator(this->_vec)); };
			const_iterator			begin()		const	{ return (const_iterator(this->_vec)); };
			iterator				end()				{ return (iterator(begin() + size())); };
			const_iterator			end()		const	{ return (const_iterator(begin() + size())); };
			reverse_iterator		rbegin()			{ return(reverse_iterator((end() - 1).base())); };
			const_reverse_iterator	rbegin()	const	{ return(const_reverse_iterator((end() - 1).base())); }
			reverse_iterator		rend()				{ return(reverse_iterator((begin() - 1).base())); };
			const_reverse_iterator	rend()		const	{ return(const_reverse_iterator((begin() - 1).base())); };



		public: /*             Capacity                         */
			size_type	size()		const	{ return (this->_size); };
			size_type	max_size()	const	{ return (std::min<size_type>(std::numeric_limits<size_type>::max() / sizeof(value_type), std::numeric_limits<difference_type>::max())); };
			size_type	capacity()	const	{ return (this->_capacity); };
			bool		empty()		const	{ return (!this->_size); };
			void		reserve (size_type n)
			{
				if (n > capacity())
				{
					value_type*		temp = this->_alloc.allocate(n);
					if (this->_vec != NULL)
					{
						for (int i = 0; i < size(); i++)
						{
							this->_alloc.construct(temp + i, this->_vec[i]);
							this->_alloc.destroy(this->_vec + i);
						}
						this->_alloc.deallocate(this->_vec, capacity());
					}
					this->_capacity = n;
					this->_vec = temp;
				}
			};
			void		resize (size_type n, value_type val = value_type())
			{
				if (n != this->_size)
				{
					value_type*		temp = this->_alloc.allocate(n);
					if (n < this->_size)
					{
						for (size_t i = 0; i < n; i++)
							this->_alloc.construct(temp + i, this->_vec[i]);
						for (int i = 0; i < size(); i++)
							this->_alloc.destroy(&this->_vec[i]);
						this->_alloc.deallocate(this->_vec, capacity());
					}
					else if (n > this->_size)
					{
						for (size_t i = 0; i < this->_size; i++)
						{
							this->_alloc.construct(temp + i, this->_vec[i]);
							this->_alloc.destroy(&this->_vec[i]);
						}
						this->_alloc.deallocate(this->_vec, capacity());
						for (size_t i = this->_size; i < n; i++)
							this->_alloc.construct(temp + i, val);
					}
					this->_vec = temp;
					this->_size = this->_capacity = n;
				}
			}

		public: /*             Element access                         */
			reference operator[] (size_type n) { return (this->_vec[n]); };
			const_reference operator[] (size_type n) const { return (this->_vec[n]); };
			reference at (size_type n)
			{
				if (n >= size())
					throw std::out_of_range("vector");
				return (this->_vec[n]);
			};
			const_reference at (size_type n) const
			{
				if (n >= size())
					throw std::out_of_range("vector");
				return (this->_vec[n]);
			};
			reference front() { return (this->_vec[0]); };
			const_reference front() const { return (this->_vec[0]); };
			reference back() { return (this->_vec[this->_size - 1]); };
			const_reference back() const { return (this->_vec[this->_size - 1]); };

		public: /*             Modifiers                         */
			iterator insert (iterator position, const value_type& val)
			{
				difference_type diff = end() - position;
				if (this->_size == this->_capacity)
						reserve(capacity() + 1);
				iterator	it = end();
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
			void insert (iterator position, size_type n, const value_type& val)
			{
				difference_type diff = end() - position;
				difference_type posIndex = position - begin();
				if (size() + n > capacity())
				{
					if (size() + n > capacity() * 2)
						reserve(size() + n);
					else
						reserve(capacity() * 2);
				}
				iterator it = end() - 1;
				for (size_t i = 0; i < diff; i++)
				{
					*(it + n) = *(it);
					it--;
				}
				it = begin() + posIndex;
				for (size_t i = 0; i < n; i++)
				{
					*(it + i) = val;
				}
				this->_size += n;
			};
			template <class InputIterator>
			void insert (iterator position, InputIterator first, InputIterator last, typename ft::enable_if<!is_integral<InputIterator>::value, bool>::type = true)
			{
				difference_type	diff = end() - position;
				difference_type	len	= last - first;
				difference_type posIndex = position - begin();
				if (size() + len > capacity())
				{
					if (size() + len > capacity() * 2)
						reserve(size() + len);
					else
						reserve(capacity() * 2);
				}
				iterator it = end() - 1;
				for (size_t i = 0; i < diff; i++)
				{
					*(it + len) = *(it);
					it--;
				}
				it = begin() + posIndex;
				for (size_t i = 0; i < len; i++)
					*(it + i) = *(first++);
				this->_size += len;
			}
			template <class InputIterator>
			void assign (InputIterator first, InputIterator last, typename ft::enable_if<!is_integral<InputIterator>::value, bool>::type = true)
			{
				difference_type	len	= last - first;
				clear();
				if (len > capacity())
				{
					this->_alloc.deallocate(this->_vec, capacity());
					this->_vec = this->_alloc.allocate(len);
					this->_capacity = len;
				}
				for (size_t i = 0; i < len; i++)
					this->_alloc.construct(this->_vec + i, *(first + i));
				this->_size = len;
			}
			void assign (size_type n, const value_type& val)
			{
				clear();
				if (n > capacity())
				{
					this->_alloc.deallocate(this->_vec, capacity());
					this->_vec = this->_alloc.allocate(n);
					this->_capacity = n;
				}
				for (size_t i = 0; i < n; i++)
					this->_alloc.construct(this->_vec + i, val);
				this->_size = n;
			}
			void push_back (const value_type& val)
			{
				if (this->_size == this->_capacity)
					reserve(capacity() * 2);
				if (this->_vec == NULL)
					reserve(1);
				this->_alloc.construct(this->_vec + this->_size, val);
				++this->_size;
			}
			iterator erase (iterator position)
			{
				iterator it = position;
				this->_alloc.destroy(it.base());
				while (it != end() - 1)
				{
					*(it) = *(it + 1);
					it++;
				}
				this->_size--;
				return (position);
			}
			iterator erase (iterator first, iterator last)
			{
				iterator		it = first;
				difference_type	len = last - first;
				for (size_t i = 0; i < len; i++)
					this->_alloc.destroy((first + i).base());
				while (it != end())
				{
					*(it) = *(it + len);
					it++;
				}
				this->_size -= len;
				return (first);
			}
			void pop_back()
			{
				this->_alloc.destroy(this->_vec + this->_size);
				--this->_size;
			};
			void clear()
			{
				for (size_t i = 0; i < this->_size; i++)
					this->_alloc.destroy(&this->_vec[i]);
				this->_size = 0;
			};
			void swap (vector& x)
			{
				std::swap(x._size, this->_size);
				std::swap(x._capacity, this->_capacity);
				std::swap(x._alloc, this->_alloc);
				std::swap(x._vec, this->_vec);
			};


			public: /*             Allocator                         */
				allocator_type get_allocator() const { return (this->_alloc); };

			private: /*             for Debugging                         */
				void _PrintVecData(int n)
				{
					std::cout << "ft:  ";
					for (size_t i = 0; i < size() + n; i++)
						std::cout << "|" << *(begin() + i) << "|" ;
					std::cout << std::endl;
				};
	};

	/*             swap                         */
	template <class T, class Alloc>
	void swap (vector<T,Alloc>& x, vector<T,Alloc>& y)
	{
		x.swap(y);
	};

	/*             relational operators                         */

	template <class T, class Alloc>
	bool operator== (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) { return ((lhs.size() == rhs.size()) && ft::equal(lhs.begin(), lhs.end(), rhs.begin()));};
	template <class T, class Alloc>
	bool operator!= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) { return (!(lhs == rhs));};
	template <class T, class Alloc>
	bool operator<  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) { return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));};
	template <class T, class Alloc>
	bool operator<= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) { return (!(rhs < lhs));};
	template <class T, class Alloc>
	bool operator>  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) { return (ft::lexicographical_compare(rhs.begin(), rhs.end(), lhs.begin(), lhs.end()));};
	template <class T, class Alloc>
	bool operator>= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) { return (!(lhs < rhs));};

};

# endif
