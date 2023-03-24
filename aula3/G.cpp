#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;

void isValid(vector<int> starts, vector<int> ends) {

    vector<int> times;
    for(int i = 0; i< starts.size(); i++){
        if(i == 0){
            times.push_back(ends[i] - starts[i]);
        }
        else{
            times.push_back(ends[i] - max(ends[i-1], starts[i]));
        }
    }
    for(int time : times){
        cout << time << " ";
    }cout << endl;

}

int main() {
  int tests;
  vector<vector<int>> n_starts;
  vector<vector<int>> n_ends;
  cin >> tests;
  for(int i = 0; i< tests; i++){
    int quant;
    vector<int> starts;
    vector<int> ends;
    cin >> quant;
    for(int j = 0; j< quant; j++){
        int n;
        cin >> n;
        starts.push_back(n);
    }
    n_starts.push_back(starts);
    for(int j = 0; j< quant; j++){
        int n;
        cin >> n;
        ends.push_back(n);
    }
    n_ends.push_back(ends);
  }
  for(int i = 0; i< tests; i++){
    isValid(n_starts[i], n_ends[i]);

  }
}