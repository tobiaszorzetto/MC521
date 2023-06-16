#include <iostream>
#include <vector>
#include <string>
#include <bits/stdc++.h>
using namespace std;
 
 
void solution(string a){
    bool jaPegou0 = false;

    if(a[0] == '0'){
        jaPegou0 = true;
    }

    for(int i = 1; i< a.size(); i++){
        if(a[i] != a[i-1]){
            if(a[i] == '0'){
                if(jaPegou0){
                    cout << 2 << endl;
                    return;
                }
                jaPegou0 = true;
            }
        }
    }

    if(!jaPegou0){
        cout << 0 << endl;
        return;
    }
    cout << 1 << endl;
    return;

}
 

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string a;

        cin >> a;

        solution(a);
    }
    return 0;
}