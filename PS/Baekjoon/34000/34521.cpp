#include <bits/stdc++.h>
using namespace std;

const int MAX = 1000001;

int ans[MAX];
bool chk[MAX << 1];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int T, N;

    for (int i = 1; i * i <= (MAX << 1); i++)
        chk[i * i] = true;

    cin >> T;
    while (T--) {
        cin >> N;
        for (int i = 1; i <= N; i++)
            ans[i] = i;

        for (int i = 1; i + 1 <= N; i++) {
            if (chk[ans[i] + ans[i + 1]]) {
                if (i + 2 <= N)
                    swap(ans[i + 1], ans[i + 2]);
                else
                    swap(ans[i], ans[i - 1]);
            }
        }

        for (int i = 1; i <= N; i++)
            cout << ans[i] << ' ';
        cout << '\n';
    }

    return 0;
}