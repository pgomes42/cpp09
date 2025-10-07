/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgomes <pgomes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 14:42:57 by pgomes            #+#    #+#             */
/*   Updated: 2025/10/07 14:59:32 by pgomes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
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