#include <iostream>
#include <vector>
#include <string>
#include <bits/stdc++.h>
using namespace std;
 

void solution(int n, int k){
    vector<vector<int>> m = vector<vector<int>>(n, vector<int>(k)); 
    for(int i = 0; i< n; i++){
        m[i][0] = 1;
    }
    for(int i = 0; i< k; i++){
        m[0][i] = 1;
    }

    for(int i = 1; i< n; i++){
        for(int j = 1; j < k; j++){
            if (i>j)
                m[i][j] = m[i][j-1] + m[i-j][j];
            else if(i == j) 
                m[i][j] = 1;
            else
                m[i][j] = 0;
        }
    }
    for(int i = 0; i< n; i++){
        for(int j = 0; j < k; j++){
            cout << m[i][j] << " ";
        } cout << endl;
    }

    cout << m[n- 1][k - 1] << endl;
    return;
}
 

int main()
{
    int n, k;
    while (true)
    {
        cin >> n >> k;

        if(n == 0 and k == 0){
            break;
        }

        solution(n, k);
    }
    return 0;
}