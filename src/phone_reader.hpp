#pragma once

#include <string>
#include <map>
#include <vector>

class PhoneNumberReader {
private:
    static const std::map<char, std::string> numberWords;
    static const std::vector<std::string> multipliers;
    
    static std::string getNumberWord(char digit);
    static std::string getMultiplier(int count);
    static std::string processSegment(const std::string& segment);

public:
    static std::string formatNumber(const std::string& phoneNumber, const std::vector<int>& format);
    static bool validatePhoneNumber(const std::string& phoneNumber);
    static bool validateFormat(const std::vector<int>& format, size_t numberLength);
};

inline const std::map<char, std::string> PhoneNumberReader::numberWords = {
    {'0', "zero "}, {'1', "one "}, {'2', "two "}, {'3', "three "},
    {'4', "four "}, {'5', "five "}, {'6', "six "}, {'7', "seven "},
    {'8', "eight "}, {'9', "nine "}
};

inline const std::vector<std::string> PhoneNumberReader::multipliers = {
    "double ", "triple ", "quadruple ", "quintuple ", "sextuple ",
    "septuple ", "octuple ", "nonuple ", "decuple "
}; 