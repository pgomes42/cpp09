/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgomes <pgomes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 14:41:11 by pgomes            #+#    #+#             */
/*   Updated: 2025/10/07 14:41:33 by pgomes           ###   ########.fr       */
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

int evaluateRPN(const std::string& expr) {
    std::stack<int> st;
    std::stringstream ss(expr);
    std::string token;

    while (ss >> token) {
        if (isNumber(token)) {
            st.push(std::stoi(token));
        } else {
            if (st.size() < 2) throw std::runtime_error("Error: malformed expression");
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

