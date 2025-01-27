#include "phone_reader.hpp"
#include <algorithm>

std::string PhoneNumberReader::getNumberWord(char digit) {
    return numberWords.at(digit);
}

std::string PhoneNumberReader::getMultiplier(int count) {
    if (count <= 1 || count > 10) return "";
    return multipliers[count - 2];
}

std::string PhoneNumberReader::processSegment(const std::string& segment) {
    std::string result;
    for (size_t i = 0; i < segment.length();) {
        char current = segment[i];
        size_t count = 1;
        
        while (i + count < segment.length() && segment[i + count] == current) {
            count++;
        }
        
        if (count > 1) {
            result += getMultiplier(count) + getNumberWord(current);
        } else {
            result += getNumberWord(current);
        }
        
        i += count;
    }
    return result;
}

std::string PhoneNumberReader::formatNumber(const std::string& phoneNumber, const std::vector<int>& format) {
    if (!validatePhoneNumber(phoneNumber) || !validateFormat(format, phoneNumber.length())) {
        return "";
    }

    std::string result;
    size_t pos = 0;
    
    for (size_t i = 0; i < format.size(); i++) {
        if (i > 0) result += "- ";
        std::string segment = phoneNumber.substr(pos, format[i]);
        result += processSegment(segment);
        pos += format[i];
    }
    
    return result;
}

bool PhoneNumberReader::validatePhoneNumber(const std::string& phoneNumber) {
    if (phoneNumber.length() != 11) return false;
    return std::all_of(phoneNumber.begin(), phoneNumber.end(), ::isdigit);
}

bool PhoneNumberReader::validateFormat(const std::vector<int>& format, size_t numberLength) {
    size_t sum = 0;
    for (int num : format) {
        sum += num;
    }
    return sum == numberLength;
} 