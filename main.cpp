/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbari <mbari@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 18:54:40 by mbari             #+#    #+#             */
/*   Updated: 2022/01/07 20:00:20 by mbari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <iostream>
#include <iterator>
#include "containers/iterator.hpp"
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



/* -------------------------- |strat testing my iterator| --------------------------*/


int main()
{
	int i = 10;
	ft::VecIter<int *> it(&i);
	// std::__wrap_iter<int *> itv(i);
	// std::reverse_iterator<int*> it(&i);
	// std::vector<int>::iterator it(i);
	std::cout << *it.base() << std::endl;


}
