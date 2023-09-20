#include <bits/stdc++.h>
using namespace std;

bool yesOrNo(string input)
{
    stack<char> st;
    for (int i = 0; i < input.length(); i++)
    {
        if (input[i] == ')')
        {
            if (st.empty()|| st.top() == '[')
                return false;
            st.pop();
        }

        if (input[i] == ']')
        {
            if (st.empty() || st.top() == '(')
                return false;
            st.pop();
        }

        if (input[i] == '(')
            st.push(input[i]);
        if (input[i] == '[')
            st.push(input[i]);
    }
    return st.empty();
}

int main()
{
    while (true)
    {
        string s;
        getline(cin, s);
        if (s == ".")
            break;
        if (yesOrNo(s))
            cout << "yes" << '\n';
        else
            cout << "no" << '\n';
    }
}
