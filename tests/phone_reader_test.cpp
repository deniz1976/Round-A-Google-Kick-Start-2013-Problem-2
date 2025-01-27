#include <gtest/gtest.h>
#include "../src/phone_reader.hpp"

TEST(PhoneNumberReaderTest, Format344) {
    std::string phoneNumber = "15012233444";
    std::vector<int> format = {3, 4, 4};
    
    std::string expected = "one five zero - one double two three - three triple four ";
    std::string result = PhoneNumberReader::formatNumber(phoneNumber, format);
    
    EXPECT_EQ(result, expected);
}

TEST(PhoneNumberReaderTest, Format335) {
    std::string phoneNumber = "15012233444";
    std::vector<int> format = {3, 3, 5};
    
    std::string expected = "one five zero - one double two - double three triple four ";
    std::string result = PhoneNumberReader::formatNumber(phoneNumber, format);
    
    EXPECT_EQ(result, expected);
}

TEST(PhoneNumberReaderTest, ValidatePhoneNumber) {
    EXPECT_TRUE(PhoneNumberReader::validatePhoneNumber("12345678901"));
    EXPECT_FALSE(PhoneNumberReader::validatePhoneNumber("123"));
    EXPECT_FALSE(PhoneNumberReader::validatePhoneNumber("abcdefghijk"));
}

TEST(PhoneNumberReaderTest, ValidateFormat) {
    EXPECT_TRUE(PhoneNumberReader::validateFormat({3, 4, 4}, 11));
    EXPECT_TRUE(PhoneNumberReader::validateFormat({3, 3, 5}, 11));
    EXPECT_FALSE(PhoneNumberReader::validateFormat({3, 3}, 11));
    EXPECT_FALSE(PhoneNumberReader::validateFormat({5, 5, 5}, 11));
} 