#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int odds_sum(vector<int> odds, vector<int> odds_gotten, int n) {
  int a = 1;
  while (true) {
    if (a == n - a) {
      return -1;
    }
    if (odds_gotten[a] == 1 or
        odds_gotten[n-a] == 1) {
      a+=2;
    } else{
      return a;
    }
  }
  return -1;
}

void solution(int n) {

    if(n%4!=0){
        cout << "NO" << endl;
        return;
    }
    vector<int> set;
    vector<int> odds;
    vector<int> odds_gotten = vector<int>(n*2,0);
    int n_odds = 0;
    bool calculate = false;
    int sum = 0;
    for (int i = 0; i < n / 2; i++) {
        sum+=(i+1) * 2;
        set.push_back((i+1) * 2);
    }
    for(int i = 0; i< n/2-1; i++){
        set.push_back((i+1));
        sum-= ((i+1) * 2 - 1);
    }
    set.push_back(sum);
    cout << "YES" << endl;
    for(int i = 0; i< n; i++){
        cout << set[i] << " ";
    } cout<< endl;
}

// Driver code
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    solution(n);
  }
  return 0;
}