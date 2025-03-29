#include <bits/stdc++.h>

#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#define int long long

using namespace std;

const int MAX = 1001000;
const int BIT = 31;

int A[MAX], cnt[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, cnt_zero = 0, ans;
    bool flag;
    cin >> N;

    for (int i = 1; i <= N; i++)
        cin >> A[i], cnt_zero += A[i] == 0;

    if (cnt_zero > 0)
        ans = N - cnt_zero;
    else {
        ans = N + 1;
        for (int i = 1, j = 1; i <= N; i++) {
            for (int k = 0; k < BIT; k++)
                if (!(A[i] & (1 << k)))
                    cnt[k]++;

            while (true) {
                flag = true;
                for (int k = 0; k < BIT; k++)
                    if (!(A[j] & (1 << k)))
                        flag &= cnt[k] > 1;
                if (!flag)
                    break;
                for (int k = 0; k < BIT; k++)
                    if (!(A[j] & (1 << k)))
                        cnt[k]--;
                j++;
            }

            flag = true;
            for (int k = 0; k < BIT; k++)
                flag &= cnt[k] > 0;
            if (flag)
                ans = min(ans, i - j);
        }

        if (ans == N + 1)
            ans = -1;
        else
            ans = N + ans - 1;
    }

    cout << ans << '\n';

    return 0;
}
