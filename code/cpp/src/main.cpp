////////////////////////////////////////////////////////////////////////////////
/// \file
/// \brief      Some simple samples on regular expressions in C++.
/// \author     Sergey Shershakov
/// \version    0.1.0
/// \date       13.11.2020
/// \copyright  © Sergey Shershakov 2020.
///             This code is for educational purposes of the course "Algorithms
///             and Data Structures" provided by the Faculty of Computer Science
///             at the Higher School of Economics.
///
/// When altering code, a copyright line must be preserved.
///
////////////////////////////////////////////////////////////////////////////////


#include <iostream>
#include <string>
#include <regex>


void test1()
{
    std::regex e1("ab*");
    bool r1 = std::regex_search("a", e1);
    r1 = std::regex_search("ab", e1);
    r1 = std::regex_search("b", e1);

    int a = 0;
}

void test2()
{
    std::cout << "\n\nTest2\n";
    std::regex e2("\\+[0-9]-[0-9]{3}-[0-9]{3}-[0-9]{4}");
    std::string s1("asd123sdf456\nThe phone number is +7-495-772-9590.\n"
                   "Another number is +7-916-123-1718.");
    std::smatch sm;

    // case 1
    bool r1 = std::regex_search(s1, sm, e2);


    // case 2
    std::string s2(s1);
    while(std::regex_search(s2, sm, e2))
    {
        std::cout << "Found: " << sm.str() << "\n";
        s2 = sm.suffix();
    }

    // case 3
    auto wBegin =
            std::sregex_iterator(s1.begin(), s1.end(), e2);
    auto wEnd = std::sregex_iterator();

    std::cout << "Found "
              << std::distance(wBegin, wEnd)
              << " words:\n";

    for (std::sregex_iterator i = wBegin; i != wEnd; ++i)
    {
        std::smatch match = *i;
        std::string matchS = match.str();
        std::cout << matchS << '\n';
    }


    int a = 0;
}


int main()
{
    std::cout << "Let's do some regex's!\n";

    test1();
    test2();

    std::cout << "\n\nBye-bye!\n\n";
    return 0;
}

