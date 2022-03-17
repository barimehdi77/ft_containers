/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbari <mbari@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 13:33:57 by mbari             #+#    #+#             */
/*   Updated: 2022/03/17 15:39:06 by mbari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_HPP
#define STACK_HPP

#include "../vector/vector.hpp"

namespace ft
{
	template <class T, class Container = ft::vector<T> >
	class stack
	{
		public:
			typedef	T											value_type;
			typedef Container									container_type;
			typedef typename container_type::size_type			size_type;
			typedef typename container_type::reference			reference;
			typedef typename container_type::const_reference	const_reference;

		protected:
			container_type _c;

		public:
			explicit stack (const container_type& ctnr = container_type()): _c(ctnr) {};

		public:
			bool empty()			const		{ return (!this->_c.size()); };
			size_type size()		const		{ return (this->_c.size()); };
			value_type& top()					{ return (this->_c.back()); };
			const value_type& top() const		{ return (this->_c.back()); };
			void push (const value_type& val)	{ this->_c.push_back(val); };
			void pop()							{ this->_c.pop_back(); };

		protected:
			template <class _T, class _C>
				friend bool operator== (const stack<_T ,_C>& lhs, const stack<_T ,_C>& rhs);
			template <class _T, class _C>
				friend bool operator!= (const stack<_T ,_C>& lhs, const stack<_T ,_C>& rhs);
			template <class _T, class _C>
				friend bool operator<  (const stack<_T ,_C>& lhs, const stack<_T ,_C>& rhs);
			template <class _T, class _C>
				friend bool operator<= (const stack<_T ,_C>& lhs, const stack<_T ,_C>& rhs);
			template <class _T, class _C>
				friend bool operator>  (const stack<_T ,_C>& lhs, const stack<_T ,_C>& rhs);
			template <class _T, class _C>
				friend bool operator>= (const stack<_T ,_C>& lhs, const stack<_T ,_C>& rhs);
	};

	template <class _T, class _C>
		bool operator== (const stack<_T ,_C>& lhs, const stack<_T ,_C>& rhs) { return (lhs._c == rhs._c); };
	template <class _T, class _C>
		bool operator!= (const stack<_T ,_C>& lhs, const stack<_T ,_C>& rhs) { return (lhs._c != rhs._c); };
	template <class _T, class _C>
		bool operator<  (const stack<_T ,_C>& lhs, const stack<_T ,_C>& rhs) { return (lhs._c < rhs._c); };
	template <class _T, class _C>
		bool operator<= (const stack<_T ,_C>& lhs, const stack<_T ,_C>& rhs) { return (lhs._c <= rhs._c); };
	template <class _T, class _C>
		bool operator>  (const stack<_T ,_C>& lhs, const stack<_T ,_C>& rhs) { return (lhs._c > rhs._c); };
	template <class _T, class _C>
		bool operator>= (const stack<_T ,_C>& lhs, const stack<_T ,_C>& rhs) { return (lhs._c >= rhs._c); };
}


#endif
