// /* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbari <mbari@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 18:54:40 by mbari             #+#    #+#             */
/*   Updated: 2022/02/14 15:48:56 by mbari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <iostream>
#include <iterator>
#include "containers/vector/vector.hpp"
#include "containers/map/map.hpp"
#include "colors.hpp"
#include <vector>
#include <map>

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
// 		std::cout << "/* -------------------------- testing pop_back -------------------------- */" << std::endl;
// 		ft_vec.pop_back();
// 		std_vec.pop_back();
// 		PrintVecData<ValueType>(ft_vec, std_vec);
// 		std::cout << RED;
// 		std::cout << "/* -------------------------- testing deleting all content using pop_back -------------------------- */" << std::endl;
// 		ft_vec.pop_back();
// 		std_vec.pop_back();
// 		ft_vec.pop_back();
// 		std_vec.pop_back();
// 		ft_vec.pop_back();
// 		std_vec.pop_back();
// 		ft_vec.pop_back();
// 		std_vec.pop_back();
// 		PrintVecData<ValueType>(ft_vec, std_vec);
// 		std::cout << RESET;
// 	}
// 	return (0);
// }


/* -------------------------- |Test erase function| --------------------------*/


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
// 		std::cout << "/* -------------------------- testing range of erase -------------------------- */" << std::endl;
// 		std::cout << "return value of erase : " << *(ft_vec.erase(ft_vec.begin() + 2)) << std::endl;
// 		std::cout << "return value of erase : " << *(std_vec.erase(std_vec.begin() + 2)) << std::endl;
// 		PrintVecData<ValueType>(ft_vec, std_vec);
// 		std::cout << RED;
// 		std::cout << "/* -------------------------- testing range of erase -------------------------- */" << std::endl;
// 		std::cout << "return value of erase : " << *(ft_vec.erase(ft_vec.begin(), ft_vec.end() - 2)) << std::endl;
// 		std::cout << "return value of erase : " << *(std_vec.erase(std_vec.begin(), std_vec.end() - 2)) << std::endl;
// 		PrintVecData<ValueType>(ft_vec, std_vec);
// 		std::cout << RESET;
// 	}
// 	return (0);
// }


/* -------------------------- |Test copy constructer function| --------------------------*/

// int main()
// {
// 	{
// 		typedef int		 ValueType;
// 		std::cout << RED;
// 		std::cout << "/* -------------------------- Printing vec and vec2 -------------------------- */" << std::endl;
// 		std::vector<ValueType> vec;
// 		vec.push_back(77);
// 		vec.push_back(7);
// 		vec.push_back(10);
// 		vec.push_back(33);
// 		vec.push_back(42);
// 		ft::vector<ValueType> vec2;
// 		vec2.push_back(77);
// 		vec2.push_back(7);
// 		vec2.push_back(10);
// 		vec2.push_back(33);
// 		vec2.push_back(42);
// 		PrintVecData<ValueType>(vec2, vec);
// 		std::cout << BLUE;
// 		std::cout << "/* -------------------------- testing copy constractor -------------------------- */" << std::endl;
// 		ft::vector<ValueType> ft_vec(vec2);
// 		std::vector<ValueType> std_vec(vec);
// 		PrintVecData<ValueType>(ft_vec, std_vec);
// 		std::cout << RESET;
// 	}
// 	return (0);
// }



/* -------------------------- |Test swap function| --------------------------*/


// int main()
// {
// 	{
// 		typedef int		 ValueType;
// 		std::cout << YELLOW;
// 		std::cout << "/* -------------------------- printing ft_vec and std_vec -------------------------- */" << std::endl;
// 		ft::vector<ValueType> ft_vec(7, 77);
// 		std::vector<ValueType> std_vec(7, 77);
// 		PrintVecData<ValueType>(ft_vec, std_vec);
// 		std::cout << BLUE;
// 		std::cout << "/* -------------------------- printing std_swap and ft_swap -------------------------- */" << std::endl;
// 		std::vector<ValueType> std_swap;
// 		std_swap.push_back(77);
// 		std_swap.push_back(7);
// 		std_swap.push_back(10);
// 		std_swap.push_back(33);
// 		std_swap.push_back(42);
// 		ft::vector<ValueType> ft_swap;
// 		ft_swap.push_back(77);
// 		ft_swap.push_back(7);
// 		ft_swap.push_back(10);
// 		ft_swap.push_back(33);
// 		ft_swap.push_back(42);
// 		PrintVecData<ValueType>(ft_swap, std_swap);
// 		std::cout << RED;
// 		std::cout << "/* -------------------------- testing swap function -------------------------- */" << std::endl;
// 		ft_vec.swap(ft_swap);
// 		std_vec.swap(std_swap);
// 		std::cout << CYAN;
// 		std::cout << "/* -------------------------- printing ft_swap and std_swap after swapping -------------------------- */" << std::endl;
// 		PrintVecData<ValueType>(ft_swap, std_swap);
// 		std::cout << PURPLE;
// 		std::cout << "/* -------------------------- printing ft_vec and std_vec after swapping -------------------------- */" << std::endl;
// 		PrintVecData<ValueType>(ft_vec, std_vec);
// 		std::cout << RESET;
// 	}
// 	return (0);
// }


/* -------------------------- |Test Element access| --------------------------*/


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
// 		std::cout << "/* -------------------------- testing operator [] -------------------------- */" << std::endl;
// 		std::cout << "printing element in index 3: " << ft_vec[3] << std::endl;
// 		std::cout << "printing element in index 3: " << std_vec[3] << std::endl;
// 		std::cout << GREEN;
// 		std::cout << "/* -------------------------- testing at() function with valid index -------------------------- */" << std::endl;
// 		try
// 		{
// 			std::cout << "printing element at index 2: " << ft_vec.at(2) << std::endl;
// 		}
// 		catch(const std::exception& e)
// 		{
// 			std::cerr << e.what() << '\n';
// 		}
// 		try
// 		{
// 			std::cout << "printing element at index 2: " << std_vec.at(2) << std::endl;
// 		}
// 		catch(const std::exception& e)
// 		{
// 			std::cerr << e.what() << '\n';
// 		}
// 		std::cout << CYAN;
// 		std::cout << "/* -------------------------- testing at() function with out of range index -------------------------- */" << std::endl;
// 		try
// 		{
// 			std::cout << "printing element at index 5: " << ft_vec.at(5) << std::endl;
// 		}
// 		catch(const std::exception& e)
// 		{
// 			std::cerr << e.what() << '\n';
// 		}
// 		try
// 		{
// 			std::cout << "printing element at index 5: " << std_vec.at(5) << std::endl;
// 		}
// 		catch(const std::exception& e)
// 		{
// 			std::cerr << e.what() << '\n';
// 		}
// 		std::cout << RED;
// 		std::cout << "/* -------------------------- testing front() -------------------------- */" << std::endl;
// 		std::cout << "printing the first element: " << ft_vec.front() << std::endl;
// 		std::cout << "printing the first element: " << std_vec.front() << std::endl;
// 		std::cout << PURPLE;
// 		std::cout << "/* -------------------------- testing Back() -------------------------- */" << std::endl;
// 		std::cout << "printing the last element: " << ft_vec.back() << std::endl;
// 		std::cout << "printing the last element: " << std_vec.back() << std::endl;
// 		std::cout << RESET;
// 	}
// 	return (0);
// }

/* -------------------------- |Test swap function| --------------------------*/

// int main()
// {
// 	{
// 		typedef int		 ValueType;
// 		std::cout << YELLOW;
// 		std::cout << "/* -------------------------- printing ft_vec and std_vec -------------------------- */" << std::endl;
// 		ft::vector<ValueType> ft_vec(7, 77);
// 		std::vector<ValueType> std_vec(7, 77);
// 		PrintVecData<ValueType>(ft_vec, std_vec);
// 		std::cout << BLUE;
// 		std::cout << "/* -------------------------- printing std_swap and ft_swap -------------------------- */" << std::endl;
// 		std::vector<ValueType> std_swap;
// 		std_swap.push_back(77);
// 		std_swap.push_back(7);
// 		std_swap.push_back(10);
// 		std_swap.push_back(33);
// 		std_swap.push_back(42);
// 		ft::vector<ValueType> ft_swap;
// 		ft_swap.push_back(77);
// 		ft_swap.push_back(7);
// 		ft_swap.push_back(10);
// 		ft_swap.push_back(33);
// 		ft_swap.push_back(42);
// 		PrintVecData<ValueType>(ft_swap, std_swap);
// 		std::cout << RED;
// 		std::cout << "/* -------------------------- testing swap function -------------------------- */" << std::endl;
// 		ft::swap(ft_vec, ft_swap);
// 		std::swap(std_vec, std_swap);
// 		std::cout << CYAN;
// 		std::cout << "/* -------------------------- printing ft_swap and std_swap after swapping -------------------------- */" << std::endl;
// 		PrintVecData<ValueType>(ft_swap, std_swap);
// 		std::cout << PURPLE;
// 		std::cout << "/* -------------------------- printing ft_vec and std_vec after swapping -------------------------- */" << std::endl;
// 		PrintVecData<ValueType>(ft_vec, std_vec);
// 		std::cout << RESET;
// 	}
// 	return (0);
// }

/* -------------------------- |Test reverse_iterator| --------------------------*/

// int main()
// {
// 	{
// 		typedef int		 ValueType;
// 		std::cout << YELLOW;
// 		std::cout << "/* -------------------------- printing ft_vec and std_vec -------------------------- */" << std::endl;
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
// 		std::cout << "/* -------------------------- printing reverse_iterator rbegin() -------------------------- */" << std::endl;
// 		std::cout << "printing last element: " << *ft_vec.rbegin() << std::endl;
// 		std::cout << "printing last element: " << *std_vec.rbegin() << std::endl;
// 		std::cout << "/* -------------------------- printing reverse_iterator rend() -------------------------- */" << std::endl;
// 		std::cout << "printing first element: " << *(ft_vec.rend() - 1) << std::endl;
// 		std::cout << "printing first element: " << *(std_vec.rend() - 1) << std::endl;
// 		std::cout << RESET;
// 	}
// 	return (0);
// }


// int main()
// {
// 	typedef	int	ValueType;
// 	{
// 		Tree<ValueType> AVL;

// 		AVL.insert(10);
// 		AVL.insert(7);
// 		AVL.insert(77);
// 		AVL.insert(8);
// 		AVL.insert(66);
// 		AVL.insert(88);
// 		AVL.insert(99);
// 		AVL.insert(33);


// 		Node<ValueType>* min = AVL.Min();
// 		std::cout << min->key << std::endl;
// 		Node<ValueType>* Max = AVL.Max();
// 		std::cout << Max->key << std::endl;
// 		Node<ValueType>* search = AVL.search(33);
// 		std::cout << search->key << std::endl;

// 		/*             find the successor of a node                         */
// 		{
// 			Node<ValueType>* succ = AVL.successor(AVL.search(10));
// 			if (succ == nullptr)
// 				std::cout << "successor of 99 is NULL " << std::endl;
// 			else
// 			std::cout << "successor of 10 is " << succ->key << std::endl;
// 		}
// 		{
// 			Node<ValueType>* succ = AVL.successor(AVL.search(8));
// 			if (succ == nullptr)
// 				std::cout << "successor of 99 is NULL " << std::endl;
// 			else
// 			std::cout << "successor of 8 is " << succ->key << std::endl;
// 		}
// 		{
// 			Node<ValueType>* succ = AVL.successor(AVL.search(99));
// 			if (succ == nullptr)
// 				std::cout << "successor of 99 is NULL " << std::endl;
// 			else
// 				std::cout << "successor of 99 is " << succ->key << std::endl;
// 		}
// 		{
// 			Node<ValueType>* succ = AVL.successor(AVL.search(7));
// 			if (succ == nullptr)
// 				std::cout << "successor of 7 is NULL " << std::endl;
// 			else
// 				std::cout << "successor of 7 is " << succ->key << std::endl;
// 		}

// 		/*             find the predecessor of a node                         */
// 		{
// 			Node<ValueType>* succ = AVL.predecessor(AVL.search(10));
// 			if (succ == nullptr)
// 				std::cout << "predecessor of 99 is NULL " << std::endl;
// 			else
// 			std::cout << "predecessor of 10 is " << succ->key << std::endl;
// 		}
// 		{
// 			Node<ValueType>* succ = AVL.predecessor(AVL.search(8));
// 			if (succ == nullptr)
// 				std::cout << "predecessor of 99 is NULL " << std::endl;
// 			else
// 			std::cout << "predecessor of 8 is " << succ->key << std::endl;
// 		}
// 		{
// 			Node<ValueType>* succ = AVL.predecessor(AVL.search(99));
// 			if (succ == nullptr)
// 				std::cout << "predecessor of 99 is NULL " << std::endl;
// 			else
// 				std::cout << "predecessor of 99 is " << succ->key << std::endl;
// 		}
// 		{
// 			Node<ValueType>* succ = AVL.predecessor(AVL.search(7));
// 			if (succ == nullptr)
// 				std::cout << "predecessor of 7 is NULL " << std::endl;
// 			else
// 				std::cout << "predecessor of 7 is " << succ->key << std::endl;
// 		}

	// 	std::cout << "┃━━━━━━━━━━━━━━━━━━━━━━━━━┃ Printing The Tree ┃━━━━━━━━━━━━━━━━━━━━━━━━┃\n\n\n\n\n" << std::endl;
	// 	AVL.print();
	// 	std::cout << "\n\n\n\n\n┃━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┃" << std::endl;

	// 	AVL.remove(77);

	// 	std::cout << "┃━━━━━━━━━━━━━━━━━━━━━━━━━┃ Printing The Tree ┃━━━━━━━━━━━━━━━━━━━━━━━━┃\n\n\n\n\n" << std::endl;
	// 	AVL.print();
	// 	std::cout << "\n\n\n\n\n┃━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┃" << std::endl;
	// }
// }


// int main()
// {
	// typedef	int	ValueType;
	// {
	// 	Tree<ValueType> AVL;

	// 	AVL.insert(1);
	// 	AVL.insert(3);
	// 	AVL.insert(2);
	// 	AVL.insert(4);
	// 	AVL.insert(6);
	// 	AVL.insert(7);
	// 	AVL.insert(10);
	// 	AVL.insert(77);
	// 	AVL.insert(8);
	// 	AVL.insert(66);
	// 	AVL.insert(88);
	// 	AVL.insert(99);
	// 	AVL.insert(33);
	// 	AVL.insert(84);
	// 	AVL.insert(30);
	// 	AVL.insert(34);
	// 	AVL.insert(9);
	// 	AVL.insert(50);
	// 	AVL.insert(31);
	// 	AVL.insert(13);
	// 	AVL.insert(70);
	// 	AVL.insert(42);


	// 	// std::cout << "┃━━━━━━━━━━━━━━━━━━━━━━━━━┃ Printing The Tree ┃━━━━━━━━━━━━━━━━━━━━━━━━┃\n\n\n\n\n" << std::endl;
	// 	// AVL.print();
	// 	// std::cout << "\n\n\n\n\n┃━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┃" << std::endl;

	// 	// AVL.remove(10);

	// 	std::cout << "┃━━━━━━━━━━━━━━━━━━━━━━━━━┃ Printing The Tree ┃━━━━━━━━━━━━━━━━━━━━━━━━┃\n\n\n\n\n" << std::endl;
	// 	AVL.print();
	// 	std::cout << "\n\n\n\n\n┃━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┃" << std::endl;
	// }
// }


// #include <utility>      // std::pair
// #include <iostream>     // std::cout

// int main ()
// {
// 	std::cout << "┃━━━━━━━━━━━━━━━━━━━━━━━━━┃ Test STD pair relational operators ┃━━━━━━━━━━━━━━━━━━━━━━━━┃" << std::endl;
// 	{
// 		std::pair<int,char> foo (10,'z');
// 		std::pair<int,char> bar (90,'a');

// 		if (foo==bar) std::cout << "{std} foo and bar are equal\n";
// 		if (foo!=bar) std::cout << "{std} foo and bar are not equal\n";
// 		if (foo< bar) std::cout << "{std} foo is less than bar\n";
// 		if (foo> bar) std::cout << "{std} foo is greater than bar\n";
// 		if (foo<=bar) std::cout << "{std} foo is less than or equal to bar\n";
// 		if (foo>=bar) std::cout << "{std} foo is greater than or equal to bar\n";
// 	}
// 	std::cout << "┃━━━━━━━━━━━━━━━━━━━━━━━━━┃ Test FT pair relational operators ┃━━━━━━━━━━━━━━━━━━━━━━━━┃" << std::endl;
// 	{
// 		ft::pair<int,char> foo (10,'z');
// 		ft::pair<int,char> bar (90,'a');

// 		if (foo==bar) std::cout << "{ft} foo and bar are equal\n";
// 		if (foo!=bar) std::cout << "{ft} foo and bar are not equal\n";
// 		if (foo< bar) std::cout << "{ft} foo is less than bar\n";
// 		if (foo> bar) std::cout << "{ft} foo is greater than bar\n";
// 		if (foo<=bar) std::cout << "{ft} foo is less than or equal to bar\n";
// 		if (foo>=bar) std::cout << "{ft} foo is greater than or equal to bar\n";
// 	}
// 	std::cout << "┃━━━━━━━━━━━━━━━━━━━━━━━━━┃ Test STD make_pair ┃━━━━━━━━━━━━━━━━━━━━━━━━┃" << std::endl;
// 	{
// 		std::pair <int,int> foo;
// 		std::pair <int,int> bar;

// 		foo = std::make_pair (10,20);
// 		bar = std::make_pair (10.5,'A'); // ok: implicit conversion from pair<double,char>

// 		std::cout << "{std} foo: " << foo.first << ", " << foo.second << '\n';
// 		std::cout << "{std} bar: " << bar.first << ", " << bar.second << '\n';

// 	}
// 	std::cout << "┃━━━━━━━━━━━━━━━━━━━━━━━━━┃ Test FT make_pair ┃━━━━━━━━━━━━━━━━━━━━━━━━┃" << std::endl;
// 	{
// 		ft::pair <int,int> foo;
// 		ft::pair <int,int> bar;

// 		foo = ft::make_pair (10,20);
// 		bar = ft::make_pair (10.5,'A'); // ok: implicit conversion from pair<double,char>

// 		std::cout << "{ft} foo: " << foo.first << ", " << foo.second << '\n';
// 		std::cout << "{ft} bar: " << bar.first << ", " << bar.second << '\n';

// 	};
// 	return 0;
// }


// int main()
// {
// 		typedef	ft::pair<int, std::string>	ValueType;
// 	{
// 		Tree<ValueType> AVL;

// 		AVL.insert(ValueType(51, "77"));
// 		AVL.insert(ValueType(77, "88"));
// 		AVL.insert(ValueType(12, "77"));
// 		AVL.insert(ValueType(7, "77"));
// 		AVL.insert(ValueType(3, "77"));
// 		AVL.insert(ValueType(15, "77"));
// 		AVL.insert(ValueType(44, "77"));
// 		AVL.insert(ValueType(99, "77"));
// 		AVL.insert(ValueType(78, "77"));
// 		AVL.insert(ValueType(55, "77"));
// 		AVL.insert(ValueType(69, "77"));
// 		AVL.insert(ValueType(45, "77"));
// 		AVL.insert(ValueType(57, "77"));
// 		AVL.insert(ValueType(10, "77"));
// 		AVL.insert(ValueType(71, "77"));
// 		AVL.insert(ValueType(96, "77"));
// 		AVL.insert(ValueType(24, "77"));
// 		AVL.insert(ValueType(11, "77"));
// 		AVL.insert(ValueType(17, "77"));
// 		AVL.insert(ValueType(19, "77"));
// 		AVL.insert(ValueType(16, "77"));
// 		AVL.insert(ValueType(35, "77"));
// 		AVL.insert(ValueType(75, "77"));


// 		// AVL.print();
// 		std::cout << "┃━━━━━━━━━━━━━━━━━━━━━━━━━┃ Printing The Tree ┃━━━━━━━━━━━━━━━━━━━━━━━━┃\n\n\n\n\n" << std::endl;
// 		std::cout << AVL.getSize() << std::endl;
// 		// {
// 		// 	Node<ValueType>* succ = AVL.successor(AVL.search(ValueType(99, "77")));
// 		// 	if (succ == nullptr)
// 		// 		std::cout << "successor of 99 is NULL " << std::endl;
// 		// 	else
// 		// 		std::cout << "successor of 99 is " << succ->key.first << std::endl;
// 		// }
// 		std::cout << "\n\n\n\n\n┃━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┃" << std::endl;

// 		// AVL.remove(ValueType(77, "77"));

// 		std::cout << "┃━━━━━━━━━━━━━━━━━━━━━━━━━┃ Printing The Tree ┃━━━━━━━━━━━━━━━━━━━━━━━━┃\n\n\n\n\n" << std::endl;
// 		AVL.print();
// 		std::cout << "\n\n\n\n\n┃━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┃" << std::endl;
// 	}
// }


/*
int main()
{
	{
		std::vector<int> foo (3,100);   // three ints with a value of 100
		std::vector<int> bar (2,200);   // two ints with a value of 200

		if (foo==bar) std::cout << "foo and bar are equal\n";
		if (foo!=bar) std::cout << "foo and bar are not equal\n";
		if (foo< bar) std::cout << "foo is less than bar\n";
		if (foo> bar) std::cout << "foo is greater than bar\n";
		if (foo<=bar) std::cout << "foo is less than or equal to bar\n";
		if (foo>=bar) std::cout << "foo is greater than or equal to bar\n";
	}
	{
		ft::vector<int> foo (3,100);   // three ints with a value of 100
		ft::vector<int> bar (2,200);   // two ints with a value of 200

		if (foo==bar) std::cout << "foo and bar are equal\n";
		if (foo!=bar) std::cout << "foo and bar are not equal\n";
		if (foo< bar) std::cout << "foo is less than bar\n";
		if (foo> bar) std::cout << "foo is greater than bar\n";
		if (foo<=bar) std::cout << "foo is less than or equal to bar\n";
		if (foo>=bar) std::cout << "foo is greater than or equal to bar\n";
	}
}
*/



// int main()
// {
// 	typedef	ft::pair<int, std::string>	ft_ValueType;
// 	typedef	std::pair<int, std::string>	std_ValueType;
// 	ft::map<int, std::string> ft;
// 	std::map<int, std::string> std;
// 	/********inserting values to ft::map*******/
// 	ft.insert(ft_ValueType(51, "77"));
// 	ft.insert(ft_ValueType(77, "88"));
// 	ft.insert(ft_ValueType(12, "77"));
// 	ft.insert(ft_ValueType(7, "77"));
// 	ft.insert(ft_ValueType(3, "77"));
// 	ft.insert(ft_ValueType(15, "77"));
// 	ft.insert(ft_ValueType(44, "77"));
// 	ft.insert(ft_ValueType(99, "77"));
// 	ft.insert(ft_ValueType(78, "77"));
// 	ft.insert(ft_ValueType(55, "77"));
// 	ft.insert(ft_ValueType(69, "77"));
// 	ft.insert(ft_ValueType(45, "77"));
// 	ft.insert(ft_ValueType(57, "77"));
// 	ft.insert(ft_ValueType(10, "77"));
// 	ft.insert(ft_ValueType(71, "77"));
// 	ft.insert(ft_ValueType(96, "77"));
// 	ft.insert(ft_ValueType(24, "77"));
// 	ft.insert(ft_ValueType(11, "77"));
// 	ft.insert(ft_ValueType(17, "77"));
// 	ft.insert(ft_ValueType(19, "77"));
// 	ft.insert(ft_ValueType(16, "77"));
// 	ft.insert(ft_ValueType(35, "77"));
// 	ft.insert(ft_ValueType(75, "77"));
// 	/********inserting values to std::map*******/
// 	std.insert(std_ValueType(51, "77"));
// 	std.insert(std_ValueType(77, "88"));
// 	std.insert(std_ValueType(12, "77"));
// 	std.insert(std_ValueType(7, "77"));
// 	std.insert(std_ValueType(3, "77"));
// 	std.insert(std_ValueType(15, "77"));
// 	std.insert(std_ValueType(44, "77"));
// 	std.insert(std_ValueType(99, "77"));
// 	std.insert(std_ValueType(78, "77"));
// 	std.insert(std_ValueType(55, "77"));
// 	std.insert(std_ValueType(69, "77"));
// 	std.insert(std_ValueType(45, "77"));
// 	std.insert(std_ValueType(57, "77"));
// 	std.insert(std_ValueType(10, "77"));
// 	std.insert(std_ValueType(71, "77"));
// 	std.insert(std_ValueType(96, "77"));
// 	std.insert(std_ValueType(24, "77"));
// 	std.insert(std_ValueType(11, "77"));
// 	std.insert(std_ValueType(17, "77"));
// 	std.insert(std_ValueType(19, "77"));
// 	std.insert(std_ValueType(16, "77"));
// 	std.insert(std_ValueType(35, "77"));
// 	std.insert(std_ValueType(75, "77"));


// 	std::cout << "\n\n\n\n\n┃━━━━━━━━━━━━━━━━━━━━━━━━━┃ Printing some values ┃━━━━━━━━━━━━━━━━━━━━━━━━┃\n\n\n\n\n" << std::endl;
// 	ft::map<int, std::string> ft_map;
// 	std::map<int, std::string> std_map;
// 	ft_map.insert(ft.begin(), ft.end());
// 	std_map.insert(std.begin(), std.end());
// 	std::cout << "ft\tfirst element in list = " << ft_map.begin()->first << std::endl;
// 	std::cout << "std\tfirst element in list = " << std_map.begin()->first << std::endl;
// 	std::cout << "\n\n\n\n\n┃━━━━━━━━━━━━━━━━━━━━━━━━━┃ Printing The Tree ┃━━━━━━━━━━━━━━━━━━━━━━━━┃\n\n\n\n\n" << std::endl;
// 	ft_map.print();
// 	// ft::map<int, std::string>::iterator ft_it = ++ft.begin();
// 	// std::map<int, std::string>::iterator std_it = ++std.begin();
// 	// // ft_it--;
// 	// // std_it--;
// 	// std::cout << "ft\tprint the current node = " << ft_it->first << std::endl;
// 	// std::cout << "std\tprint the current node = " << std_it->first << std::endl;
// 	// ft_it = ft.insert(ft_it, ft_ValueType(9, "77"));
// 	// std_it = std.insert(std_it, std_ValueType(9, "77"));
// 	// std::cout << "ft\tsucc of the current node = " << (--ft_it)->first << std::endl;
// 	// std::cout << "std\tsucc of the current node  = " << (--std_it)->first << std::endl;
// 	std::cout << "\n\n\n\n\n┃━━━━━━━━━━━━━━━━━━━━━━━━━┃ Printing The Tree ┃━━━━━━━━━━━━━━━━━━━━━━━━┃\n\n\n\n\n" << std::endl;
// 	ft.print();
// 	std::cout << "\n\n\n\n\n┃━━━━━━━━━━━━━━━━━━━━━━━━━┃ Printing The Map Info ┃━━━━━━━━━━━━━━━━━━━━━━━━┃\n\n\n\n\n" << std::endl;
// 	std::cout << "ft::\t" << ft.size() << std::endl;
// 	std::cout << "std::\t" << std.size() << std::endl;
// 	std::cout << "ft::\t" << ft.empty() << std::endl;
// 	std::cout << "std::\t" << std.empty() << std::endl;
// 	std::cout << "ft::\t" << ft.max_size() << std::endl;
// 	std::cout << "std::\t" << std.max_size() << std::endl;
// 	std::cout << "\n\n\n\n\n┃━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┃" << std::endl;
// }


int main()
{
	typedef	ft::pair<int, std::string>	ft_ValueType;
	typedef	std::pair<int, std::string>	std_ValueType;
	ft::map<int, std::string> ft;
	std::map<int, std::string> std;
	/********inserting values to ft::map*******/
	ft.insert(ft_ValueType(51, "77"));
	ft.insert(ft_ValueType(77, "88"));
	ft.insert(ft_ValueType(12, "77"));
	ft.insert(ft_ValueType(7, "77"));
	ft.insert(ft_ValueType(3, "77"));
	// ft.insert(ft_ValueType(15, "77"));
	// ft.insert(ft_ValueType(44, "77"));
	// ft.insert(ft_ValueType(99, "77"));
	// ft.insert(ft_ValueType(78, "77"));
	// ft.insert(ft_ValueType(55, "77"));
	// ft.insert(ft_ValueType(69, "77"));
	// ft.insert(ft_ValueType(45, "77"));
	// ft.insert(ft_ValueType(57, "77"));
	// ft.insert(ft_ValueType(10, "77"));
	// ft.insert(ft_ValueType(71, "77"));
	// ft.insert(ft_ValueType(96, "77"));
	// ft.insert(ft_ValueType(24, "77"));
	// ft.insert(ft_ValueType(11, "77"));
	// ft.insert(ft_ValueType(17, "77"));
	// ft.insert(ft_ValueType(19, "77"));
	// ft.insert(ft_ValueType(16, "77"));
	// ft.insert(ft_ValueType(35, "77"));
	// ft.insert(ft_ValueType(75, "77"));
	/********inserting values to std::map*******/
	std.insert(std_ValueType(51, "77"));
	std.insert(std_ValueType(77, "88"));
	std.insert(std_ValueType(12, "77"));
	// std.insert(std_ValueType(7, "77"));
	// std.insert(std_ValueType(3, "77"));
	// std.insert(std_ValueType(15, "77"));
	// std.insert(std_ValueType(44, "77"));
	// std.insert(std_ValueType(99, "77"));
	// std.insert(std_ValueType(78, "77"));
	// std.insert(std_ValueType(55, "77"));
	// std.insert(std_ValueType(69, "77"));
	// std.insert(std_ValueType(45, "77"));
	// std.insert(std_ValueType(57, "77"));
	// std.insert(std_ValueType(10, "77"));
	// std.insert(std_ValueType(71, "77"));
	// std.insert(std_ValueType(96, "77"));
	// std.insert(std_ValueType(24, "77"));
	// std.insert(std_ValueType(11, "77"));
	// std.insert(std_ValueType(17, "77"));
	// std.insert(std_ValueType(19, "77"));
	// std.insert(std_ValueType(16, "77"));
	// std.insert(std_ValueType(35, "77"));
	// std.insert(std_ValueType(75, "77"));


	std::cout << "\n\n\n\n\n┃━━━━━━━━━━━━━━━━━━━━━━━━━┃ Printing The Tree ┃━━━━━━━━━━━━━━━━━━━━━━━━┃\n\n\n\n\n" << std::endl;
	ft.print();
	std::cout << "\n\n\n\n\n┃━━━━━━━━━━━━━━━━━━━━━━━━━┃ removing some values ┃━━━━━━━━━━━━━━━━━━━━━━━━┃\n\n\n\n\n" << std::endl;
	std::cout << "ft.begin() : " << ft.begin()->first << std::endl;
	std::cout << "std.begin() : " << std.begin()->first << std::endl;
	ft.erase(ft.find(7));
	std.erase(std.find(7));
	std::cout << "ft.begin() : " << ft.begin()->first << std::endl;
	std::cout << "std.begin() : " << std.begin()->first << std::endl;
	std::cout << "\n\n\n\n\n┃━━━━━━━━━━━━━━━━━━━━━━━━━┃ Printing The Tree ┃━━━━━━━━━━━━━━━━━━━━━━━━┃\n\n\n\n\n" << std::endl;
	ft.print();
	std::cout << "\n\n\n\n\n┃━━━━━━━━━━━━━━━━━━━━━━━━━┃ Printing The Map Info ┃━━━━━━━━━━━━━━━━━━━━━━━━┃\n\n\n\n\n" << std::endl;
	std::cout << "ft::\t" << ft.size() << std::endl;
	std::cout << "std::\t" << std.size() << std::endl;
	std::cout << "ft::\t" << ft.empty() << std::endl;
	std::cout << "std::\t" << std.empty() << std::endl;
	std::cout << "ft::\t" << ft.max_size() << std::endl;
	std::cout << "std::\t" << std.max_size() << std::endl;
	std::cout << "\n\n\n\n\n┃━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┃" << std::endl;
}
