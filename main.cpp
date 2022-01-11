/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbari <mbari@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 18:54:40 by mbari             #+#    #+#             */
/*   Updated: 2022/01/11 18:05:47 by mbari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <iostream>
#include <iterator>
#include "containers/iterator.hpp"
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



/* -------------------------- |Understanding How allocator really work| --------------------------*/


int main()
{
	std::vector<int> ft_vec(1, 1337);
	// std::vector<int> std_vec(10);
ft_vec.push_back(42);
ft_vec.push_back(-42);
std::cout << "capacity : " << ft_vec.capacity() << std::endl;
std::cout << "size : " << ft_vec.size() << std::endl;


    ft_vec.insert(ft_vec.begin(), 77);
    ft_vec.insert(ft_vec.begin(), 33);
    std::vector<int>::iterator ft_it = ft_vec.begin();
    // std::vector<int>::iterator std_it = std_vec.begin();
    std::cout << ft_vec.capacity() << std::endl;
    std::cout << ft_vec.size() << std::endl;
    // ft_vec.reserve(100);
    // std::cout << ft_vec.capacity() << std::endl;
    // std::cout << ft_vec.size() << std::endl;
    std::cout << *ft_it << std::endl;
    std::cout << *(ft_it + 1) << std::endl;
    // std::cout << std_vec.size() << std::endl;

    return 0;
}
