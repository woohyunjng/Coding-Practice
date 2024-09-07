#include <bits/stdc++.h>
#define int long long

#define MAX 200100
#define MOD 998244353
#define INF 0x7f7f7f7f7f7f7f7f
#define endl '\n'

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

int arr[MAX], sm[MAX], dp[MAX], dp_sm[MAX];
map<int, int> cnt;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, K;
    cin >> N >> K;

    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
        sm[i] = sm[i - 1] + arr[i];
    }

    dp[0] = 1;
    dp_sm[0] = 1;
    cnt[0] = 1;

    for (int i = 1; i <= N; i++) {
        dp[i] = (dp_sm[i - 1] - cnt[sm[i] - K] + MOD) % MOD;

        dp_sm[i] = (dp_sm[i - 1] + dp[i]) % MOD;
        cnt[sm[i]] = (cnt[sm[i]] + dp[i]) % MOD;
    }

    cout << dp[N];

    return 0;
}