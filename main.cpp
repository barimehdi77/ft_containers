/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbari <mbari@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 18:54:40 by mbari             #+#    #+#             */
/*   Updated: 2022/01/17 18:24:49 by mbari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <iostream>
#include <iterator>
#include "containers/iterator.hpp"
#include "colors.hpp"
#include "containers/vector.hpp"
#include <vector>

/* -------------------------- |Understand how iterators really work| --------------------------*/

// template <typename iterator>
// void	func(iterator it)
// {
// 	// typename std::iterator_traits<int *>::value_type a = 1337;
// 	typename iterator::value_type a = 1337;
// 	std::cout << a << std::endl;
// }

// int main(int ac, char **av, char **env)
// {
// 	int	tab[] = {1, 2, 3, 4};

// 	std::vector<int> vec;

// 	std::vector<int>::iterator it = vec.begin();

// 	func(it);
// }



/* -------------------------- |Test for fill insert| --------------------------*/


// int main()
// {
// 	{
// 		std::cout << "/* -------------------------- testing single element Insert() -------------------------- */" << std::endl;
// 		ft::vector<int> ft_vec;
// 		std::vector<int> std_vec;

// 		std::cout << "ft::capacity : " << ft_vec.capacity() << std::endl;
// 		std::cout << "ft::size : " << std_vec.size() << std::endl;
// 		std::cout << "std::capacity : " << ft_vec.capacity() << std::endl;
// 		std::cout << "std::size : " << std_vec.size() << std::endl;


// 		ft_vec.insert(ft_vec.begin(), 77);
// 		std_vec.insert(std_vec.begin(), 77);
// 		std::cout << "ft::capacity : " << ft_vec.capacity() << std::endl;
// 		std::cout << "ft::size : " << std_vec.size() << std::endl;
// 		std::cout << "std::capacity : " << ft_vec.capacity() << std::endl;
// 		std::cout << "std::size : " << std_vec.size() << std::endl;


// 		std::cout << "ft:  " << *(ft_vec.begin()) << std::endl;
// 		std::cout << "std: " << *(std_vec.begin()) << std::endl;
// 	}

// 	{
// 		std::cout << "/* -------------------------- testing fill Insert() -------------------------- */" << std::endl;
// 		ft::vector<int> ft_vec;
// 		std::vector<int> std_vec;
// 		std::cout << "ft::capacity : " << ft_vec.capacity() << std::endl;
// 		std::cout << "ft::size : " << std_vec.size() << std::endl;
// 		std::cout << "std::capacity : " << ft_vec.capacity() << std::endl;
// 		std::cout << "std::size : " << std_vec.size() << std::endl;

// 		ft_vec.insert(ft_vec.begin(), 10, 77);
// 		std_vec.insert(std_vec.begin(), 10, 77);
// 		std::cout << "ft::capacity : " << ft_vec.capacity() << std::endl;
// 		std::cout << "ft::size : " << std_vec.size() << std::endl;
// 		std::cout << "std::capacity : " << ft_vec.capacity() << std::endl;
// 		std::cout << "std::size : " << std_vec.size() << std::endl;

// 		std::cout << "ft:  ";
// 		for (size_t i = 0; i < 10; i++)
// 			std::cout << "|" << *(ft_vec.begin() + i) << "|" ;
// 		std::cout << std::endl << "std: ";
// 		for (size_t i = 0; i < 10; i++)
// 			std::cout << "|" << *(std_vec.begin() + i) << "|" ;
// 		std::cout << std::endl;
// 	}


// 	{
// 		std::cout << "/* -------------------------- testing range Insert() -------------------------- */" << std::endl;
// 		std::vector<int> vec;
// 		vec.push_back(77);
// 		vec.push_back(7);
// 		vec.push_back(10);
// 		vec.push_back(33);
// 		ft::vector<int> ft_vec;
// 		std::vector<int> std_vec;
// 		std::cout << "ft::capacity : " << ft_vec.capacity() << std::endl;
// 		std::cout << "ft::size : " << std_vec.size() << std::endl;
// 		std::cout << "std::capacity : " << ft_vec.capacity() << std::endl;
// 		std::cout << "std::size : " << std_vec.size() << std::endl;

// 		ft_vec.insert(ft_vec.begin(), vec.begin(), vec.end());
// 		std_vec.insert(std_vec.begin(), vec.begin(), vec.end());
// 		std::cout << "ft::capacity : " << ft_vec.capacity() << std::endl;
// 		std::cout << "ft::size : " << std_vec.size() << std::endl;
// 		std::cout << "std::capacity : " << ft_vec.capacity() << std::endl;
// 		std::cout << "std::size : " << std_vec.size() << std::endl;

// 		std::cout << "ft:  ";
// 		for (size_t i = 0; i < ft_vec.size(); i++)
// 			std::cout << "|" << *(ft_vec.begin() + i) << "|" ;
// 		std::cout << std::endl << "std: ";
// 		for (size_t i = 0; i < std_vec.size(); i++)
// 			std::cout << "|" << *(std_vec.begin() + i) << "|" ;
// 		std::cout << std::endl;
// 	}
// 	return 0;
// }


/* -------------------------- |Test inset| --------------------------*/


// int main()
// {
	// {
		// typedef int		 ValueType;
		// std::cout << YELLOW;
		// std::cout << "/* -------------------------- testing fill constractor -------------------------- */" << std::endl;
		// std::vector<int> vec;
		// vec.push_back(77);
		// vec.push_back(7);
		// vec.push_back(10);
		// vec.push_back(33);
		// vec.push_back(42);
		// ft::vector<ValueType> ft_vec(vec.begin(), vec.end());
		// std::vector<ValueType> std_vec(vec.begin(), vec.end());
		// PrintVecData<ValueType>(ft_vec, std_vec);
		// std::cout << GREEN;
		// std::cout << "/* -------------------------- testing single element insert -------------------------- */" << std::endl;
		// ft_vec.insert(ft_vec.begin() + 1, 1337);
		// std_vec.insert(std_vec.begin() + 1, 1337);
		// PrintVecData<ValueType>(ft_vec, std_vec);
		// std::cout << BLUE;
		// std::cout << "/* -------------------------- testing fill insert -------------------------- */" << std::endl;
		// ft_vec.insert(ft_vec.begin(), 3, 88);
		// std_vec.insert(std_vec.begin(), 3, 88);
		// PrintVecData<ValueType>(ft_vec, std_vec);
		// std::cout << RED;
		// std::cout << "/* -------------------------- testing range insert -------------------------- */" << std::endl;
		// std::vector<ValueType> vec2;
		// vec2.push_back(1);
		// vec2.push_back(2);
		// vec2.push_back(3);
		// vec2.push_back(4);
		// vec2.push_back(5);
		// ft_vec.insert(ft_vec.begin() + 3, vec2.begin(), vec2.end());
		// std_vec.insert(std_vec.begin() + 3, vec2.begin(), vec2.end());
		// PrintVecData<ValueType>(ft_vec, std_vec);
		// std::cout << RESET;
	// }
	// return (0);
// }


/* -------------------------- |Test resize function| --------------------------*/

// int main()
// {
// 	{
// 		typedef int		 ValueType;
// 		std::cout << YELLOW;
// 		std::cout << "/* -------------------------- testing fill constractor -------------------------- */" << std::endl;
// 		std::vector<int> vec;
// 		vec.push_back(77);
// 		vec.push_back(7);
// 		vec.push_back(10);
// 		vec.push_back(33);
// 		vec.push_back(42);
// 		ft::vector<ValueType> ft_vec(vec.begin(), vec.end());
// 		std::vector<ValueType> std_vec(vec.begin(), vec.end());
// 		PrintVecData<ValueType>(ft_vec, std_vec);
// 		std::cout << BLUE;
// 		std::cout << "/* -------------------------- testing resize -------------------------- */" << std::endl;
// 		ft_vec.resize(10);
// 		std_vec.resize(10);
// 		PrintVecData<ValueType>(ft_vec, std_vec);
// 		std::cout << RED;
// 		std::cout << "/* -------------------------- testing resize with insert -------------------------- */" << std::endl;
// 		ft_vec.insert(ft_vec.begin() + 2, 88);
// 		std_vec.insert(std_vec.begin() + 2, 88);
// 		PrintVecData<ValueType>(ft_vec, std_vec);
// 		std::cout << RESET;
// 	}
// 	return (0);
// }



/* -------------------------- |Test assign function| --------------------------*/



// int main()
// {
// 	{
// 		typedef int		 ValueType;
// 		std::cout << YELLOW;
// 		std::cout << "/* -------------------------- testing fill constractor -------------------------- */" << std::endl;
// 		std::vector<int> vec;
// 		vec.push_back(77);
// 		vec.push_back(7);
// 		vec.push_back(10);
// 		vec.push_back(33);
// 		vec.push_back(42);
// 		ft::vector<ValueType> ft_vec(vec.begin(), vec.end());
// 		std::vector<ValueType> std_vec(vec.begin(), vec.end());
// 		PrintVecData<ValueType>(ft_vec, std_vec);
// 		std::cout << BLUE;
// 		std::cout << "/* -------------------------- testing assign -------------------------- */" << std::endl;
// 		std::vector<int> vec2;
// 		vec2.push_back(200);
// 		vec2.push_back(300);
// 		vec2.push_back(400);
// 		vec2.push_back(500);
// 		vec2.push_back(600);
// 		vec2.push_back(500);
// 		vec2.push_back(600);
// 		ft_vec.assign(10, 77);
// 		std_vec.assign(10, 77);
// 		PrintVecData<ValueType>(ft_vec, std_vec);
// 		std::cout << RESET;
// 	}
// 	return (0);
// }

/* -------------------------- |Test push_back function| --------------------------*/


// int main()
// {
// 	{
// 		typedef int		 ValueType;
// 		std::cout << YELLOW;
// 		std::cout << "/* -------------------------- testing fill constractor -------------------------- */" << std::endl;
// 		std::vector<int> vec;
// 		vec.push_back(77);
// 		vec.push_back(7);
// 		vec.push_back(10);
// 		vec.push_back(33);
// 		vec.push_back(42);
// 		ft::vector<ValueType> ft_vec(vec.begin(), vec.end());
// 		std::vector<ValueType> std_vec(vec.begin(), vec.end());
// 		PrintVecData<ValueType>(ft_vec, std_vec);
// 		std::cout << BLUE;
// 		std::cout << "/* -------------------------- testing push_back -------------------------- */" << std::endl;
// 		ft_vec.push_back(99);
// 		std_vec.push_back(99);
// 		ft_vec.push_back(99);
// 		std_vec.push_back(99);
// 		ft_vec.push_back(99);
// 		std_vec.push_back(99);
// 		ft_vec.push_back(99);
// 		std_vec.push_back(99);
// 		ft_vec.push_back(99);
// 		std_vec.push_back(99);
// 		// here the capacity will be *2
// 		ft_vec.push_back(99);
// 		std_vec.push_back(99);
// 		PrintVecData<ValueType>(ft_vec, std_vec);
// 		std::cout << RESET;
// 	}
// 	return (0);
// }

/* -------------------------- |Test pop_back function| --------------------------*/


int main()
{
	{
		typedef int		 ValueType;
		std::cout << YELLOW;
		std::cout << "/* -------------------------- testing fill constractor -------------------------- */" << std::endl;
		std::vector<int> vec;
		vec.push_back(77);
		vec.push_back(7);
		vec.push_back(10);
		vec.push_back(33);
		vec.push_back(42);
		ft::vector<ValueType> ft_vec(vec.begin(), vec.end());
		std::vector<ValueType> std_vec(vec.begin(), vec.end());
		PrintVecData<ValueType>(ft_vec, std_vec);
		std::cout << BLUE;
		std::cout << "/* -------------------------- testing pop_back -------------------------- */" << std::endl;
		ft_vec.pop_back();
		std_vec.pop_back();
		PrintVecData<ValueType>(ft_vec, std_vec);
		std::cout << RED;
		std::cout << "/* -------------------------- testing deleting all content using pop_back -------------------------- */" << std::endl;
		ft_vec.pop_back();
		std_vec.pop_back();
		ft_vec.pop_back();
		std_vec.pop_back();
		ft_vec.pop_back();
		std_vec.pop_back();
		ft_vec.pop_back();
		std_vec.pop_back();
		PrintVecData<ValueType>(ft_vec, std_vec);
		std::cout << RESET;
	}
	return (0);
}

