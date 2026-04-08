// OctToDec.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include <string>
#include <regex>
#include <math.h>


int main(int argc, char* args[])
{
    const unsigned int nMaxOctDigits = static_cast<unsigned int>(floor(log2(UINT32_MAX)/3));
    const std::regex oRegEx("^[0-7]+$");
    unsigned int nOctPower = 1;
    unsigned int nDecNum = 0;
    std::string strLine;
    system("cls");
    std::cout << "Input an octal number\r\n";
    std::getline(std::cin, strLine);
    unsigned int nStrLen = static_cast<unsigned int>(strLine.length());
    bool bIsRightString = (nStrLen <= nMaxOctDigits) && (std::regex_match(strLine, oRegEx));
    if (!bIsRightString)
    {
        std::cout << "Wrong octal number format!!!\r\n";
        std::cin.get();
        return 0;
    }
    for (unsigned int i = 0; i < nStrLen; i++)
    {
        unsigned int nOctDigit = strLine[nStrLen - 1 - i] - '0';
        nDecNum += (nOctDigit * nOctPower);
        nOctPower *= 8;
    }
    std::cout << "The decimal equivalent of the octal number "
              << strLine << " is: " << nDecNum << "\r\n";
    std::cin.get();
    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
