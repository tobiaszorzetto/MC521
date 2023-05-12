#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <bits/stdc++.h>
using namespace std;

unsigned solution(const vector<unsigned> &height, const vector<unsigned> &width)
{
    unsigned result = 0, i, j;
    vector<unsigned> lis(height.size());

    lis[0] = width[0];
    for (i = 1; i < height.size(); i++)
    {
        lis[i] = width[i];

        for (j = 0; j < i; j++)
        {
            if (height[j] < height[i] and lis[i] < lis[j] + width[j])
            {
                lis[i] = lis[j] + width[i];
            }
        }
    }

    for (i = 0; i < lis.size(); i++)
    {
        if (result < lis[i])
        {
            result = lis[i];
        }
    }
    return result;
}

int main()
{
    unsigned t, c, n, lis, lds;
    vector<unsigned> height, width;
    cin >> t;
    for (c = 1; c <= t; c++)
    {
        cin >> n;
        height.resize(n);
        width.resize(n);

        for (int i = 0; i < n; i++)
        {
            cin >> height[i];
        }
        for (int i = 0; i < n; i++)
        {
            cin >> width[i];
        }

        lis = solution(height, width);

        reverse(height.begin(), height.end());
        reverse(width.begin(), width.end());

        lds = solution(height, width);

        if (lis >= lds)
        {
            cout << "Case " << c << ". Increasing (" << lis << "). Decreasing ("
                 << lds << ")." << endl;
        }
        else
        {
            cout << "Case " << c << ". Decreasing (" << lds << "). Increasing ("
                 << lis << ")." << endl;
        }
    }
    return 0;
}