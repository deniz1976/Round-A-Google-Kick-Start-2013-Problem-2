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

using namespace std;

std::string getnum(char a) {
    if (a == '0') {
        return "zero ";
    } else if (a == '1') {
        return "one ";
    } else if (a == '2') {
        return "two ";
    } else if (a == '3') {
        return "three ";
    } else if (a == '4') {
        return "four ";
    } else if (a == '5') {
        return "five ";
    } else if (a == '6') {
        return "six ";
    } else if (a == '7') {
        return "seven ";
    } else if (a == '8') {
        return "eight ";
    } else {
        return "nine ";
    }
}

// first format is 3-4-4 123 4567 8912
std::string firstFormat(const std::string &phoneNumber) {
    std::string multiples[] = {"double ", "triple ", "quadruple ", "quintuple ", "sextuple ", "septuple ", "octuple ",
                               "nonuple ", "decuple "};

    std::string firstPart = phoneNumber.substr(0, 3); // 0 1 2
    std::string secondPart = phoneNumber.substr(3, 4); // 3 4 5 6
    std::string thirdPart = phoneNumber.substr(7); // 7 8 9 10

    char firstArr[10] = {phoneNumber.at(0), phoneNumber.at(1), phoneNumber.at(2), 'a', 'b', 'c', 'd', 'e', 'f', 'g'};
    char secondArr[10] = {phoneNumber.at(3), phoneNumber.at(4), phoneNumber.at(5), phoneNumber.at(6), 'a', 'b', 'c',
                          'd', 'f', 'g'};
    char thirdArr[10] = {phoneNumber.at(7), phoneNumber.at(8), phoneNumber.at(9), phoneNumber.at(10), 'a', 'b', 'c',
                         'd', 'f', 'g'};

    std::string answer;
    int counter = 0;
    for (int i; counter < 3; i++) {
        i = counter;
        string x = getnum(firstArr[i]);
        if (firstArr[i] == firstArr[i + 1]) {
            i += 1;
            if (firstArr[i] == firstArr[i + 1]) {
//                i += 1;
                counter += 3;
                answer += multiples[1] + x;
            } else {
                i += 1;
                answer += multiples[0] + x;
                counter += 2;
            }
        } else {
            answer += x;
            counter += 1;
        }
    }

    answer += " - ";
    counter = 0;
    for (int i; counter < 4; i++) {
        i = counter;
        string x = getnum(secondArr[i]);
        if (secondArr[i] == secondArr[i + 1]) {
            i += 1;
            if (secondArr[i] == secondArr[i + 1]) {
                i += 1;
                if (secondArr[i] == secondArr[i + 1]) {
//                    i += 1;
                    answer += multiples[2] + x;
                    counter += 4;

                } else {
                    i += 1;
                    answer += multiples[1] + x;
                    counter += 3;
                }
            } else {
                i += 1;
                answer += multiples[0] + x;
                counter += 2;
            }
        } else {
            answer += x;
            counter += 1;
        }
    }
    answer += " - ";
    counter = 0;

    for (int i; counter < 4; i++) {
        i = counter;
        string x = getnum(thirdArr[i]);
        if (thirdArr[i] == thirdArr[i + 1]) {
            i += 1;
            if (thirdArr[i] == thirdArr[i + 1]) {
                i += 1;
                if (thirdArr[i] == thirdArr[i + 1]) {
//                    i += 1;
                    answer += multiples[2] + x;
                    counter += 4;
                } else {
                    i += 1;
                    answer += multiples[1] + x;
                    counter += 3;
                }
            } else {
                i += 1;
                answer += multiples[0] + x;
                counter += 2;
            }
        } else {
            answer += x;
            counter += 1;
        }
    }

    return answer;


}

// second format is 3-3-5 123 456 78912
std::string secondFormat(const std::string &phoneNumber) {
    std::string multiples[] = {"double ", "triple ", "quadruple ", "quintuple ", "sextuple ", "septuple ", "octuple ",
                               "nonuple ", "decuple "};

    std::string firstPart = phoneNumber.substr(0, 3); // 0 1 2
    std::string secondPart = phoneNumber.substr(3, 3); // 3 4 5
    std::string thirdPart = phoneNumber.substr(6); // 6 7 8 9 10

    char firstArr[10] = {phoneNumber.at(0), phoneNumber.at(1), phoneNumber.at(2), 'a', 'b', 'c', 'd', 'e', 'f', 'g'};
    char secondArr[10] = {phoneNumber.at(3), phoneNumber.at(4), phoneNumber.at(5), 'a', 'b', 'c',
                          'd', 'f', 'g', 'h'};
    char thirdArr[10] = {phoneNumber.at(6), phoneNumber.at(7), phoneNumber.at(8), phoneNumber.at(9), phoneNumber.at(10),
                         'a', 'b', 'c',
                         'd', 'f'};

    std::string answer;
    int counter = 0;
    for (int i; counter < 3; i++) {
        i = counter;
        string x = getnum(firstArr[i]);
        if (firstArr[i] == firstArr[i + 1]) {
            i += 1;
            if (firstArr[i] == firstArr[i + 1]) {
//                i += 1;
                counter += 3;
                answer += multiples[1] + x;
            } else {
                i += 1;
                answer += multiples[0] + x;
                counter += 2;
            }
        } else {
            answer += x;
            counter += 1;
        }
    }

    answer += " - ";
    counter = 0;

    for (int i; counter < 3; i++) {
        i = counter;
        string x = getnum(secondArr[i]);
        if (secondArr[i] == secondArr[i + 1]) {
            i += 1;
            if (secondArr[i] == secondArr[i + 1]) {
//                i += 1;
                counter += 3;
                answer += multiples[1] + x;
            } else {
                i += 1;
                answer += multiples[0] + x;
                counter += 2;
            }
        } else {
            answer += x;
            counter += 1;
        }
    }

    answer += " - ";
    counter = 0;
    for (int i; counter < 5; i++) {
        i = counter;
        string x = getnum(thirdArr[i]);
        if (thirdArr[i] == thirdArr[i + 1]) {
            i += 1;
            if (thirdArr[i] == thirdArr[i + 1]) {
                i += 1;
                if (thirdArr[i] == thirdArr[i + 1]) {
                    i += 1;
                    if (thirdArr[i] == thirdArr[i + 1]) {
                        answer += multiples[3] + x;
                        counter += 5;
                    } else {
                        i += 1;
                        answer += multiples[2] + x;
                        counter += 4;
                    }

                } else {
                    i += 1;
                    answer += multiples[1] + x;
                    counter += 3;
                }
            } else {
                i += 1;
                answer += multiples[0] + x;
                counter += 2;
            }
        } else {
            answer += x;
            counter += 1;
        }
    }


    return answer;
}

int main() {

    bool loop = true;
    std::string phoneNumber;
    while (loop) {
        std::cout << "Enter a phone number 11 digits " << std::endl;
        cin >> phoneNumber;
        if (phoneNumber.size() == 11) {
            loop = false;
            std::cout << "" << std::endl;
        } else {
            phoneNumber = "";
        }
    }

    std::string x = firstFormat(phoneNumber);
    std::string y = secondFormat(phoneNumber);
    std::cout << "3-4-4 solution" << std::endl;
    std::cout << x << std::endl;
    std::cout << "3-3-5 solution" << std::endl;
    std::cout << y << std::endl;

    return 0;

}



