#include <bits/stdc++.h>
#define int long long

#define MAX 110
#define MOD 1000000007
#define INF 0x7f7f7f7f7f7f7f7f
#define endl '\n'

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

int arr[MAX], sm[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, K, ans = -INF;
    cin >> N >> K;

    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
        sm[i] = sm[i - 1] + arr[i];
    }

    for (int i = K; i <= N; i++)
        ans = max(ans, sm[i] - sm[i - K]);

    cout << ans;

    return 0;
}