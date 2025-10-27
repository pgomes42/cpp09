/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgomes <pgomes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
<<<<<<< HEAD
/*   Created: 2025/10/26 22:06:17 by pgomes            #+#    #+#             */
/*   Updated: 2025/10/26 22:06:38 by pgomes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main(int ac, char *argv[]) {
    (void)ac;
    std::string expr = argv[1];
    try {
        RPN test(expr);
        int result = test.evaluateRPN();
=======
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
>>>>>>> 07f8fcf272463d5698ac3136afea03d37c32d9ee
        std::cout << "Expressão: " << expr << "\n";
        std::cout << "Resultado: " << result << "\n";
    } catch (const std::exception& e) {
        std::cerr << e.what() << "\n";
<<<<<<< HEAD
    }
    return (0);
}
=======
        return 1;
    }
    return 0;
}
>>>>>>> 07f8fcf272463d5698ac3136afea03d37c32d9ee
