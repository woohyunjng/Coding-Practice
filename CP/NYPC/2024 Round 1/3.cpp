#include <bits/stdc++.h>
#define int long long

#define MAX 500100
#define MOD 1000000007
#define INF 0x7f7f7f7f7f7f7f7f
#define endl '\n'

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

int arr[MAX], dp[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N;
    cin >> N;

    for (int i = 1; i <= N; i++)
        cin >> arr[i];

    dp[1] = arr[1];
    for (int i = 2; i <= N; i++)
        dp[i] = min(dp[i - 1] + arr[i], dp[i - 2] + max(arr[i - 1], arr[i]));

    cout << dp[N];

    return 0;
}