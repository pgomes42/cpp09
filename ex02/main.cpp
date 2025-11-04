/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgomes <pgomes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 21:10:09 by pgomes            #+#    #+#             */
/*   Updated: 2025/10/31 10:44:22 by pgomes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int ac, char *argv[])
{
   int i;
    if(ac == 1)
        std::cout << " Error\n invalid arguments\n";
    try
    {
       PmergeMe test(&argv[1], ac);
       i = 0;
        std::cout << "Before : ";
        while (++i < ac )
            std::cout << argv[i] << " ";
        std::cout << std::endl;
        test.sort_vector();
        test.sort_deque();
        test.print_sorted_list(test.getConteiner_vector());
    std::cout << "Time to process a reange of  " <<( ac - 1 )
    << " elements with std::vector ";
    
    std::cout << std::fixed << std::setprecision(6)
          << static_cast<double>(test.getTime_to_sort_vector()  ) << " s"  << std::endl;
    std::cout << "Time to process a reange of  " <<( ac - 1 )
    << " elements with std::deque ";
    std::cout << std::fixed << std::setprecision(6)
          << static_cast<double>(test.getTime_to_sort_deque()  ) << " s"  << std::endl;
   
    std::cout.unsetf(std::ios::floatfield);

    } 
    catch (const std::exception& e) 
    {
        std::cerr << e.what() << "\n";
    }
    
    return (0);
}