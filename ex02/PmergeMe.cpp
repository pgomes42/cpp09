/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgomes <pgomes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 21:36:12 by pgomes            #+#    #+#             */
/*   Updated: 2025/10/30 11:34:54 by pgomes           ###   ########.fr       */
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
