/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbari <mbari@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 19:46:30 by mbari             #+#    #+#             */
/*   Updated: 2022/02/20 08:55:28 by mbari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAPUTILS_HPP
#define MAPUTILS_HPP

// #include "vector.hpp"
namespace ft
{
	/*             pair Class                         */
	template <class T1, class T2>
	struct pair
	{
		typedef	T1 first_type;
		typedef T2 second_type;

		first_type	first;
		second_type	second;

		pair(): first(), second() {};
		template<class U, class V>
		pair (const pair<U,V>& pr): first(pr.first), second(pr.second) {};
		pair (const first_type& a, const second_type& b): first(a), second(b) {};

		pair& operator= (const pair& pr)
		{
			if (this != &pr)
			{
				this->first = pr.first;
				this->second = pr.second;
			}
			return (*this);
		};
	};

	/*             relational operators of pair                         */

	template <class T1, class T2>
	bool operator== (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs) { return (lhs.first == rhs.first && lhs.second == rhs.second); };
	template <class T1, class T2>
	bool operator!= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs) { return !(lhs == rhs); };
	template <class T1, class T2>
	bool operator<  (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs) { return lhs.first<rhs.first || (!(rhs.first<lhs.first) && lhs.second<rhs.second); };
	template <class T1, class T2>
	bool operator<= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs) { return !(rhs<lhs); };
	template <class T1, class T2>
	bool operator>  (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs) { return rhs<lhs; };
	template <class T1, class T2>
	bool operator>= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs) { return !(lhs<rhs); };

	/*             make_pair function                         */
	template <class T1,class T2>
	ft::pair<T1,T2> make_pair (T1 x, T2 y) { return (ft::pair<T1,T2>(x,y)); };

	// template<bool Cond, class T = void> struct	enable_if				{};
	// template<class T>					struct	enable_if<true, T>		{ typedef T type; };


	// template <class T>	struct	is_integral								{ static const bool value = false; };
	// template <> 		struct	is_integral<bool> 						{ static const bool value = true; };
	// template <> 		struct	is_integral<char>						{ static const bool value = true; };
	// template <> 		struct	is_integral<char16_t>					{ static const bool value = true; };
	// template <> 		struct	is_integral<char32_t>					{ static const bool value = true; };
	// template <> 		struct	is_integral<wchar_t>					{ static const bool value = true; };
	// template <> 		struct	is_integral<signed char>				{ static const bool value = true; };
	// template <> 		struct	is_integral<short int>					{ static const bool value = true; };
	// template <> 		struct	is_integral<int>						{ static const bool value = true; };
	// template <> 		struct	is_integral<long int>					{ static const bool value = true; };
	// template <> 		struct	is_integral<long long int>				{ static const bool value = true; };
	// template <> 		struct	is_integral<unsigned char>				{ static const bool value = true; };
	// template <> 		struct	is_integral<unsigned short int>			{ static const bool value = true; };
	// template <> 		struct	is_integral<unsigned int>				{ static const bool value = true; };
	// template <> 		struct	is_integral<unsigned long int>			{ static const bool value = true; };
	// template <> 		struct	is_integral<unsigned long long int>		{ static const bool value = true; };



}


#endif
