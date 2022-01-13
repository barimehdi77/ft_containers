/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbari <mbari@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 18:54:40 by mbari             #+#    #+#             */
/*   Updated: 2022/01/13 18:52:12 by mbari            ###   ########.fr       */
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
//         std::cout << "/* -------------------------- testing single element Insert() -------------------------- */" << std::endl;
//         ft::vector<int> ft_vec;
//         std::vector<int> std_vec;

//         std::cout << "ft::capacity : " << ft_vec.capacity() << std::endl;
//         std::cout << "ft::size : " << std_vec.size() << std::endl;
//         std::cout << "std::capacity : " << ft_vec.capacity() << std::endl;
//         std::cout << "std::size : " << std_vec.size() << std::endl;


//         ft_vec.insert(ft_vec.begin(), 77);
//         std_vec.insert(std_vec.begin(), 77);
//         std::cout << "ft::capacity : " << ft_vec.capacity() << std::endl;
//         std::cout << "ft::size : " << std_vec.size() << std::endl;
//         std::cout << "std::capacity : " << ft_vec.capacity() << std::endl;
//         std::cout << "std::size : " << std_vec.size() << std::endl;


//         std::cout << "ft:  " << *(ft_vec.begin()) << std::endl;
//         std::cout << "std: " << *(std_vec.begin()) << std::endl;
//     }

//     {
//         std::cout << "/* -------------------------- testing fill Insert() -------------------------- */" << std::endl;
//         ft::vector<int> ft_vec;
//         std::vector<int> std_vec;
//         std::cout << "ft::capacity : " << ft_vec.capacity() << std::endl;
//         std::cout << "ft::size : " << std_vec.size() << std::endl;
//         std::cout << "std::capacity : " << ft_vec.capacity() << std::endl;
//         std::cout << "std::size : " << std_vec.size() << std::endl;

//         ft_vec.insert(ft_vec.begin(), 10, 77);
//         std_vec.insert(std_vec.begin(), 10, 77);
//         std::cout << "ft::capacity : " << ft_vec.capacity() << std::endl;
//         std::cout << "ft::size : " << std_vec.size() << std::endl;
//         std::cout << "std::capacity : " << ft_vec.capacity() << std::endl;
//         std::cout << "std::size : " << std_vec.size() << std::endl;

//         std::cout << "ft:  ";
//         for (size_t i = 0; i < 10; i++)
//             std::cout << "|" << *(ft_vec.begin() + i) << "|" ;
//         std::cout << std::endl << "std: ";
//         for (size_t i = 0; i < 10; i++)
//             std::cout << "|" << *(std_vec.begin() + i) << "|" ;
//         std::cout << std::endl;
//     }


//     {
//         std::cout << "/* -------------------------- testing range Insert() -------------------------- */" << std::endl;
//         std::vector<int> vec;
//         vec.push_back(77);
//         vec.push_back(7);
//         vec.push_back(10);
//         vec.push_back(33);
//         ft::vector<int> ft_vec;
//         std::vector<int> std_vec;
//         std::cout << "ft::capacity : " << ft_vec.capacity() << std::endl;
//         std::cout << "ft::size : " << std_vec.size() << std::endl;
//         std::cout << "std::capacity : " << ft_vec.capacity() << std::endl;
//         std::cout << "std::size : " << std_vec.size() << std::endl;

//         ft_vec.insert(ft_vec.begin(), vec.begin(), vec.end());
//         std_vec.insert(std_vec.begin(), vec.begin(), vec.end());
//         std::cout << "ft::capacity : " << ft_vec.capacity() << std::endl;
//         std::cout << "ft::size : " << std_vec.size() << std::endl;
//         std::cout << "std::capacity : " << ft_vec.capacity() << std::endl;
//         std::cout << "std::size : " << std_vec.size() << std::endl;

//         std::cout << "ft:  ";
//         for (size_t i = 0; i < ft_vec.size(); i++)
//             std::cout << "|" << *(ft_vec.begin() + i) << "|" ;
//         std::cout << std::endl << "std: ";
//         for (size_t i = 0; i < std_vec.size(); i++)
//             std::cout << "|" << *(std_vec.begin() + i) << "|" ;
//         std::cout << std::endl;
//     }
//     return 0;
// }


/* -------------------------- |Test constractors| --------------------------*/




int main()
{
    {
        typedef int         ValueType;
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
        std::cout << GREEN;
        std::cout << "/* -------------------------- testing single element insert -------------------------- */" << std::endl;
        ft_vec.insert(ft_vec.begin() + 1, 1337);
        std_vec.insert(std_vec.begin() + 1, 1337);
        PrintVecData<ValueType>(ft_vec, std_vec);
        std::cout << BLUE;
        std::cout << "/* -------------------------- testing fill insert -------------------------- */" << std::endl;
        ft_vec.insert(ft_vec.begin(), 3, 88);
        std_vec.insert(std_vec.begin(), 3, 88);
        PrintVecData<ValueType>(ft_vec, std_vec);
        std::cout << RED;
        std::cout << "/* -------------------------- testing range insert -------------------------- */" << std::endl;
        std::vector<ValueType> vec2;
        vec2.push_back(1);
        vec2.push_back(2);
        vec2.push_back(3);
        vec2.push_back(4);
        vec2.push_back(5);
        ft_vec.insert(ft_vec.begin() + 3, vec2.begin(), vec2.end());
        std_vec.insert(std_vec.begin() + 3, vec2.begin(), vec2.end());
        PrintVecData<ValueType>(ft_vec, std_vec);

        std::cout << RESET;
        // fix this
    }
    return 0;
}
