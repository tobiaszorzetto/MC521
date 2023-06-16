#include <iostream>
#include <vector>
#include <string>
#include <bits/stdc++.h>
using namespace std;

void solution(int n, vector<long long int> a, vector<long long int> b)
{
    long long int quant = 0;
    for(int i = 1; i < n; i++){
        int k;
        for(int j = 0; j< n; j++){
            if(b[j] == a[i]){
                k = j;
            }
        }
        for(int j = 0; j < i; j++){
            int c = count(b.begin(), b.begin()+k+1, a[j]);
            if(c == 0){
                quant++;
                break;
            }
        }
    }

    cout << quant << endl;
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
        vector<long long int> b;

        for(int i = 0; i< n; i++){
            long long int k;
            cin >> k;
            a.push_back(k);
        }
        for(int i = 0; i< n; i++){
            long long int k;
            cin >> k;
            b.push_back(k);
        }

        solution(n, a, b);
    }
    return 0;
}