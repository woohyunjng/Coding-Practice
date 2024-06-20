#include <bits/stdc++.h>
#define MAX 1000
#define int long long

using namespace std;
typedef pair<int, int> pr;

int uf_parent[MAX];
set<int> S[MAX];

void clear(int K, bool set_clear = true) {
    for (int i = 1; i <= K; i++) {
        uf_parent[i] = i;
        if (set_clear) {
            S[i].clear();
            S[i].insert(i);
        }
    }
}

int find(int K) {
    if (uf_parent[K] != K)
        uf_parent[K] = find(uf_parent[K]);
    return uf_parent[K];
}

void uni(int A, int B) {
    A = find(A), B = find(B);
    if (A > B)
        swap(A, B);
    uf_parent[B] = A;

    if (S[A].size() < S[B].size())
        swap(S[A], S[B]);
    for (int i : S[B])
        S[A].insert(i);
}