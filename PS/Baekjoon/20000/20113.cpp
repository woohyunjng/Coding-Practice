#include <bits/stdc++.h>
#define int long long

using namespace std;

const int MAX = 200;

int cnt[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, X, ans = 0, ans_cnt = 0;

    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> X;
        if (X)
            cnt[X]++;
    }

    for (int i = 1; i <= N; i++) {
        if (cnt[i] > ans_cnt)
            ans_cnt = cnt[i], ans = i;
        else if (cnt[i] == ans_cnt)
            ans = -1;
    }

    if (ans == -1)
        cout << "skipped" << '\n';
    else
        cout << ans << '\n';

    return 0;
}