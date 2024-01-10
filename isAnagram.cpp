#include <bits/stdc++.h>

using namespace std;

// this approach is to sort both strings and then compare bith string character wise.

bool isAnagram2(string s, string t)
{
    sort(s.begin(), s.end());
    sort(t.begin(), t.end());

    if (s.length() > t.length() || t.length() > s.length())
    {
        return false;
    }

    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] != t[i])
        {
            return false;
        }
    }
    return true;
}

// another approach is to simply make two arrays of 256 size and use that array to keep track of characters.

bool isAnagram(string s, string t)
{
    int hashArr[256] = {0};
    if (s.length() > t.length() || t.length() > s.length())
    {
        return false;
    }
    for (int i = 0; i < s.length(); i++)
    {
        hashArr[(s[i] - 0)]++;
    }

    for (int i = 0; i < t.length(); i++)
    {
        hashArr[(t[i] - 0)]--;
    }

    for (int i = 0; i < 256; i++)
    {
        if (hashArr[i] != 0)
        {
            return false;
        }
    }
    return true;
}

int main()
{
    // string s = "anagram";
    // string t = "nagaram";

    string s = "drcat";
    string t = "cdtet";

    // cout << ('s' - 0) << endl;

    cout << isAnagram(s, t) << endl;
}