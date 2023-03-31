#include <iostream>
#include <vector>
#include <map>
using namespace std;


// algoritmo copiado de https://www.geeksforgeeks.org/subset-sum-problem-dp-25/
void solution(int k){
    map<int, int> m;
    vector<int> xs;
    int y = k+1;
    int x;
    int sum = 0;
    while(true){
        if(k*k/(y-k) - (int) (k/(y-k)) == 0){
            sum++;
            x = k + k*k/(y-k);
            cout << y << " "<<  x << endl;
            m[x] = y;
            xs.push_back(x);
            if(y >= x){
                break;
            }
        }
        y++;
    }
    cout << sum << endl;
    for (int c : xs)
        cout << "1/" << k << " = 1/" << c << " + 1/" << m[c] << endl;
}

// Driver code
int main(){
    int k;
    while(cin >> k){

        solution(k);
    }
    return 0;
}