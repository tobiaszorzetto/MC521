#include <iostream>
#include <vector>
#include <string>
#include <bits/stdc++.h>
using namespace std;
 

vector<int> commonNumbers(vector<int> n, vector<int> m)
{
    vector<int> a;
    for(int i=0;i<n.size();i++)
    {
        for(int j=0;j<m.size();j++)
        {
            if(n[i]==m[j])
            a.push_back(n[i]);
        }
    }
   return a;
}

void solution(int n, vector<vector<int>> linhas){
    vector<int> a = linhas[0];
    for(int i = 1; i < n; i++){
        vector<int> b = commonNumbers(a, linhas[i]);
        a.clear();
        a = b;
    }

    for(int i = 0; i < a.size(); i++){
        cout << a[i]<< " ";
    } cout << endl;

    return;
}
 

int main()
{
    int t;
    cin >> t;
    int n = t;
    vector<vector<int>> linhas;
    while (t--)
    {
        
        vector<int> linha;
        int n;
        cin >> n;

        for(int i = 0; i < n; i++ ){
            int k;
            cin >> k;
            linha.push_back(k);
        }
        linhas.push_back(linha);
    }
    solution(n, linhas);
    return 0;
}