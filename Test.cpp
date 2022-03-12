#include "doctest.h"
#include "mat.hpp"
using namespace ariel;

#include <string>
#include <algorithm>
#include <iostream>
using namespace std;
string nospaces(string input)
{
    std::erase(input, ' ');
    std::erase(input, '\t');
    std::erase(input, '\n');
    std::erase(input, '\r');
    return input;
}
bool isPalindrome(string input)
{
    string tmp = input;
    reverse(tmp.begin(), tmp.end());
    if (input == tmp)
    {
        return true;
    }
    else
    {
        return false;
    }
}

TEST_CASE("Good input")
{
    CHECK(nospaces(mat(9, 7, '@', '-')) == nospaces("@@@@@@@@@\n"
                                                    "@-------@\n"
                                                    "@-@@@@@-@\n"
                                                    "@-@---@-@\n"
                                                    "@-@@@@@-@\n"
                                                    "@-------@\n"
                                                    "@@@@@@@@@"));
    CHECK(nospaces(mat(3, 3, '@', '-')) == nospaces("@@@\n"
                                                    "@-@\n"
                                                    "@@@"));
    CHECK(nospaces(mat(7, 5, '&', '^')) == nospaces("&&&&&&&\n"
                                                    "&^^^^^&\n"
                                                    "&^&&&^&\n"
                                                    "&^^^^^&\n"
                                                    "&&&&&&&"));
}

TEST_CASE("is_palindrome")
{
    string st = "";
    for (int i = 1; i < 100; i += 2)
    {
        for (int j = 1; j < 150; j += 2)
        {
            st = nospaces(mat(i, j, '@', '-'));
            if (isPalindrome(st))
            {
               cout << "secces" << endl; 
            }
            else
            {
               FAIL_CHECK("FAILD_PALINDROME");
            }
        }
    }
}


TEST_CASE("EVEN")
{
    for (int i = 0; i < 100; i += 2)
    {
        for (int j = 0; j < 90; j += 2)
        {
            CHECK_THROWS(mat(i, j, '&', '#'));
        }
    }
}
TEST_CASE("Negative")
{
    CHECK_THROWS(mat(-7, 3, '&', '#'));
    CHECK_THROWS(mat(5, -9, '&', '#'));
    CHECK_THROWS(mat(-13, -3, '&', '#'));
}
TEST_CASE("Invalid symball")
{
    char a=12;
    char b='\0';
    CHECK_THROWS(mat(7, 3, a, b));
    a=20;
    b=22;
    CHECK_THROWS(mat(5, 9, a, b));
    a=30;
    CHECK_THROWS(mat(13, 3, a, b));
}

TEST_CASE("in_addition")
{
    CHECK(nospaces(mat(1, 1, '@', '-')) == nospaces("@\n"));
    CHECK(nospaces(mat(3, 1, '@', '-')) == nospaces("@@@\n"));
    CHECK(nospaces(mat(3, 5, '@', '-')) == nospaces("@@@\n"
                                                    "@-@\n"
                                                    "@-@\n"
                                                    "@-@\n"
                                                    "@@@"));
    CHECK(nospaces(mat(1, 3, '@', '-')) == nospaces("@\n"
                                                    "@\n"
                                                    "@"));
    CHECK(nospaces(mat(1, 1, '&', '-')) == nospaces("&\n"));
    CHECK(nospaces(mat(9, 7, '@', '-')) == nospaces("@@@@@@@@@\n"
                                                    "@-------@\n"
                                                    "@-@@@@@-@\n"
                                                    "@-@---@-@\n"
                                                    "@-@@@@@-@\n"
                                                    "@-------@\n"
                                                    "@@@@@@@@@"));
    CHECK(nospaces(mat(3, 5, '&', '-')) == nospaces("&&&\n"
                                                    "&-&\n"
                                                    "&-&\n"
                                                    "&-&\n"
                                                    "&&&"));
    CHECK(nospaces(mat(3, 7, '&', '-')) == nospaces("&&&\n"
                                                    "&-&\n"
                                                    "&-&\n"
                                                    "&-&\n"
                                                    "&-&\n"
                                                    "&-&\n"
                                                    "&&&"));
    CHECK(nospaces(mat(3, 9, '&', '-')) == nospaces("&&&\n"
                                                    "&-&\n"
                                                    "&-&\n"
                                                    "&-&\n"
                                                    "&-&\n"
                                                    "&-&\n"
                                                    "&-&\n"
                                                    "&-&\n"
                                                    "&&&"));
    CHECK(nospaces(mat(3, 11, '&', '-')) == nospaces("&&&\n"
                                                     "&-&\n"
                                                     "&-&\n"
                                                     "&-&\n"
                                                     "&-&\n"
                                                     "&-&\n"
                                                     "&-&\n"
                                                     "&-&\n"
                                                     "&-&\n"
                                                     "&-&\n"
                                                     "&&&"));
    CHECK(nospaces(mat(3, 13, '&', '-')) == nospaces("&&&\n"
                                                     "&-&\n"
                                                     "&-&\n"
                                                     "&-&\n"
                                                     "&-&\n"
                                                     "&-&\n"
                                                     "&-&\n"
                                                     "&-&\n"
                                                     "&-&\n"
                                                     "&-&\n"
                                                     "&-&\n"
                                                     "&-&\n"
                                                     "&&&"));
}
