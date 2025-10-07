// simple runner for PmergeMe that forwards argv to the class
#include "PmergeMe.hpp"

int main(int argc, char **argv) {
    if (argc < 2) {
        std::cerr << "Usage: " << argv[0] << " <numbers...>\n";
        return 1;
    }
    PmergeMe pm(argc, argv);
    return 0;
}
