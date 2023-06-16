#include <iostream>
#include <vector>
using namespace std;




string solution(vector<int >set, int n){
    sort(set.begin(), set.end())
    for(int i = 0; i<n-1;i++){
        if(set[i+1]-set[i]>1){
            return "NO"
        }
    }
    return "YES"
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