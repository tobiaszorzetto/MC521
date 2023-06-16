#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

void solution(int n, vector<int> numbers) {

  vector<int> indices = vector<int>(3, 0);
  vector<int> values = vector<int>(3, 0);

  int pos = 0;

  for (int i = 1; i < n; i++) {
    if (pos == 0 and numbers[i] > numbers[i - 1]) {
      indices[0] = i;
      values[0] = numbers[i - 1];
      indices[1] = i + 1;
      values[1] = numbers[i];
      pos++;
    }
    if (pos == 1 and numbers[i] > values[1]) {
      values[1] = numbers[i];
      indices[1] = i + 1;
    }
    if (pos == 1 and numbers[i] < values[1]) {
      cout << "YES\n"
           << indices[0] << " " << indices[1] << " " << i + 1 << endl;
      return;
    }
  }
  cout << "NO" << endl;

  return;
}

// Driver code
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    vector<int> numbers;
    cin >> n;
    for (int i = 0; i < n; i++) {
      int k;
      cin >> k;
      numbers.push_back(k);
    }
    solution(n, numbers);
  }
  return 0;
}