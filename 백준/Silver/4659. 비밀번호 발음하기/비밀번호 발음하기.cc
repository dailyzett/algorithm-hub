#include <bits/stdc++.h>
using namespace std;

string s;

bool isVowel(char c)
{
    return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
}

bool aeiou(string s)
{
    string vowels = "aeiou";
    for (char vowel : vowels)
    {
        size_t f = s.find(vowel);
        if (f != string::npos)
        {
            return true;
        }
    }
    return false;
}

bool three_duplicate(string s)
{
    int vowelCount = 0;
    int consonatnsCount = 0;

    for (char c : s)
    {
        if (isVowel(c))
        {
            vowelCount++;
            consonatnsCount = 0;
        }
        else
        {
            vowelCount = 0;
            consonatnsCount++;
        }

        if (consonatnsCount == 3 || vowelCount == 3)
        {
            return false;
        }
    }

    return true;
}

bool same_alpabet(string s)
{
    char before = s[0];
    for (int i = 1; i < s.size(); i++)
    {
        if (s[i] == 'e' || s[i] == 'o')
            continue;
        if (before == s[i])
            return false;
        before = s[i];
    }
    return true;
}

int main()
{
    while (true)
    {
        cin >> s;
        if(s == "end") break;
        if (aeiou(s) && three_duplicate(s) && same_alpabet(s))
        {
            cout << "<" << s << ">"
                 << " is acceptable.\n";
        }
        else
        {
            cout << "<" << s << ">"
                 << " is not acceptable.\n";
        }
    }
}