#include <iostream>
#include <vector>
#include <string>
#include <bits/stdc++.h>
using namespace std;

void solution(int a, int b, int m, string caminho){
    reverse(caminho.begin(), caminho.end());
    int n =caminho.size();
    vector<int> v = vector<int>(n+1);
    v[0] = 0;
    vector<char> v_comb= vector<char>(n+1);
    v_comb[0] = 'O';

    for(int i = 1; i< n; i++){
        char k = caminho[i-1];
        if(k == v_comb[i-1]){
            v[i] = v[i-1]; 
        } else if (k == 'B'){
            v[i] = v[i-1] + b;
        } else if (k == 'A'){
            v[i] = v[i-1] + a;
        }

        v_comb[i] = k;
        
    }
    v[n] = v[n-1];

    for(int i = 1; i< n+1; i++){
        if(v[i]>m){
            int k = n - (i - 2 );
            if(k>n) k = n;
            cout << k << endl;
            return;
        }
    }
    cout << "1" << endl;
    return;


}
 

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        
        int a, b, m;

        cin >> a >> b >> m;

        string caminho;
        cin>> caminho;

        
        solution(a, b, m, caminho);
    }
    return 0;
}