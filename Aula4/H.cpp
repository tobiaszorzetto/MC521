#include <iostream>
#include <vector>
using namespace std;

int getNumber(int k, vector<int> A){
    int sum = 0;
    for(int i = 0; i< k; i++){
        if(A[i] <= A[k]){
            sum++;
        }
    }
    return sum;
}

int solution(vector<int >set, int n){
    vector<int> B = vector<int> (n, 0);
    int sum = 0; 
    for(int i = 0; i< n; i++){
        B[i] = getNumber(i, set);
        sum+=B[i];
    }
    return sum;
}

// Driver code
int main()
{
    int t;
    cin >> t;
    while(t--){
        vector<int> set;
        int n;
        cin >> n;
        for(int i = 0; i< n; i++){
            int q;
            cin >> q;
            set.push_back(q);
        }
        cout << solution(set, n) << endl;

    }
    return 0;
}