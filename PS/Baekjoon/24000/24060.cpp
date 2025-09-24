#include <bits/stdc++.h>
using namespace std;

const int MAX = 500001;

int A[MAX], T[MAX], K, ans = -1;

void merge_sort(int l, int r) {
    if (l >= r)
        return;
    int m = l + r >> 1, X, Y, Z;
    merge_sort(l, m), merge_sort(m + 1, r);

    for (X = l, Y = m + 1, Z = 1; X <= m && Y <= r; Z++) {
        if (A[X] <= A[Y])
            T[Z] = A[X++];
        else
            T[Z] = A[Y++];
    }
    while (X <= m)
        T[Z++] = A[X++];
    while (Y <= r)
        T[Z++] = A[Y++];
    X = l, Y = 1;
    while (X <= r) {
        A[X++] = T[Y++];
        if (--K == 0)
            ans = A[X - 1];
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N;

    cin >> N >> K;
    for (int i = 1; i <= N; i++)
        cin >> A[i];

    merge_sort(1, N);

    cout << ans << '\n';

    return 0;
}