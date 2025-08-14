#include "findVertices.h"
#include <bits/stdc++.h>
using namespace std;

void find(int N) {
    vector<int> arr[2], edges[2], lst;
    int res[7] = {0}, A, B, X = 1, Y = 0;

    while (X * 2 <= N)
        X <<= 1, Y++;

    for (int i = 0; i <= Y; i++) {
        arr[0].clear(), arr[1].clear();
        edges[0].clear(), edges[1].clear();

        for (int j = 1; j <= N; j++)
            arr[(j & (1 << i)) >> i].push_back(j);

        for (int j = 0; j + 1 < arr[0].size(); j++)
            edges[0].push_back(arr[0][j]), edges[1].push_back(arr[0][j + 1]);
        for (int j = 0; j + 1 < arr[1].size(); j++)
            edges[0].push_back(arr[1][j]), edges[1].push_back(arr[1][j + 1]);
        res[i] = query(edges[0], edges[1], arr[0].back(), arr[1].back());
    }

    for (int i = 0; i <= Y; i++) {
        if (res[i] == 0)
            continue;
        A = 1 << i, B = 0;
        for (int j = 0; j <= Y; j++) {
            if (i == j)
                continue;
            arr[0].clear(), arr[1].clear();
            edges[0].clear(), edges[1].clear();

            if (res[j]) {
                for (int k = 1; k <= N; k++) {
                    if ((k & (1 << i)) && (k & (1 << j)))
                        arr[0].push_back(k);
                    else if (!(k & (1 << i)) && !(k & (1 << j)))
                        arr[1].push_back(k);
                }

                for (int k = 0; k + 1 < arr[0].size(); k++)
                    edges[0].push_back(arr[0][k]), edges[1].push_back(arr[0][k + 1]);
                for (int k = 0; k + 1 < arr[1].size(); k++)
                    edges[0].push_back(arr[1][k]), edges[1].push_back(arr[1][k + 1]);

                if (!arr[0].empty() && !arr[1].empty() && query(edges[0], edges[1], arr[0].back(), arr[1].back()))
                    A |= (1 << j);
                else
                    B |= (1 << j);
            } else {
                for (int k = 1; k <= N; k++) {
                    if ((k & (1 << i)) && (k & (1 << j)))
                        arr[0].push_back(k);
                    else if (!(k & (1 << i)) && (k & (1 << j)))
                        arr[1].push_back(k);
                }

                for (int k = 0; k + 1 < arr[0].size(); k++)
                    edges[0].push_back(arr[0][k]), edges[1].push_back(arr[0][k + 1]);
                for (int k = 0; k + 1 < arr[1].size(); k++)
                    edges[0].push_back(arr[1][k]), edges[1].push_back(arr[1][k + 1]);

                if (!arr[0].empty() && !arr[1].empty() && query(edges[0], edges[1], arr[0].back(), arr[1].back()))
                    A |= (1 << j), B |= (1 << j);
            }
        }
        answer(A, B);
        break;
    }
}