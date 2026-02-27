#include "sauce.h"
#include <bits/stdc++.h>
using namespace std;

int solve(int N) {
    vector<int> arr[6], tmp;
    int S[6], T[6][6], ans = 0;

    for (int i = 0; i < N; i++)
        arr[i % 6].push_back(i);
    for (int i = 0; i < 6; i++)
        S[i] = query(arr[i]), ans += S[i];

    for (int i = 0; i < 6; i++)
        for (int j = i + 1; j < 6; j++) {
            tmp.clear();
            tmp.insert(tmp.end(), arr[i].begin(), arr[i].end());
            tmp.insert(tmp.end(), arr[j].begin(), arr[j].end());
            T[i][j] = query(tmp) - S[i] - S[j], ans += T[i][j];
        }

    for (int i = 0; i < 6; i++)
        for (int j = i + 1; j < 6; j++)
            for (int k = j + 1; k < 6; k++) {
                tmp.clear();
                tmp.insert(tmp.end(), arr[i].begin(), arr[i].end());
                tmp.insert(tmp.end(), arr[j].begin(), arr[j].end());
                tmp.insert(tmp.end(), arr[k].begin(), arr[k].end());
                ans += query(tmp) - T[i][j] - T[j][k] - T[i][k] - S[i] - S[j] - S[k];
            }

    return ans;
}