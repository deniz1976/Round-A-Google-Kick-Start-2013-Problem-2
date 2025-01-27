/**
 * @name Deniz Mutlu
 */

/** Problem
Do you know how to read the phone numbers in English? Now let me tell you.

For example, In China, the phone numbers are 11 digits, like: 15012233444. Someone divides the numbers into 3-4-4
format, i.e. 150 1223 3444. While someone divides the numbers into 3-3-5 format, i.e. 150 122 33444. Different formats
lead to different ways to read these numbers:

110 0223 3444 reads one five zero one double two three three triple four.

150 122 33444 reads one five zero one double two double three triple four.

Here comes the problem:

Given a list of phone numbers and the dividing formats, output the right ways to read these numbers.

Rules:

Single numbers just read them separately.

2 successive numbers use double.

3 successive numbers use triple.

4 successive numbers use quadruple.

5 successive numbers use quintuple.

6 successive numbers use sextuple.

7 successive numbers use septuple.

8 successive numbers use octuple.

9 successive numbers use nonuple.

10 successive numbers use decuple.

More than 10 successive numbers read them all separately.

Input
The first line of the input gives the number of test cases, T. T lines|test cases follow. Each line contains a phone
number N and the dividing format F, one or more positive integers separated by dashes (-), without leading zeros and
whose sum always equals the number of digits in the phone number.

Output
For each test case, output one line containing "Case #x: y", where x is the case number (starting from 1) and y is the
reading sentence in English whose words are separated by a space.

Limits
Time limit: 30 seconds per test set.
Memory limit: 1GB.
1 ≤ T ≤ 100.

Test set 1 - Visible
1 ≤ length of N ≤ 10.

Test set 2 - Hidden
1 ≤ length of N ≤ 100.
 *
 */

#include <iostream>
#include <string>
#include <map>
#include <vector>

using namespace std;

class PhoneNumberReader {
private:
    static const map<char, string> numberWords;
    static const vector<string> multipliers;
    
    static string getNumberWord(char digit) {
        return numberWords.at(digit);
    }
    
    static string getMultiplier(int count) {
        if (count <= 1 || count > 10) return "";
        return multipliers[count - 2];
    }
    
    static string processSegment(const string& segment) {
        string result;
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

public:
    static string formatNumber(const string& phoneNumber, const vector<int>& format) {
        string result;
        size_t pos = 0;
        
        for (size_t i = 0; i < format.size(); i++) {
            if (i > 0) result += "- ";
            string segment = phoneNumber.substr(pos, format[i]);
            result += processSegment(segment);
            pos += format[i];
        }
        
        return result;
    }
};

const map<char, string> PhoneNumberReader::numberWords = {
    {'0', "zero "}, {'1', "one "}, {'2', "two "}, {'3', "three "},
    {'4', "four "}, {'5', "five "}, {'6', "six "}, {'7', "seven "},
    {'8', "eight "}, {'9', "nine "}
};

const vector<string> PhoneNumberReader::multipliers = {
    "double ", "triple ", "quadruple ", "quintuple ", "sextuple ",
    "septuple ", "octuple ", "nonuple ", "decuple "
};

int main() {
    bool loop = true;
    string phoneNumber;
    
    while (loop) {
        cout << "Enter a phone number 11 digits " << endl;
        cin >> phoneNumber;
        if (phoneNumber.size() == 11) {
            loop = false;
            cout << endl;
        }
    }

    vector<int> format1 = {3, 4, 4}; // 3-4-4 format
    vector<int> format2 = {3, 3, 5}; // 3-3-5 format
    
    cout << "3-4-4 solution" << endl;
    cout << PhoneNumberReader::formatNumber(phoneNumber, format1) << endl;
    
    cout << "3-3-5 solution" << endl;
    cout << PhoneNumberReader::formatNumber(phoneNumber, format2) << endl;

    return 0;
}



