#include <bits/stdc++.h>
#define int long long
using namespace std;

const int MAX = 100001;
const int INF = 0x3f3f3f3f3f3f3f3f;

int solve(vector<int> &arr, bool chk) {
    int N = arr.size(), X = 0, K = 0, ans = INF;
    bool flag;
    vector<int> tmp;

    if (N == 1) {
        ans = 0;
        for (int i = 1; i <= 9; i++) {
            if (!(arr[0] & (1 << i)))
                continue;
            ans = ans * 10 + i;
            if (ans == i && (arr[0] & 1))
                ans *= 10;
        }
        return (ans == 0 && (arr[0] & 1)) ? 10 : ans;
    }

    for (int i = 0; i < 9 + chk; i++) {
        tmp.clear(), X = 0, flag = false;
        for (int j = 0; j < N; j++) {
            K = (i + j) % 10, X |= (1023 ^ (1 << K)) & arr[j];
            flag |= (arr[j] & 1) && K == 0;
            if (K == 9 || j + 1 == N)
                tmp.push_back(X), X = 0;
        }
        X = solve(tmp, arr.size() >= 3 || i < 9) * 10 + i;
        if (X == 0 && flag)
            X = 10;
        ans = min(ans, X);
    }

    return ans;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, B;
    vector<int> arr;

    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> B, arr.push_back(1 << B);

    cout << solve(arr, true) << '\n';

    return 0;
}