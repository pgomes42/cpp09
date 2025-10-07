#include <iostream>
#include <stack>
#include <sstream>
#include <string>


int evaluateRPN(const std::string& expr) {
    std::stack<int> s;
    std::stringstream ss(expr);
    std::string token;

    while (ss >> token) {
        // Se for número → empilha
        if (isdigit(token[0]) || (token.size() > 1 && token[0] == '-')) {
            s.push(std::strtol(token.c_str());
            
            
        }
        // Se for operador → aplica operação
        else {
            int b = s.top(); s.pop();
            int a = s.top(); s.pop();

            if (token == "+") s.push(a + b);
            else if (token == "-") s.push(a - b);
            else if (token == "*") s.push(a * b);
            else if (token == "/") s.push(a / b);
            else {
                throw std::runtime_error("Error" + token);
            }
        }
    }

    return s.top();
}

int main(int ac, char *argv[]) {
    std::string expr = argv[1];
    try {
        int result = evaluateRPN(expr);
        std::cout << "Expressão: " << expr << "\n";
        std::cout << "Resultado: " << result << "\n";
    } catch (const std::exception& e) {
        std::cerr << e.what() << "\n";
    }
    return 0;
}
