#include <iostream>
#include <vector>
#include <limits>
#include <map>
using namespace std;

int solution(int n, vector<int> set)
{
    vector<int> restos = {0, 0, 0};
    for (int i = 0; i < n; i++)
    {
        restos[set[i] % 3]++;
    }
    int sum = 0;
    while (restos[0] != n / 3 || restos[1] != n / 3 || restos[2] != n / 3)
    {
        for (int i = 0; i < 3; i++)
        {
            while (restos[i] > n / 3)
            {
                sum++;
                if (i == 0)
                {
                    restos[i + 1]++;
                    restos[i]--;
                }
                else if (i == 1) 
                {
                    restos[i]--;
                    restos[2]++;
                }
                else{
                    restos[i]--;
                    restos[0]++;
                }
            }
        }
    }
    return sum;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        vector<int> set;
        int n;
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            int k;
            cin >> k;
            set.push_back(k);
        }
        cout << solution(n, set) << endl;
    }
    return 0;
}