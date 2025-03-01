#include <bits/stdc++.h>
#define int long long

using namespace std;

const int MAX = 300000;

int A[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, K, X, cnt, st, en, md, ans;
    bool flag;

    vector<int> arr;

    cin >> N >> K;
    for (int i = 1; i <= N; i++) {
        cin >> A[i];
        if (A[i])
            arr.push_back(i);
    }

    st = 0, en = N;
    while (st <= en) {
        md = st + en >> 1, X = N, flag = false, cnt = 0;
        while (true) {
            if (++cnt > K)
                break;
            if (X - md <= 1) {
                flag = true;
                break;
            }
            X = *lower_bound(arr.begin(), arr.end(), X - md);
        }

        if (flag)
            ans = md, en = md - 1;
        else
            st = md + 1;
    }

    cout << ans << '\n';

    return 0;
}