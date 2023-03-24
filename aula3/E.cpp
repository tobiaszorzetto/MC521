#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>
#include <map>

#include <bits/stdc++.h>
using namespace std;

void isValid(vector<vector<string>> players)
{
    vector<int> points = vector<int>(3, 0);
    map<string, int> map;

    for (int j = 0; j < 3; j++)
    {

        for (string word : players[j])
        {
            if (map.find(word) != map.end())
            {
                map[word]++;
            }
            else
            {
                map[word] = 1;
            }
        }
    }
    for (int j = 0; j < 3; j++)
    {

        for (string word : players[j])
        {
            if (map[word] == 1)
            {
                points[j] += 3;
            }
            else if (map[word] != 3)
            {
                points[j]++;
            }
        }
    }

    for (int i = 0; i < 3; i++)
    {
        cout << points[i] << " ";
    }
    cout << endl;
}

int main()
{
    int tests;
    vector<vector<vector<string>>> words;
    cin >> tests;
    for (int i = 0; i < tests; i++)
    {
        int quant;
        vector<int> starts;
        vector<int> ends;
        cin >> quant;
        vector<vector<string>> ws;
        for (int k = 0; k < 3; k++)
        {
            vector<string> w;
            for (int j = 0; j < quant; j++)
            {
                string n;
                cin >> n;
                w.push_back(n);
            }
            ws.push_back(w);
        }
        words.push_back(ws);
    }
    for (int i = 0; i < tests; i++)
    {
        isValid(words[i]);
    }
}