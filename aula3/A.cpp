#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>
#include <map>

#include <bits/stdc++.h>
using namespace std;


int isValid(vector<int> numbers) {
  map<int, int> map;
  for(int i = 0; i<numbers.size(); i++){
    if (map.find(numbers[i]) != map.end())
            {
                map[numbers[i]]++;
            }
            else
            {
                map[numbers[i]] = 1;
            }
  }
  int quant_repetidos = 0;
  for (auto const& x : map)
        {
          if (x.second >1){
            quant_repetidos++;
          }

        }
  if(quant_repetidos == 0){
    return 0;
  }

    int quant = 0;
    bool c = true;
    bool count = true;
    for(int i = 0; i<numbers.size(); i++){
      map[numbers[i]]--;
      quant++;
      if(map[numbers[i]]==1){
        quant_repetidos --;
      }
      if (quant_repetidos == 0) break;
    }
    return quant;
}

int main() {
  int tests;
  vector<vector<int>> n_numbers;
  cin >> tests;
  for(int i = 0; i< tests; i++){
    int quant;
    vector<int> numbers;
    cin >> quant;
    for(int j = 0; j< quant; j++){
        int n;
        cin >> n;
        numbers.push_back(n);
    }
    n_numbers.push_back(numbers);

  }
  for(vector<int> items : n_numbers){
    cout << isValid(items) << endl;

  }
}