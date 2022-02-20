/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbari <mbari@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 16:59:21 by mbari             #+#    #+#             */
/*   Updated: 2022/02/20 01:07:39 by mbari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLORS_H
#define COLORS_H

# define GREEN "\e[1;32m"
# define RESET "\e[0m"
# define RED "\e[1;91m"
# define CYAN "\e[1;36m"
# define YELLOW "\e[1;33m"
# define PURPLE "\e[1;35m"
# define BLUE "\e[1;34m"

#include "containers/vector/vector.hpp"
#include <vector>

template<typename T>
void PrintVecInfo(ft::vector<T>& ft_vec, std::vector<T>& std_vec)
{
	std::cout << std::boolalpha;
	std::cout << "ft::capacity : " << ft_vec.capacity() << std::endl;
	std::cout << "ft::size : " << ft_vec.size() << std::endl;
	std::cout << "ft::max_size : " << ft_vec.max_size() << std::endl;
	std::cout << "ft::empty : " << ft_vec.empty() << std::endl;
	std::cout << "std::capacity : " << std_vec.capacity() << std::endl;
	std::cout << "std::size : " << std_vec.size() << std::endl;
	std::cout << "std::max_size : " << std_vec.max_size() << std::endl;
	std::cout << "std::empty : " << std_vec.empty() << std::endl;
}


template<typename T>
void PrintVecData(ft::vector<T>& ft_vec, std::vector<T>& std_vec = std::vector<T>())
{
	std::cout << "ft:  ";
	for (size_t i = 0; i < ft_vec.size(); i++)
		std::cout << "|" << *(ft_vec.begin() + i) << "|" ;
	std::cout << std::endl << "std: ";
	for (size_t i = 0; i < std_vec.size(); i++)
		std::cout << "|" << *(std_vec.begin() + i) << "|" ;
	std::cout << std::endl;
	PrintVecInfo<T>(ft_vec, std_vec);
}

#endif
