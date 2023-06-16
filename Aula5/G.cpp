#include <iostream>
#include <vector>
#include <cmath>
using namespace std;


int divisor(int number, int max)
    {
        int i;
        for (i = int(number/max); i<=sqrt(number); i++)
        {
            if (number % i == 0)
            {
                return i;
            }
        }
        return number;
    }

int solution(vector<int >set){
    if(set[0] <= set[1]) return 1;
    return divisor(set[0],set[1]);
}

int main()
{
    int t;
    cin >> t;
    while(t--){
        vector<int> set;
        for(int i = 0; i< 2; i++){
            int q;
            cin >> q;
            set.push_back(q);
        }
        cout << solution(set) << endl;

    }
    return 0;
}