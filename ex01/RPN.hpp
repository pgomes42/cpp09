/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgomes <pgomes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 21:38:16 by pgomes            #+#    #+#             */
/*   Updated: 2025/10/30 11:38:25 by pgomes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <stack>
#include <sstream>
#include <string>
#include <cstdlib>


class RPN
{
    private:
        RPN();
        std::string expr;
    public:
        RPN(const std::string & argv);
        int evaluateRPN();
        ~RPN();
};


#endif