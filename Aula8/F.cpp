#include <iostream>
#include <vector>
#include <string>
#include <bits/stdc++.h>
using namespace std;
 


void solution(int n, string s){
    bool viu1 = false;
    char k = s[0];
    if(k == '1') viu1 = true;
    int sum = 0;
    for(int i = 1; i< n; i++){
        if(s[i] == '1' and viu1 == false){
            viu1 = true;
        }
        else if (s[i] == '0' and viu1 == true and k == '1'){
            sum++;
        }
        else if (s[i] == '1' and viu1 and k == '0'){
            sum++;
        }
        k = s[i];
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

        string s;
        cin >> s;
        
        solution(n, s);
    }
    return 0;
}