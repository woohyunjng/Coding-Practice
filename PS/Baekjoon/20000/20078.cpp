#include "train.h"
#include <bits/stdc++.h>
using namespace std;

const int MAX = 5001;

vector<int> adj[MAX], rev[MAX];
int in[MAX], cnt[MAX];
bool chk[MAX];

vector<int> who_wins(vector<int> A, vector<int> R, vector<int> U, vector<int> V) {
    int N = A.size(), M = U.size(), X;
    bool flag;
    vector<int> ans(N, 0);

    for (int i = 0; i < M; i++) {
        adj[U[i]].push_back(V[i]), rev[V[i]].push_back(U[i]);
        in[U[i]]++;
    }

    queue<int> q;

    while (true) {
        for (int i = 0; i < N; i++) {
            chk[i] = cnt[i] = 0;
            for (int j : adj[i])
                cnt[i] += R[j];
            if ((A[i] == 0 && cnt[i] == in[i]) || (A[i] == 1 && cnt[i]))
                q.push(i), chk[i] = true;
        }

        while (!q.empty()) {
            X = q.front(), q.pop();
            if (R[X])
                continue;
            for (int i : rev[X]) {
                cnt[i]++;
                if (chk[i])
                    continue;
                if ((A[i] == 0 && cnt[i] == in[i]) || (A[i] == 1 && cnt[i]))
                    q.push(i), chk[i] = true;
            }
        }

        flag = true;
        for (int i = 0; i < N; i++)
            if (R[i] && !chk[i])
                R[i] = 0, flag = false;
        if (flag)
            break;
    }

    for (int i = 0; i < N; i++)
        ans[i] = chk[i];
    return ans;
}
