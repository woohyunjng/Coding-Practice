#include <bits/stdc++.h>
using namespace std;

const int MAX = 60;

int M[MAX], V[MAX], rev[1000];

void dnc(int is, int ie, int ps, int pe) {
    if (is > ie || ps > pe)
        return;

    int X = M[is];

    dnc(is + 1, is + X - ps, ps, X - 1);
    dnc(is + X - ps + 1, ie, X + 1, pe);

    cout << (char)V[is];
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N;
    string A, B;

    cin >> A >> B, N = A.size();

    for (int i = 0; i < N; i++)
        V[i] = B[i], rev[B[i]] = i;
    for (int i = 0; i < N; i++)
        M[rev[A[i]]] = i;

    dnc(0, N - 1, 0, N - 1);
    cout << '\n';

    return 0;
}