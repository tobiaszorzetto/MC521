#include <iostream>
#include <vector>
#include <string>
#include <bits/stdc++.h>
using namespace std;
 

void solution(int n, int v){
    n = n - 1;
    int p = 2;
    int k;
    if(n < v){
        cout << n << endl;
        return; 
    } else{
        k = v;
        n -=v;
    }

    while(n>0){
        n--;
        k +=p;
        p++;
    }

    cout << k << endl;
    return; 

}
 

int main()
{
    int n, v;
    cin >> n >> v;
    solution(n, v);
    return 0;
}