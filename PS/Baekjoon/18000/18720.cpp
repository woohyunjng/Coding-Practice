#include <bits/stdc++.h>
#define int long long

#define MAX 200100
#define MOD 1000000007
#define INF 0x7f7f7f7f7f7f7f7f
#define endl '\n'

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

int arr[MAX], val[MAX], res[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int T, N, D, K, ans;
    priority_queue<int> pq;
    cin >> T;

    while (T--) {
        cin >> N >> D;

        for (int i = 1; i <= N; i++)
            cin >> arr[i];
        sort(arr + 1, arr + N + 1);

        for (int i = 1; i <= N; i++)
            arr[i] -= D * i;

        for (int i = 1; i <= N; i++) {
            if (!pq.empty())
                pq.pop();
            pq.push(arr[i]);
            pq.push(arr[i]);

            val[i] = pq.top();
        }

        val[N + 1] = INF;
        ans = 0;

        for (int i = N; i >= 1; i--) {
            if (val[i] > val[i + 1])
                val[i] = val[i + 1];
            res[i] = val[i] + D * i;
        }

        if (res[1] < 0)
            res[1] = 0;

        res[0] = -INF;
        for (int i = 1; i <= N; i++) {
            if (res[i] < res[i - 1] + D)
                res[i] = res[i - 1] + D;
            ans += abs(res[i] - arr[i] - D * i);
            cout << res[i] << ' ';
        }

        cout << ans << '\n';

        while (!pq.empty())
            pq.pop();
    }

    return 0;
}