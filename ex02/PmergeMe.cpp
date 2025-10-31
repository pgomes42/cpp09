/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgomes <pgomes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 21:36:12 by pgomes            #+#    #+#             */
/*   Updated: 2025/10/31 10:00:19 by pgomes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "PmergeMe.hpp"

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
    mergeInsertion(conteiner_vector);
     std::clock_t time_end = std::clock();
    time_to_vector_sort = time_to_load_vector +
    (static_cast<double>(time_end - time_start));
}

void PmergeMe::sort_deque(void)
{
    std::clock_t time_start = std::clock();  
    mergeInsertion(conteiner_deque);
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

