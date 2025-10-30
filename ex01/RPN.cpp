/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgomes <pgomes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 21:59:33 by pgomes            #+#    #+#             */
/*   Updated: 2025/10/30 11:55:28 by pgomes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN(){}
RPN::~RPN(){}

RPN::RPN(const std::string& exp): expr(exp){}

RPN::RPN(const RPN &other) : expr(other.expr) {}

RPN &RPN::operator=(const RPN &other)
{
    if (this != &other)
        expr = other.expr;
    return *this;
}

int RPN::evaluateRPN() {
    std::stack<int> st;
    std::stringstream ss(expr);
    std::string token;

    while (ss >> token) {

        if (isdigit(token[0]) || (token.size() > 1 && token[0] == '-')) {
            st.push(std::atoi(token.c_str())); 
        }
        else {
            int b = st.top(); st.pop();
            int a = st.top(); st.pop();


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
