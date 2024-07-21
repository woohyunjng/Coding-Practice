#include <bits/stdc++.h>
#define int long long
#define MAX 30010
#define MOD 100003

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

int arr[MAX], dp_before[MAX], dp[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, Q, A;
    cin >> N;

    for (int i = 1; i <= N; i++)
        cin >> arr[i];

    for (int i = 1; i <= N; i++) {
        dp[1] = (dp_before[1] + arr[i]) % MOD;
        for (int j = 2; j <= i; j++) {
            dp[j] = (dp_before[j] + dp_before[j - 1] * arr[i]) % MOD;
        }

        for (int j = 1; j <= i; j++) {
            dp_before[j] = dp[j];
        }
    }

    cin >> Q;
    while (Q--) {
        cin >> A;
        cout << dp[A] << '\n';
    }

    return 0;
}