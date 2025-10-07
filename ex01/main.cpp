/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgomes <pgomes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 14:38:57 by pgomes            #+#    #+#             */
/*   Updated: 2025/10/07 14:39:28 by pgomes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <RPN.hpp>

int main(int ac, char *argv[]) {
    if (ac < 2) {
        std::cerr << "Usage: " << argv[0] << " \"<RPN expression>\"\n";
        return 1;
    }
    std::string expr = argv[1];
    try {
        int result = evaluateRPN(expr);
        std::cout << "Expressão: " << expr << "\n";
        std::cout << "Resultado: " << result << "\n";
    } catch (const std::exception& e) {
        std::cerr << e.what() << "\n";
        return 1;
    }
    return 0;
}