<<<<<<< HEAD
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgomes <pgomes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 21:10:09 by pgomes            #+#    #+#             */
/*   Updated: 2025/10/27 00:30:14 by pgomes           ###   ########.fr       */
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
        std::cout << static_cast<float>(test.getTime_to_sort_vector() / CLOCKS_PER_SEC) << " us"  << std::endl;
        std::cout << "Time to process a reange of  " <<( ac - 1 )
        << " elements with std::deque ";
        std::cout << static_cast<float>(test.getTime_to_sort_deque() / CLOCKS_PER_SEC) << " us"  << std::endl;

    } 
    catch (const std::exception& e) 
    {
        std::cerr << e.what() << "\n";
    }
    
    return (0);
}
=======
// simple runner for PmergeMe that forwards argv to the class
#include "PmergeMe.hpp"

int main(int argc, char **argv) {
    if (argc < 2) {
        std::cerr << "Usage: " << argv[0] << " <numbers...>\n";
        return 1;
    }
    PmergeMe pm(argc, argv);
    return 0;
}
>>>>>>> 07f8fcf272463d5698ac3136afea03d37c32d9ee
