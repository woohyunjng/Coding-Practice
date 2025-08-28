#include "liar.h"
#include <bits/stdc++.h>

using namespace std;

vector<int> game(int K, int N) {
    vector<int> arr, val;
    for (int i = 1; i <= N; i++)
        arr.push_back(i);

    int V;
    bool flag;

    while (arr.size() > (1 << K)) {
        flag = false, V = 0;
        for (int i = 0; i <= K && !flag; i++)
            flag |= ask({arr[1 << K]});
        if (!flag) {
            arr.erase(arr.begin() + (1 << K));
            continue;
        }

        for (int i = 0; i < K; i++) {
            for (int j = 0; j < (1 << K); j++)
                if (j & (1 << i))
                    val.push_back(arr[j]);
            if (!ask(val))
                V |= 1 << i;
            val.clear();
        }
        arr.erase(arr.begin() + V), V = 0;
    }

    return arr;
}