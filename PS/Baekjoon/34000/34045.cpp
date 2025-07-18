#include <bits/stdc++.h>
using namespace std;

const int MAX = 300001;

int A[MAX], B[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N;
    bool ans = true;

    cin >> N;
    for (int i = 1; i <= N; i++)
        cin >> A[i];
    for (int i = 1; i <= N; i++)
        cin >> B[i];

    for (int i = 1; i <= N; i++) {
        if (A[i] == B[i] || B[i] == i)
            continue;
        while (A[i] != B[i] && A[A[i]] != A[i])
            swap(A[i], A[A[i]]);
    }

    for (int i = 1; i <= N; i++) {
        if (A[i] == B[i])
            continue;
        while (A[i] != B[i] && A[A[i]] != A[i])
            swap(A[i], A[A[i]]);
    }

    for (int i = 1; i <= N; i++)
        ans &= A[i] == B[i];

    cout << (ans ? "YES" : "NO") << '\n';

    return 0;
}
