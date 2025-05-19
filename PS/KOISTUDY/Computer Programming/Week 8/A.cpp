#include <bits/stdc++.h>
#define int long long

using namespace std;

const int MAX = 100001;

int A[MAX], S[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, Q, L, R;

    cin >> N >> Q;
    for (int i = 1; i <= N; i++)
        cin >> A[i], S[i] = S[i - 1] + A[i];

    while (Q--) {
        cin >> L >> R;
        cout << S[R] - S[L - 1] << '\n';
    }

    return 0;
}