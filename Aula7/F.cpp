#include <iostream>
#include <vector>
#include <string>
#include <algorithm>    
#include <bits/stdc++.h>
using namespace std;

void solution(int n, vector<long long int> a, vector<string> b)
{
    sort(a.begin(), a.end());
    int quant = 0;
    for(int i = 0; i<n; i++){
        if(b[i][0]=='-') quant++;
    }

    long long int sum = 0;

    for(int i = 0; i<n; i++){
        a[i] = abs(a[i]);
    }
    sort(a.begin(), a.end());
    for(int i = 1; i<n; i++){
        sum+= a[i];
    }

    if(quant%2 == 0){
        sum+= abs(a[0]);
    } else{
        sum-= abs(a[0]);
    }

    cout << sum << endl;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;

        cin >> n;

        vector<long long int> a;
        vector<string> b;

        for(int i = 0; i< n; i++){
            string k;
            cin >> k;
            a.push_back(stoi(k));
            b.push_back(k);
        }

        solution(n, a, b);
    }
    return 0;
}