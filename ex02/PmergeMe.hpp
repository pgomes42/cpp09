/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgomes <pgomes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 20:32:40 by pgomes            #+#    #+#             */
/*   Updated: 2025/10/31 14:36:03 by pgomes           ###   ########.fr       */
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
#include <cctype>
#include <iomanip>
#include <deque>
#include <algorithm>
#include <sys/time.h>

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

       

    private:
        std::vector<int> conteiner_vector;
        std::deque<int> conteiner_deque;
        double time_to_load_vector;
        double time_to_load_deque;
        double time_to_vector_sort;
        double time_to_deque_sort;
    
        PmergeMe();
        void load_conteiner_deque(char **argv, int & size);
        void load_conteiner_vector(char **argv, int & size);
        template <typename Container>
            void mergeInsertion(Container &list);
        template <typename Container>
            void insertion(Container &list, typename Container::value_type val);
        template <typename Container>
            void load_conteiner_generic(Container *container, char **argv, int & size, double &time_field);
       
};

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

template <typename Container>
    void PmergeMe::load_conteiner_generic(Container *container, char **argv, int & size, double &time_field)
    {
        struct timeval tv_start, tv_end;
        gettimeofday(&tv_start, NULL);
        typename Container::value_type number;
        int i = -1;
        while (++i < size - 1)
        {
            if (!std::isdigit(static_cast<unsigned char>(argv[i][0])) && argv[i][0] != '+')
                throw std::runtime_error(std::string("Error\nNumber invalid: ") + argv[i]);
            number = static_cast<typename Container::value_type>(std::atoi(argv[i]));
            container->push_back(number);
        }
        gettimeofday(&tv_end, NULL);
        time_field = static_cast<double>(tv_end.tv_sec - tv_start.tv_sec) +
                    static_cast<double>(tv_end.tv_usec - tv_start.tv_usec) / 1e6;
    }

#endif
