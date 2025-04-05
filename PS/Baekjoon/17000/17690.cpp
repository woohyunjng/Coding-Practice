#include "library.h"
#include <bits/stdc++.h>
using namespace std;

vector<int> ans;
bool chk[1001];

int N;

int query(vector<int> &Q) {
    int cnt = accumulate(Q.begin(), Q.end(), 0);
    return cnt - Query(Q);
}

int get(int X, vector<int> arr) {
    int S = arr.size(), A, B;
    if (S == 1)
        return arr[0];

    vector<int> L, R, T(N, 0);
    for (int i = 0; i < S / 2; i++)
        L.push_back(arr[i]), T[arr[i]] = 1;
    for (int i = S / 2; i < S; i++)
        R.push_back(arr[i]);

    A = query(T), T[X] = 1, B = query(T);
    if (B - A == 1)
        return get(X, L);
    else
        return get(X, R);
}

void Solve(int n) {
    N = n;
    vector<int> Q(N, 1);

    if (N == 1) {
        ans.push_back(1);
        Answer(ans);
        return;
    }

    for (int i = 0; i < N; i++) {
        Q[i] = 0;
        if (query(Q) == N - 2) {
            ans.push_back(i), chk[i] = true;
            break;
        }
        Q[i] = 1;
    }

    for (int i = 1; i < N; i++) {
        Q.clear();
        for (int j = 0; j < N; j++) {
            if (chk[j])
                continue;
            Q.push_back(j);
        }
        ans.push_back(get(ans[i - 1], Q)), chk[ans[i]] = true;
    }

    for (int i = 0; i < N; i++)
        ans[i]++;
    Answer(ans);
}