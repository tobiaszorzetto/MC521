#include <iostream>
#include <vector>
#include <string>
#include <bits/stdc++.h>
#include <cmath>
using namespace std;
 


void solution(string s){
    int sum = 1 ;
    char k = 'o';
    for(int i = 0; i < s.size() - 1; i++){
        if(s[i] == 'u' and s[i+1] == 'u'){
            if(k != 'u'){
                sum*=2;
                k = 'u';
            } else{
                k = 'o';
            }
        }
        if(s[i] == 'n' and s[i+1] == 'n'){
            if(k != 'n'){
                sum*=2;
                k = 'n';
            } else{
                k = 'o';
            }
        }
    }
    sum = sum % int((pow(10,9) + 7));

    cout << sum << endl;

    return;
}
 

int main()
{

    string s;
    cin >> s;
    
    solution(s);
    return 0;
}