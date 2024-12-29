#include <bits/stdc++.h>
#define int long long

#define MAX 100100
using namespace std;

map<string, int> cnt;
string arr[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, st, en, mid, res = -1;
    bool flag;

    cin >> N;
    for (int i = 1; i <= N; i++)
        cin >> arr[i];

    st = 5, en = N;
    while (st <= en) {
        mid = st + en >> 1, flag = false, cnt.clear();
        for (int i = 1; i <= mid; i++)
            flag = flag || (++cnt[arr[i]] == 5);

        for (int i = mid + 1; i <= N; i++) {
            --cnt[arr[i - mid]];
            flag = flag || (++cnt[arr[i]] == 5);
        }

        if (!flag)
            st = mid + 1;
        else
            en = mid - 1, res = mid;
    }

    cout << res << '\n';

    return 0;
}