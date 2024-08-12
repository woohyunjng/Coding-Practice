#include <bits/stdc++.h>
#define int long long

#define MAX 140
#define MOD 1000000007
#define DEF 10000
#define INF 0x7f7f7f7f7f7f7f7f
#define endl '\n'

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

int arr[MAX], dp[MAX][50];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N;
    cin >> N;

    for (int i = 1; i <= N; i++)
        cin >> arr[i];

    dp[1][arr[1]] = 1;
    for (int i = 2; i < N; i++) {
        for (int j = 0; j <= 20; j++) {
            if (dp[i - 1][j]) {
                if (j + arr[i] <= 20)
                    dp[i][j + arr[i]] += dp[i - 1][j];
                if (j - arr[i] >= 0)
                    dp[i][j - arr[i]] += dp[i - 1][j];
            }
        }
    }

    cout << dp[N - 1][arr[N]] << endl;

    return 0;
}