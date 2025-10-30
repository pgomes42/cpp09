/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgomes <pgomes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 11:52:23 by pgomes            #+#    #+#             */
/*   Updated: 2025/10/30 11:55:28 by pgomes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP
#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <stdexcept>
#include <cstdlib>
#include <cctype>
#include <ctime>

class BitcoinExchange {
public:
    BitcoinExchange();
    BitcoinExchange(const std::string &inputPath);
    BitcoinExchange(const BitcoinExchange &other);
    BitcoinExchange &operator=(const BitcoinExchange &other);
    ~BitcoinExchange();
    
    float getExchangeRate(const std::string &date) const;
    void displayData() const;

    void loadInputFile(const std::string &inputPath);

    void processQueries() const;

    static bool isInteger(const std::string &s);

    static bool isNumber(const std::string &s);

private:
    std::map<std::string, float> exchangeRates;
    struct Query {
        std::string raw;
        std::string date;
        double value;
        int status;
    };
    std::vector<Query> queryDates;
    std::ifstream dataFile;
    std::ifstream inputFile;
    void parseLine(const std::string &line);
    void loadData();
    static bool validate_data(const std::string &dateStr);
    float getRateForDate(const std::string &date) const;
};

#endif