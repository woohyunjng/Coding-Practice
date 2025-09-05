#include <bits/stdc++.h>
using namespace std;

const int MAX = 100001;

int L[MAX], R[MAX], uf[MAX];

int find(int X) { return uf[X] == X ? X : uf[X] = find(uf[X]); }
void uni(int X, int Y) {
    X = find(X), Y = find(Y);
    if (X == Y)
        return;
    else if (X > Y)
        swap(X, Y);
    uf[Y] = X;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, Q, X, Y;
    vector<int> arr;

    cin >> N >> Q;
    for (int i = 1; i <= N; i++) {
        cin >> L[i] >> R[i] >> X, uf[i] = i;
        arr.push_back(i);
    }

    sort(arr.begin(), arr.end(), [&](int A, int B) { return L[A] == L[B] ? R[A] < R[B] : L[A] < L[B]; });

    X = 0, R[0] = -1;
    for (int i : arr) {
        if (L[i] <= R[X])
            uni(i, X);
        if (R[i] > R[X])
            X = i;
    }

    while (Q--) {
        cin >> X >> Y;
        cout << (find(X) == find(Y)) << '\n';
    }

    return 0;
}