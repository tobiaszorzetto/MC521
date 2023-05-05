#include <iostream>
#include <vector>
#include <string>
#include <bits/stdc++.h>
using namespace std;

void solution(string a)
{
    int primeiro5 = -1;
    int primeiro0 = -1;
    int s;
    int i = a.size() - 1;
    for (i; i >= 0; i--)
    {
        if (a[i] == '5')
        {
            if (primeiro0 != -1)
            {
                s = (a.size() -1 - primeiro0) + (primeiro0 - i - 1);
                cout << s << endl;
                return;
            }
            else if (primeiro5 == -1)
            {
                primeiro5 = i;
            }
        }
        else if (a[i] == '0')
        {
            if (primeiro0 != -1)
            {
                s = (a.size() - 1  - primeiro0) + (primeiro0 - i - 1);
                cout << s << endl;
                return;
            }
            else if (primeiro0 == -1)
            {
                primeiro0 = i;
            }
        }
        else if (a[i] == '2' or a[i] == '7')
        {
            if (primeiro5 != -1)
            {
                s = (a.size() -1 - primeiro5) + (primeiro5 - i - 1);

                cout << s << endl;
                return;
            }
        }
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string a;

        cin >> a;

        solution(a);
    }
    return 0;
}