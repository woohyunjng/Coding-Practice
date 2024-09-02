#include <bits/stdc++.h>
#define int long long

#define MAX 3010
#define MOD 1000000007
#define INF 0x7f7f7f7f7f7f7f7f
#define endl '\n'

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

int arr[MAX], sm[MAX], dp[MAX][2];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, A, B, res = 0;
    cin >> N;

    for (int i = 1; i <= N; i++)
        cin >> arr[i];
    sort(arr + 1, arr + N + 1);

    for (int i = 1; i <= N; i++)
        sm[i] = sm[i - 1] + arr[i];

    cin >> A >> B;

    for (int i = 1; i <= N; i++) {
        dp[i][0] = sm[i] * A;
        dp[i][1] = B + (arr[i] * i - sm[i]) * A;

        for (int j = 1; j < i; j++) {
            dp[i][0] = min(dp[i][0], dp[j][1] + (sm[i] - sm[j] - arr[j] * (i - j)) * A);
            dp[i][1] = min(dp[i][1], min(dp[j][0], dp[j][1]) + B + (arr[i] * (i - j) - (sm[i] - sm[j])) * A);
        }
    }

    cout << min(dp[N][0], dp[N][1]);

    return 0;
}