#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

void solution(vector<int> a, long long int sum, int comeco, int fim,
              long long int k, vector<long long int> m) {
  int sumPart = m[fim] - m[comeco - 1];
  int newSum = (fim - comeco + 1) * k;

  sum -= (sumPart - newSum);
  if (sum % 2 == 0) {
    cout << "NO" << endl;
  } else {
    cout << "YES" << endl;
  }
  return;
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    vector<int> a;
    int n, q;
    cin >> n >> q;
    vector<long long int> m = vector<long long int>(n + 1);
    m[0] = 0;
    long long int sum = 0;
    for (int i = 1; i < n + 1; i++) {
      long long int k;
      cin >> k;
      sum += k;
      a.push_back(k);
      m[i] = sum;
    }
    for (int i = 0; i < q; i++) {
      int comeco, fim;
      long long int k;
      cin >> comeco >> fim >> k;
      int sumPart = m[fim] - m[comeco - 1];
      int newSum = (fim - comeco + 1) * k;

      int sumQ = sum - (sumPart - newSum);
      if (sumQ % 2 == 0) {
        cout << "NO" << endl;
      } else {
        cout << "YES" << endl;
      }
    }
  }
  return 0;
}