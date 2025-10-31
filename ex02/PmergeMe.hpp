/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgomes <pgomes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 20:32:40 by pgomes            #+#    #+#             */
/*   Updated: 2025/10/31 10:00:03 by pgomes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <string>
#include <iostream>
#include <vector>
#include <sstream>
#include <ctime>
#include <cstdlib>
#include <iomanip>
#include <deque>
#include <algorithm> 

class PmergeMe
{
    public:
        PmergeMe(char **argv, int &size);
        PmergeMe(const PmergeMe &other);
        PmergeMe &operator=(const PmergeMe &other);
        ~PmergeMe();
        void sort_vector(void);
        void sort_deque(void);
        void print_sorted_list(const std::vector<int> &list);
        std::vector<int> getConteiner_vector(void);
        double getTime_to_sort_vector();
        double getTime_to_sort_deque();
        void load_conteiner_deque(char **argv, int & size);
        void load_conteiner_vector(char **argv, int & size);
       
        
        
    private:
        PmergeMe();
    
    template <typename Container>
    void mergeInsertion(Container &list);
    template <typename Container>
    void insertion(Container &list, typename Container::value_type val);
        std::vector<int> conteiner_vector;
        std::deque<int> conteiner_deque;
        double time_to_load_vector;
        double time_to_load_deque;
        double time_to_vector_sort;
        double time_to_deque_sort;

};

#endif

template <typename Container>
void PmergeMe::insertion(Container &list, typename Container::value_type val)
{
    typename Container::iterator pos = std::lower_bound(list.begin(), list.end(), val);
    list.insert(pos, val);
}

template <typename Container>
void PmergeMe::mergeInsertion(Container & list)
{
    if (list.size() <= 1)
        return ;
    Container M, S;

    for (size_t i= 0; i + 1 < list.size(); i += 2 )
    {
        typename Container::value_type a = list[i];
        typename Container::value_type b = list[i + 1];
        if (a > b)
            std::swap(a, b);
        S.push_back(a);
        M.push_back(b);
    }
    if (list.size() % 2 != 0 )
        M.push_back(list.back());
    mergeInsertion(M);
    for(size_t i = 0; i < S.size(); i++)
        insertion(M, S[i]);
    list = M;
}
