
#include <iostream>
#include <vector>
#include <string>
#include <bits/stdc++.h>
using namespace std;
 
 
int solution(int n, int m, vector<int> N, vector<int> M){
    vector<int> ordered;
    int i,j = 0;
    while(i<n and j<m){
        if(i == n){
            ordered.push_back(M[j]);
            j++;
        } else if(j == m){
            ordered.push_back(N[i]);
            i++;
        } else if(M[j] > N[i]){
            ordered.push_back(M[j]);
            j++;
        } else if(M[j] <= N[i]){
            ordered.push_back(N[i]);
            i++;
        }
    }

    for(int i = 0; i< n+m; i++){
        cout << ordered[i] << " ";
    } cout << endl;
    
}
 

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        vector<int> N;
        vector<int> M;
        int n;
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            int k;
            cin >> k;
            N.push_back(k);
        }
        int m;
        cin >> m;
        for (int i = 0; i < m; i++)
        {
            int k;
            cin >> k;
            M.push_back(k);
        }
        cout << solution(n, m, N, M) << endl;
    }
    return 0;
}