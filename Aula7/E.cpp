#include <iostream>
#include <vector>
#include <string>
#include <bits/stdc++.h>
using namespace std;

string complete(int pos, int quant, string a, char c){
    for(int i = pos; i< pos+quant; i++){
        if(c == 'R') c = 'B';
        else c = 'R';

        a[i] = c;
    }

    return a;
} 
 
void solution(int n, string a){
    int quant = 0;
    int pos = 0;
    int posPainted = -1;
    for(int i = 0; i< n; i++){
        if(a[i] == '?'){
            if(quant == 0){
                pos = i;
                quant++;
            } 
            else{
                quant++;
            }
        }
        if(a[i] == 'B' or a[i] == 'R'){
            if (posPainted == -1){
                if( quant % 2 == 0 and a[i] == 'R'){
                    a = complete(pos, quant, a, 'B');
                }
                else if( quant % 2 == 1 and a[i] == 'R'){
                    a = complete(pos, quant, a, 'R');
                }
                else if( quant % 2 == 0 and a[i] == 'B'){
                    a = complete(pos, quant, a, 'R');
                }
                else{
                    a = complete(pos, quant, a, 'B');
                }
            } else{

                a = complete(pos, quant, a, a[posPainted]);
            }
            posPainted = i;
            quant = 0;
        }
    }
    char color;
    if(posPainted == -1){
        color = 'R';
    } else{

        color = a[posPainted];
    }

    for(int i = pos; i< pos+quant; i++ ){
        if(color == 'R') color = 'B';
        else color = 'R';
        a[i] = color;
    }

    cout << a << endl;

}
 

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string a;

        int n;
        cin >> n;
        cin >> a;

        solution(n, a);
    }
    return 0;
}