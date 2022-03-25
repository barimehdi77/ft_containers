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
#include "containers/stack/stack.hpp"
#include "containers/vector/vector.hpp"
#include "containers/map/map.hpp"
#include "colors.hpp"
#include <stack>
#include <vector>
#include <map>

#define LIB ft

int main(int ac, char** av)
{
	if (ac != 3)
	{
		std::cerr << "Please enter how many insert" << std::endl;
		std::cerr << "Or Provide a seed please" << std::endl;
		return 1;
	}
	const int seed = atoi(av[1]);
	const int size = atoi(av[2]);
	srand(seed);

	LIB::map<int, int> map_int;

	for (int i = 0; i < size; i++)
	{
		int access = rand();
		map_int[access];
	}

}






