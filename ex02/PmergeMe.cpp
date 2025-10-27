/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgomes <pgomes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
<<<<<<< HEAD
/*   Created: 2025/10/26 21:36:12 by pgomes            #+#    #+#             */
/*   Updated: 2025/10/27 09:07:00 by pgomes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "PmergeMe.hpp"

PmergeMe:: PmergeMe(){}
PmergeMe:: ~PmergeMe(){}

PmergeMe:: PmergeMe(char **argv, int &size)
{
    load_conteiner_deque(argv, size);
    load_conteiner_vector(argv, size);
}
 void PmergeMe:: load_conteiner_deque(char **argv, int & size)
 {
    std::clock_t time_start = std::clock();
    int number;

    int i = -1;
    while (++i < size - 1)
    {
         if (!isdigit(argv[i][0]) && argv[i][0] != '+')
           throw std::runtime_error("Error\nNumber invalid: " +(std::string)argv[i]);
        number = std::atoi(argv[i]);
        conteiner_deque.push_back(number);      
    }
    std::clock_t time_end = std::clock();
    time_to_load_deque =  static_cast<double>(time_end - time_start);
 }

void PmergeMe:: load_conteiner_vector(char **argv, int & size)
 {
    std::clock_t time_start = std::clock();
    int number;

    int i = -1;
    while (++i < size - 1)
    {
         if (!isdigit(argv[i][0]) && argv[i][0] != '+')
           throw std::runtime_error("Error\nNumber invalid: " +(std::string)argv[i]);
        number = std::atoi(argv[i]);
        conteiner_vector.push_back(number);      
    }
    std::clock_t time_end = std::clock();
    time_to_load_vector =  static_cast<double>(time_end - time_start);
 }

 void PmergeMe::sort_vector(void)
{
    std::clock_t time_start = std::clock();
    merge_Insertion_v(conteiner_vector);
     std::clock_t time_end = std::clock();
    time_to_vector_sort = time_to_load_vector +
    (static_cast<double>(time_end - time_start));
}

void PmergeMe::sort_deque(void)
{
    std::clock_t time_start = std::clock();  
    merge_Insertion_d(conteiner_deque);
    std::clock_t time_end = std::clock();
    time_to_deque_sort = time_to_load_deque +
    (static_cast<double>(time_end - time_start));
}

void PmergeMe:: print_sorted_list(const std::vector<int> &list)
{
    std::cout << "after : ";
    for(size_t i = 0; i < list.size(); i++)
        std::cout << list[i] << " ";
    std::cout << std::endl;
}

double PmergeMe:: getTime_to_sort_vector()
{
    return time_to_vector_sort;
}

double PmergeMe:: getTime_to_sort_deque()
{
    return time_to_deque_sort;
}
std::vector<int>PmergeMe:: getConteiner_vector(void)
{
    return (conteiner_vector);
}
void PmergeMe:: insertion_v (std::vector<int> &list, int val)
{
    std::vector<int>::iterator pos = std::lower_bound(list.begin(), list.end(), val);
    list.insert(pos, val);
    
}

void PmergeMe:: merge_Insertion_v(std::vector<int> & list)
{
    if (list.size() <= 1)
        return ;
    std::vector<int> M, S;

    for (size_t i= 0; i + 1 < list.size(); i += 2 )
    {
        int a = list[i];
        int b = list[i + 1];
        if (a > b)
            std::swap(a, b);
        S.push_back(a);
        M.push_back(b);
    }
    if (list.size() % 2 != 0 )
        M.push_back(list.back());
    merge_Insertion_v(M);
    for(size_t i = 0; i < S.size(); i++)
        insertion_v(M, S[i]);
    list = M;
}
void PmergeMe:: insertion_d (std::deque<int> &list, int val)
{
    std::deque<int>::iterator pos = std::lower_bound(list.begin(), list.end(), val);
     list.insert(pos, val);
}

void PmergeMe:: merge_Insertion_d(std::deque<int> & list)
{
    if (list.size() <= 1)
        return ;
    std::deque<int> M, S;

    for (size_t i= 0; i + 1 < list.size(); i += 2 )
    {
        int a = list[i];
        int b = list[i + 1];
        if (a > b)
            std::swap(a, b);
        S.push_back(a);
        M.push_back(b);
    }
    if (list.size() % 2 != 0 )
        M.push_back(list.back());
    merge_Insertion_d(M);
    for(size_t i = 0; i < S.size(); i++)
        insertion_d(M, S[i]);
    list = M;
}
=======
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
>>>>>>> 07f8fcf272463d5698ac3136afea03d37c32d9ee
