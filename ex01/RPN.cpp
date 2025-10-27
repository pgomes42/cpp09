/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgomes <pgomes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
<<<<<<< HEAD
/*   Created: 2025/10/26 21:59:33 by pgomes            #+#    #+#             */
/*   Updated: 2025/10/26 22:05:41 by pgomes           ###   ########.fr       */
=======
/*   Created: 2025/10/07 14:41:11 by pgomes            #+#    #+#             */
/*   Updated: 2025/10/07 14:41:33 by pgomes           ###   ########.fr       */
>>>>>>> 07f8fcf272463d5698ac3136afea03d37c32d9ee
/*                                                                            */
/* ************************************************************************** */

#include <RPN.hpp>

static bool isNumber(const std::string &s) {
    if (s.empty()) return false;
    std::size_t i = 0;
    if ((s[0] == '+' || s[0] == '-') && s.size() > 1) i = 1;
    for (; i < s.size(); ++i) {
        if (!std::isdigit(static_cast<unsigned char>(s[i]))) return false;
    }
    return true;
}

<<<<<<< HEAD
#include "RPN.hpp"

RPN::RPN(){}
RPN::~RPN(){}

RPN::RPN(const std::string& exp): expr(exp){}

int RPN::evaluateRPN() {
    std::stack<int> s;
=======
int evaluateRPN(const std::string& expr) {
    std::stack<int> st;
>>>>>>> 07f8fcf272463d5698ac3136afea03d37c32d9ee
    std::stringstream ss(expr);
    std::string token;

    while (ss >> token) {
<<<<<<< HEAD
        if (isdigit(token[0]) || (token.size() > 1 && token[0] == '-')) {
            s.push(std::atoi(token.c_str())); 
        }
        else {
            int b = s.top(); s.pop();
            int a = s.top(); s.pop();
=======
        if (isNumber(token)) {
            st.push(std::stoi(token));
        } else {
            if (st.size() < 2) throw std::runtime_error("Error: malformed expression");
            int b = st.top(); st.pop();
            int a = st.top(); st.pop();
>>>>>>> 07f8fcf272463d5698ac3136afea03d37c32d9ee

            if (token == "+") st.push(a + b);
            else if (token == "-") st.push(a - b);
            else if (token == "*") st.push(a * b);
            else if (token == "/") {
                if (b == 0) throw std::runtime_error("Error: division by zero");
                st.push(a / b);
            } else {
                throw std::runtime_error(std::string("Error: unknown operator ") + token);
            }
        }
    }

    if (st.empty()) throw std::runtime_error("Error: empty expression");
    return st.top();
}
<<<<<<< HEAD
=======

>>>>>>> 07f8fcf272463d5698ac3136afea03d37c32d9ee
