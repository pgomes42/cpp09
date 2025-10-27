/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgomes <pgomes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
<<<<<<< HEAD
/*   Created: 2025/10/25 20:32:40 by pgomes            #+#    #+#             */
/*   Updated: 2025/10/27 00:29:50 by pgomes           ###   ########.fr       */
=======
/*   Created: 2025/10/07 14:42:57 by pgomes            #+#    #+#             */
/*   Updated: 2025/10/07 14:59:32 by pgomes           ###   ########.fr       */
>>>>>>> 07f8fcf272463d5698ac3136afea03d37c32d9ee
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
<<<<<<< HEAD
#define PMERGERME_HPP

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
=======
#define PMERGEME_HPP   

#include <iostream>
#include <list>
#include <sstream>
#include <string>
#include <limits>


class PmergeMe
{
private:
    std::list<unsigned int> _list;
    void _sortList();
    void _printList();
    void _my_time();
    void _he_time();
    void load_list_from_array(int argc, char **argv);

public:
    PmergeMe(int argc, char **argv);
    ~PmergeMe();

};
#endif 
>>>>>>> 07f8fcf272463d5698ac3136afea03d37c32d9ee
