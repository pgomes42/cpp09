#include "BitcoinExchange.hpp"

int main(int argc, char **argv) {
    if (argc < 2) {
        std::cerr << "Error: could not open file." << std::endl;
        return 1;
    }
    try {
        std::string inputPath = argv[1];
        BitcoinExchange be(inputPath);
        be.processQueries();
    } catch (const std::exception &e) {
        std::cerr << "Fatal error: " << e.what() << std::endl;
        return 1;
    }
    return 0;
}
