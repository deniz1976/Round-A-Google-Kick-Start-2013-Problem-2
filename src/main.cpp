#include "phone_reader.hpp"
#include <iostream>

int main() {
    bool loop = true;
    std::string phoneNumber;
    
    while (loop) {
        std::cout << "Enter a phone number 11 digits " << std::endl;
        std::cin >> phoneNumber;
        if (PhoneNumberReader::validatePhoneNumber(phoneNumber)) {
            loop = false;
            std::cout << std::endl;
        } else {
            std::cout << "Invalid phone number! Please enter 11 digits." << std::endl;
        }
    }

    std::vector<int> format1 = {3, 4, 4}; // 3-4-4 format
    std::vector<int> format2 = {3, 3, 5}; // 3-3-5 format
    
    std::cout << "3-4-4 solution" << std::endl;
    std::cout << PhoneNumberReader::formatNumber(phoneNumber, format1) << std::endl;
    
    std::cout << "3-3-5 solution" << std::endl;
    std::cout << PhoneNumberReader::formatNumber(phoneNumber, format2) << std::endl;

    return 0;
} 