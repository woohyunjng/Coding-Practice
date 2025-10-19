#include <bits/stdc++.h>
using namespace std;

const int MAX = 100001;

int A[MAX], ans[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, L, R;

    cin >> N;
    for (int i = 1; i <= N; i++)
        cin >> A[i];
    sort(A + 1, A + N + 1);

    L = 1, R = N;
    for (int i = N; i >= 1; i--) {
        if ((N - i) & 1)
            ans[i] = A[L++];
        else
            ans[i] = A[R--];
    }

    for (int i = 1; i <= N; i++)
        cout << ans[i] << ' ';
    cout << '\n';

    return 0;
}