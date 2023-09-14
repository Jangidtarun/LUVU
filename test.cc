#include <bits/stdc++.h>
using namespace std;

int main()
{
    cout << "hello world" << endl;
    int val = 3;
    string se = "suck";
    cout << val << " " << se << endl;
    
    vector<int> values = {1, 2, 3};
    for (int val : values)
        cout << val << " ";
    cout << endl;

    set<int> v;
    v.insert(3);
    v.insert(2);
    for (int val : v)
        cout << val << " ";
    cout << endl;

    unordered_set<int> s;
    s.insert(3);
    s.insert(2);
    s.insert(1);
    s.insert(2);
    for (int val : s)
        cout << val << " ";
    cout << endl;
}