/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgomes <pgomes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 11:52:17 by pgomes            #+#    #+#             */
/*   Updated: 2025/10/07 11:52:18 by pgomes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <cstring>
#include <cerrno>
#include <climits>

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const std::string &inputPath) {
    dataFile.open("data.csv");
    if (!dataFile.is_open())
        throw std::runtime_error(std::string("Could not open data file: data.csv\n"));
    loadData();
    loadInputFile(inputPath);
}
BitcoinExchange::~BitcoinExchange() {}

void BitcoinExchange::loadData() {
    std::string line;
   while (std::getline(dataFile, line))
   {
       if (line.find("date") != std::string::npos && line.find("exchange_rate") != std::string::npos)
           continue;
       else
           parseLine(line);
   }
    dataFile.close();
}

void BitcoinExchange::parseLine(const std::string &line) {
    std::istringstream ss(line);
    std::string date;
    std::string rateStr;
    if (std::getline(ss, date, ',') && std::getline(ss, rateStr)) {
        if (validate_data(date) && isNumber(rateStr)) {
            float rate = std::atof(rateStr.c_str());
            exchangeRates[date] = rate;
        } else {
            std::cerr << "Invalid data line: " << line << '\n';
        }
    } else {
        std::cerr << "Malformed line: " << line << '\n';
    }
}
float BitcoinExchange::getExchangeRate(const std::string &date) const {
    std::map<std::string, float>::const_iterator it = exchangeRates.find(date);
    if (it == exchangeRates.end())
        throw std::out_of_range("Date not found");
    return it->second;
}

void BitcoinExchange::displayData() const {
    for (std::map<std::string, float>::const_iterator it = exchangeRates.begin(); it != exchangeRates.end(); ++it) {
        std::cout << it->first << " => " <<  it->second << '\n';
    }
}

bool BitcoinExchange::validate_data(const std::string &dateStr) {
    if (dateStr.size() != 10)
        return false;
    for (size_t i = 0; i < dateStr.size(); ++i) {
        if (i == 4 || i == 7) {
            if (dateStr[i] != '-') return false;
        } else if (!std::isdigit(static_cast<unsigned char>(dateStr[i]))) {
            return false;
        }
    }

    int year = std::atoi(dateStr.substr(0,4).c_str());
    int month = std::atoi(dateStr.substr(5,2).c_str());
    int day = std::atoi(dateStr.substr(8,2).c_str());

    if (month < 1 || month > 12) return false;
    static const int mdays[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    int maxday = mdays[month - 1];
    if (month == 2) {
        bool leap = (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0));
        if (leap) maxday = 29;
    }
    if (day < 1 || day > maxday) return false;
    return true;
}

bool BitcoinExchange::isInteger(const std::string &s) {
    if (s.empty()) return false;
    size_t i = 0;
    if (s[0] == '+' || s[0] == '-') i = 1;
    for (; i < s.size(); ++i) if (!std::isdigit(static_cast<unsigned char>(s[i]))) return false;
    return true;
}

bool BitcoinExchange::isNumber(const std::string &s) {
    if (s.empty()) return false;
    std::istringstream iss(s);
    double v;
    char c;
    if (!(iss >> v)) return false;
    if (iss >> c) return false;
    return true;
}

void BitcoinExchange::loadInputFile(const std::string &inputPath) {
    inputFile.close();
    inputFile.open(inputPath.c_str());
    if (!inputFile.is_open())
        throw std::runtime_error("Could not open input file: " + inputPath);

    std::string line;
    if (std::getline(inputFile, line)) {
    }
    while (std::getline(inputFile, line)) {
        Query q;
        q.raw = line;
        q.date = "";
        q.value = 0.0;
        q.status = 0;
        std::string date;
        std::string valStr;
        size_t sep = line.find('|');
        if (sep != std::string::npos) {
            date = line.substr(0, sep);
            valStr = line.substr(sep + 1);
        } else {
            std::istringstream ss(line);
            if (!std::getline(ss, date, ',') || !std::getline(ss, valStr)) {
                q.status = 1;
                q.raw = line;
                queryDates.push_back(q);
                continue;
            }
        }
    const std::string spaces = " \t\n\r";
    size_t start = date.find_first_not_of(spaces);
    size_t end = date.find_last_not_of(spaces);
    if (start == std::string::npos) date = std::string();
    else date = date.substr(start, end - start + 1);
    size_t start2 = valStr.find_first_not_of(spaces);
    size_t end2 = valStr.find_last_not_of(spaces);
    if (start2 == std::string::npos) valStr = std::string();
    else valStr = valStr.substr(start2, end2 - start2 + 1);

        if (!validate_data(date) || !isNumber(valStr)) {
            q.status = 1;
            q.raw = line;
            queryDates.push_back(q);
            continue;
        }
        double value = static_cast<double>(std::atof(valStr.c_str()));
        q.date = date;
        q.value = value;
        if (value > static_cast<double>(INT_MAX) || value < static_cast<double>(INT_MIN)) {
            q.status = 3;
        } else if (value < 0.0) {
            q.status = 2;
        } else if (value == 0.0) {
        }
        queryDates.push_back(q);
    }
}

float BitcoinExchange::getRateForDate(const std::string &date) const {
    std::map<std::string, float>::const_iterator it = exchangeRates.find(date);
    if (it != exchangeRates.end()) return it->second;
    std::map<std::string, float>::const_iterator lb = exchangeRates.lower_bound(date);
    if (lb == exchangeRates.begin()) {
        throw std::out_of_range("No earlier rate available for date: " + date);
    }
    --lb;
    return lb->second;
}

void BitcoinExchange::processQueries() const {
    for (std::vector<Query>::const_iterator it = queryDates.begin(); it != queryDates.end(); ++it) {
        const Query &q = *it;
        if (q.status == 1) {
            std::cerr << "Error: bad input => " << q.raw << '\n';
            continue;
        }
        if (q.status == 3) {
            std::cerr << "Error: too large a number." << '\n';
            continue;
        }
        if (q.status == 2) {
            std::cerr << "Error: not a positive number." << '\n';
            continue;
        }
        try {
            float rate = getRateForDate(q.date);
            std::cout << q.date << " => " << q.value << " = " << (q.value * static_cast<double>(rate)) << '\n';
        } catch (const std::exception &e) {
            std::cerr << "Error: " << e.what() << '\n';
        }
    }
}
