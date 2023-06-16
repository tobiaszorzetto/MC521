#include <iostream>
#include <vector>
#include <string>
using namespace std;

void solution(string set, string query){
    int j = 0;
    int f;
    cout << query << endl;
    for(int i = 0; i< query.length(); i++){
        if(query[i] < set[j]){
            cout << "Not mached " << i << " " << j<< " "<< query[i] << set[j] <<  endl;
            return;
        }
        while(query[i] > set[j]){
            j++;
        }
        if(query[i] == set[j]){
            if(i == 0){
                f = j;
            }
            else if (i == query.length()-1)
            {
                cout << "Mached" << f << " " << j << endl;
                return;
            }
            j++;
        }
      if(j>=set.length()){
        cout << "HAHHAHAHA" << endl;
        return;
      }
    }
  cout << query << endl;
  cout << "olololo" << endl;
}

int main()
{
    string set;
    getline(cin,set);
    int q;
    cin >> q;
    for(int i = 0; i<q+1;i++){
        string query = "";
        getline(cin,query);
        solution(set, query);
    }
    return 0;
}