#include "supertrees.h"
#include <bits/stdc++.h>
using namespace std;

typedef array<int, 2> pr;

const int MAX = 1000;

int uf[2][MAX];
vector<int> arr[2][MAX], val[MAX];

int find(int T, int X) { return X == uf[T][X] ? X : uf[T][X] = find(T, uf[T][X]); }
void uni(int T, int X, int Y) {
    X = find(T, X), Y = find(T, Y);
    if (X == Y)
        return;
    else if (X > Y)
        swap(X, Y);
    uf[T][Y] = X;
    while (!arr[T][Y].empty())
        arr[T][X].push_back(arr[T][Y].back()), arr[T][Y].pop_back();
}

int construct(vector<vector<int>> P) {
    int N = P.size();
    bool chk = true;

    vector<vector<int>> ans_vec;
    vector<pr> ans;
    ans_vec.resize(N, vector<int>(N, 0));

    for (int i = 0; i < 2; i++)
        for (int j = 0; j < N; j++)
            uf[i][j] = j, arr[i][j].push_back(j);

    for (int i = 0; i < N; i++)
        for (int j = i + 1; j < N; j++) {
            if (P[i][j] == 1 && find(0, i) != find(0, j))
                uni(0, i, j);
            else if (P[i][j] == 3)
                chk = false;
        }

    for (int i = 0; i < N; i++)
        for (int j = i + 1; j < N; j++)
            if (P[i][j] != 0 && find(1, i) != find(1, j))
                uni(1, i, j);

    for (int i = 0; i < N; i++)
        for (int j = i + 1; j < N; j++)
            if (P[i][j] == 0)
                chk &= find(1, i) != find(1, j);

    for (int i = 0; i < N; i++) {
        if (find(0, i) != i)
            continue;
        for (int j = 0; j + 1 < arr[0][i].size(); j++)
            ans.push_back({arr[0][i][j], arr[0][i][j + 1]});
        for (int j = 0; j < arr[0][i].size(); j++)
            for (int k = j + 1; k < arr[0][i].size(); k++)
                chk &= P[arr[0][i][j]][arr[0][i][k]] == 1;
        val[find(1, i)].push_back(arr[0][i][0]);
    }

    for (int i = 0; i < N; i++) {
        if (find(1, i) != i)
            continue;
        if (val[i].size() <= 1)
            continue;
        if (val[i].size() == 2)
            chk = false;
        for (int j = 0; j < val[i].size(); j++)
            ans.push_back({val[i][j], val[i][(j + 1) % val[i].size()]});
    }

    if (chk) {
        for (pr i : ans)
            ans_vec[i[0]][i[1]] = ans_vec[i[1]][i[0]] = 1;
        build(ans_vec);
        return 1;
    } else
        return 0;
}