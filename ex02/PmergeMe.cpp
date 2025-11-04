/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgomes <pgomes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 21:36:12 by pgomes            #+#    #+#             */
/*   Updated: 2025/10/31 14:36:04 by pgomes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <unistd.h>

PmergeMe:: PmergeMe(){}
PmergeMe:: ~PmergeMe(){}

PmergeMe::PmergeMe(const PmergeMe &other)
    : conteiner_vector(other.conteiner_vector), conteiner_deque(other.conteiner_deque),
      time_to_load_vector(other.time_to_load_vector), time_to_load_deque(other.time_to_load_deque),
      time_to_vector_sort(other.time_to_vector_sort), time_to_deque_sort(other.time_to_deque_sort)
{
}

PmergeMe &PmergeMe::operator=(const PmergeMe &other)
{
    if (this != &other)
    {
        conteiner_vector = other.conteiner_vector;
        conteiner_deque = other.conteiner_deque;
        time_to_load_vector = other.time_to_load_vector;
        time_to_load_deque = other.time_to_load_deque;
        time_to_vector_sort = other.time_to_vector_sort;
        time_to_deque_sort = other.time_to_deque_sort;
        
    }
    return *this;
}

PmergeMe:: PmergeMe(char **argv, int &size)
{
    load_conteiner_deque(argv, size);
    load_conteiner_vector(argv, size);
}

void PmergeMe:: load_conteiner_deque(char **argv, int & size)
 {
    load_conteiner_generic<std::deque<int> >(&conteiner_deque, argv, size, time_to_load_deque);
}

void PmergeMe:: load_conteiner_vector(char **argv, int & size)
 {
     load_conteiner_generic<std::vector<int> >(&conteiner_vector, argv, size, time_to_load_vector);
 }

 void PmergeMe::sort_vector(void)
{
    struct timeval tv_start, tv_end;
    gettimeofday(&tv_start, NULL);
    mergeInsertion(conteiner_vector);
    gettimeofday(&tv_end, NULL);
    double dur = static_cast<double>(tv_end.tv_sec - tv_start.tv_sec) +
                 static_cast<double>(tv_end.tv_usec - tv_start.tv_usec) / 1e6;
    time_to_vector_sort = time_to_load_vector + dur;
}

void PmergeMe::sort_deque(void)
{
    struct timeval tv_start, tv_end;
    gettimeofday(&tv_start, NULL);
    mergeInsertion(conteiner_deque);
    gettimeofday(&tv_end, NULL);
    double dur = static_cast<double>(tv_end.tv_sec - tv_start.tv_sec) +
                 static_cast<double>(tv_end.tv_usec - tv_start.tv_usec) / 1e6;
    time_to_deque_sort = time_to_load_deque + dur;
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

