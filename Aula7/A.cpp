#include <iostream>
#include <vector>
#include <string>
#include <bits/stdc++.h>
using namespace std;
 
 
void solution(int n, string a, string b){
    if(b[n-1] == '1'){
        cout << "NO" << endl;
        return;
    }
    for(int i = 0; i< n; i++){
        if(a[i] == '1' and b[i] == '1'){
            cout << "NO" << endl;
            return;
        }
    }

    cout << "YES" << endl;
    return;
}
 

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string a;
        string b;

        int n;
        cin >> n;
        cin >> a;
        cin >> b;

        solution(n, a, b);
    }
    return 0;
}