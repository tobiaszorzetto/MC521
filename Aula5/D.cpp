#include <iostream>
#include <vector>
using namespace std;

void solution(vector<int >set, int n){
    int a, b, c;
    a =  set[0] + set[1] - set[3];
    b = set[0] - a;
    c = set[0] -a;

    cout << a << " "<< b << " "<< c << endl;
}

// Driver code
int main()
{
    vector<int> set;
    for(int i = 0; i< 4; i++){
        int q;
        cin >> q;
        set.push_back(q);
    }
    solution(set);
    return 0;
}