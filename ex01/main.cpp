/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgomes <pgomes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 22:06:17 by pgomes            #+#    #+#             */
/*   Updated: 2025/10/30 11:37:57 by pgomes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main(int ac, char *argv[]) {
    (void)ac;
    std::string expr = argv[1];
    try {
        RPN test(expr);
        std::cout << test.evaluateRPN() << "\n";
    } catch (const std::exception& e) {
        std::cerr << e.what() << "\n";
    }
    return 0;
}