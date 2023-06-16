#include <iostream>
#include <vector>
using namespace std;




string solution(vector<int >set){
    n = set[0];

    vector<int> pesos = {2,3,5,7}
    vector<int> quants = {100,1000,1000000}

    for(int i = 0; int i<3; i++){
        if(n>pesos[i]*quants[i]){
            n-=pesos[i]*quants[i];

        }
    }

}

// Driver code
int main()
{
    while(true){
        vector<int> set;
        for(int i = 0; i< 2; i++){
            int q;
            cin >> q;
            set.push_back(q);
        }
        if(set[1] == 0) break;
        cout << solution(set) << endl;

    }
    return 0;
}