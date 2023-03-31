#include <iostream>
#include <vector>
#include <limits>
#include <map>
using namespace std;



int solution(int n){
    vector<int> M = {6,8,10};
    map<int,int> V = {{6,15},{8,20},{10,25}};
    vector<int> P(n+1,0);
    vector<int> Z(n+1,0);
    for(int i = 1; i< n+1; i++){
        Z[i] =  numeric_limits<int>::max();
        if(i<=6){
            Z[i] = 1;
            P[i] = 6;
        }
        for(int j = 0; j<3; j++){
            if(M[j] <=i && Z[i-M[j]]< Z[i]){
                Z[i] = Z[i-M[j]];
                P[i] = M[j];
            }
        }

    }
    int sum = 0;
    while(n>0){
        sum+= V[P[n]];
        cout << P[n] << " "<< n << endl;
        n -= P[n-1];
    }
    return sum;
}

// Driver code
int main()
{
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        cout << solution(n)<< endl;

    }
    return 0;
}