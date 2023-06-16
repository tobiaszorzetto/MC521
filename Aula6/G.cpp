#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int findAsw(vector<int> red, vector<int> blue, vector<int> res, vector<int> aux,
            int n, int m, int posB, int posRed, int posRes) {
  if (posRes < m + n and posB < m and posRed < n) {
    res.push_back(blue[posB]);
    aux.push_back(red[posRed]);
    return max(
        findAsw(red, blue, res, res, n, m, posB + 1, posRed, posRes + 1),
        findAsw(red, blue, aux, aux, n, m, posB, posRed + 1, posRes + 1));
  } else if (posRed < n and posRes < m + n) {
    aux.push_back(red[posRed]);
    return findAsw(red, blue, aux, aux, n, m, posB, posRed + 1, posRes + 1);
  } else if (posB < m and posRes < m + n) {
    res.push_back(blue[posB]);
    return findAsw(red, blue, res, res, n, m, posB + 1, posRed, posRes + 1);
  } else {
    vector<int> v;
    for (int i = 0; i <= n + m; i++) {
      if (i == 0) {
        v.push_back(0);
      } else if (i == 1) {
        v.push_back(res[0]);
      } else {
        v.push_back(v[i - 1] + res[i - 1]);
      }
    }
    /for (int i = 0; i < n + m; i++) {
      cout << res[i] << "  ";
    }
    for (int i = 0; i <= n + m; i++) {
      cout << v[i] << " ";
    }
    cout << "Fim de um dos vetores and " <<max_element(v.begin(), v.end())
         << " ";
    return max_element(v.begin(), v.end());
  }
}

int main() {
  int t, n, m, aux, posB, posRed, posRes;
  vector<int> red, blue, res;
  cin >> t;
  while (t--) {
    posB = posRed = posRes = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
      cin >> aux;
      red.push_back(aux);
    }
    cin >> m;
    for (int i = 0; i < m; i++) {
      cin >> aux;
      blue.push_back(aux);
    }
    aux = findAsw(red, blue, res, res, n, m, posB, posRed, posRes);
    red.clear();
    blue.clear();
    res.clear();
    cout << aux << "\n";
  }
}