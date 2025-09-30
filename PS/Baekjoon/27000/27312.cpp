#include <bits/stdc++.h>
using namespace std;

const int MAX = 1001;

int ans[MAX], A[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int M, N, Q, R;

    cin >> M >> N >> Q;
    for (int i = 1; i <= N; i++)
        cin >> A[i];

    for (int i = 1; i <= M; i++) {
        cout << "? " << i << ' ' << i << '\n', cout.flush();
        cin >> R, ans[i] = R % A[i] + 1;
    }

    for (int i = M + 1; i <= N; i++)
        ans[i] = 1;

    cout << "! ";
    for (int i = 1; i <= N; i++)
        cout << ans[i] << ' ';
    cout << '\n', cout.flush();

    return 0;
}