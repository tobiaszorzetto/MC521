#include <iostream>
#include <vector>
using namespace std;


// algoritmo copiado de https://www.geeksforgeeks.org/subset-sum-problem-dp-25/
bool isSubsetSum(vector<int> set, int n, int sum)
{
    if (sum == 0)
        return true;
    if (n == 0)
        return false;
    if (set[n - 1] > sum)
        return isSubsetSum(set, n - 1, sum);
 
    return isSubsetSum(set, n - 1, sum)
           || isSubsetSum(set, n - 1, sum - set[n - 1]);
}

string solution(vector<int >set, int sum, int n){
    if(isSubsetSum(set,n, sum)){
        return "YES";
    }
    return "NO";
}

// Driver code
int main()
{
    int t;
    cin >> t;
    while(t--){
        vector<int> set;
        int sum;
        cin >> sum;
        int n;
        cin >> n;
        for(int i = 0; i< n; i++){
            int q;
            cin >> q;
            set.push_back(q);
        }
        cout << solution(set, sum, n) << endl;

    }
    return 0;
}