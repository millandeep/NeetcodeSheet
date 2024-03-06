#include <bits/stdc++.h>
using namespace std;

bool isValid(char a)
{
    if ((a >= 'a' && a <= 'z') || (a >= '0' && a <= '9') || (a >= 'A' && a <= 'Z'))
    {
        return true;
    }
    return false;
}

bool isPalindrome(string s)
{
    int start = 0;
    int end = s.length() - 1;

    while (start < end)
    {
        if (isValid(s[start]) && isValid(s[end]))
        {
            if (tolower(s[start]) == tolower(s[end]))
            {
                start++;
                end--;
            }
            else
            {
                return false;
            }
        }
        else if (!isValid(s[start]))
        {
            start++;
        }
        else if (!isValid(s[end]))
        {
            end--;
        }
    }
    return true;
}

int main()
{
    string s = "race a car";
    // string s = " ";
    // string s = "A man, a plan, a canal: Panama";

    if (isPalindrome(s))
    {
        cout << "true";
    }
    else
    {
        cout << "false";
    }
}