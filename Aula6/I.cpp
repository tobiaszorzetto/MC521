
#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;
 
int knapSack(int W, vector<int> wt, vector<int> val, int n)
{
    int i, w;
    int K[2][W + 1];
    for (i = 0; i <= n; i++) {
        for (w = 0; w <= W; w++) {
            if (i == 0 || w == 0)
                K[i % 2][w] = 0;
            else if (wt[i - 1] <= w)
                K[i % 2][w] = max(
                    val[i - 1]
                        + K[(i - 1) % 2][w - wt[i - 1]],
                    K[(i - 1) % 2][w]);
            else
                K[i % 2][w] = K[(i - 1) % 2][w];
        }
    }
    return K[n % 2][W];
}
 
int solution(int n, int nn, vector<int> quant_pessoas, vector<int> pesos, vector<int> valores){
    int sum = 0;
    for(int i = 0; i< nn; i++){
        sum += knapSack(quant_pessoas[i], pesos, valores, n);
    }
    return sum;
}
 

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        vector<int> pesos;
        vector<int> valores;
        vector<int> quant_pessoas;
        int n;
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            int k;
            int l;
            cin >> k >> l ;
            valores.push_back(k);
            pesos.push_back(l);
        }
        int nn;
        cin >> nn;
        for (int i = 0; i < nn; i++)
        {
            int k;
            cin >> k;
            quant_pessoas.push_back(k);
        }
        cout << solution(n, nn, quant_pessoas, pesos, valores) << endl;
    }
    return 0;
}