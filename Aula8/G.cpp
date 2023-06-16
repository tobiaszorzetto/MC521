#include <iostream>
#include <vector>
#include <string>
#include <bits/stdc++.h>
using namespace std;

int getValue (vector<int> a){
    if (count(a.begin(), a.end(), '0') > 0){
        if(count(a.begin(), a.end(), '1') > 0){
            return 2;
        }
        return 1;
    }
    return 0;
}

vector<int> comb (vector<int> a, vector<int> b){
    for(int i = 0; i< b.size(); i++){
        a.push_back(b[i]);
    }
    return a;
}

void solution(int n, string a, string b){
    vector<int> v = vector<int>(n+1);
    v[0] = 0;
    vector<vector<int>> v_comb= vector<vector<int>>(n+1);

    for(int i = 1; i< n+1; i++){
        vector<int> p;
        p.push_back(a[i-1]);
        p.push_back(b[i-1]);
        vector<int> c = comb(v_comb[i-1], p);
        int v1 = v[i-1]+ (getValue(c) - getValue(v_comb[i-1]));
        int v2 = v[i-1] + getValue(p);

        if(v1> v2){
            v_comb[i] = c;
            v[i] = v1;
        } else{
            v[i] = v2;
            v_comb[i] = p; 
        }
        
    }

    cout << v[n] << endl;
    return;


}
 

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        
        int n;
        cin >> n;

        string a;
        cin >> a;

        string b;
        cin >> b;
        
        solution(n, a, b);
    }
    return 0;
}