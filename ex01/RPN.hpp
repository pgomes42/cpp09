<<<<<<< HEAD
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgomes <pgomes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 21:38:16 by pgomes            #+#    #+#             */
/*   Updated: 2025/10/26 22:00:02 by pgomes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
#define RPN_HPP

=======
#ifndef RPN_HPP
#define RPN_HPP
#include <iostream>
>>>>>>> 07f8fcf272463d5698ac3136afea03d37c32d9ee
#include <iostream>
#include <stack>
#include <sstream>
#include <string>
<<<<<<< HEAD
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
=======
#include <cctype>
#include <stdexcept>
int evaluateRPN(const std::string& expr);
#endif // RPN_HPP
>>>>>>> 07f8fcf272463d5698ac3136afea03d37c32d9ee
