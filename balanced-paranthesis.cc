#include <bits/stdc++.h>
using namespace std;

bool is_balanced(string s)
{
    unordered_map<char, int> op = {{'(', 1}, {'{', 2}, {'[', 3}};
    unordered_map<char, int> cl = {{')', -1}, {'}', -2}, {']', -3}};
    stack<char> st;
    for (auto ch : s)
    {
        if (op.find(ch) != op.end())
            st.push(ch);
        else if (cl.find(ch) != cl.end())
        {
            if (!(op[st.top()] + cl[ch]))
                st.pop();
            else
                return false;
        }
    }
    if (!st.empty())
        return false;
    return true;
}

int main()
{
    string p = "[([][])()]";
    bool ans = is_balanced(p);
    if (ans)
        cout << "yes\n";
    else
        cout << "no\n";
}