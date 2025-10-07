/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgomes <pgomes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 14:48:16 by pgomes            #+#    #+#             */
/*   Updated: 2025/10/07 15:03:50 by pgomes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <algorithm>
#include <vector>
#include <cstdlib>
#include <ctime>

PmergeMe::PmergeMe(int argc, char **argv)
{
    load_list_from_array(argc, argv);
    _printList();
    _my_time();
    _he_time();
    _sortList();
    _printList();
}

PmergeMe::~PmergeMe() {}

void PmergeMe::load_list_from_array(int argc, char **argv) {
    for (int i = 1; i < argc; ++i) {
        std::string token(argv[i]);
        char *endptr = NULL;
        unsigned long num = std::strtoul(token.c_str(), &endptr, 10);
        if (endptr == token.c_str() || *endptr != '\0') {
            std::cerr << "Error: invalid number '" << token << "'\n";
            exit(EXIT_FAILURE);
        }
        if (num > std::numeric_limits<unsigned int>::max()) {
            std::cerr << "Error: number out of range '" << token << "'\n";
            exit(EXIT_FAILURE);
        }
        _list.push_back(static_cast<unsigned int>(num));
    }
}

void PmergeMe::_printList() {
    std::cout << "List: ";
    for (std::list<unsigned int>::const_iterator it = _list.begin(); it != _list.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

void PmergeMe::_sortList() {
    // simple wrapper: copy to vector, sort, copy back
    std::list<unsigned int> list_copy(_list.begin(), _list.end());
    list_copy.merge_sort(); // Placeholder for actual sort
    _list.assign(list_copy.begin(), list_copy.end());
}

void PmergeMe::_my_time() {
    // placeholder: print time start
    std::cout << "[my_time] start\n";
}

void PmergeMe::_he_time() {
    // placeholder: print time end
    std::cout << "[he_time] end\n";
}
