/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgomes <pgomes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 20:32:40 by pgomes            #+#    #+#             */
/*   Updated: 2025/10/30 11:55:28 by pgomes           ###   ########.fr       */
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
        void merge_Insertion_v(std::vector<int> & list);
        void insertion_v (std::vector<int> &list, int val);
        void merge_Insertion_d(std::deque<int> & list);
        void insertion_d (std::deque<int> &list, int val);
        std::vector<int> conteiner_vector;
        std::deque<int> conteiner_deque;
        double time_to_load_vector;
        double time_to_load_deque;
        double time_to_vector_sort;
        double time_to_deque_sort;

};

#endif
