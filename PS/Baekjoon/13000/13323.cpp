#include <bits/stdc++.h>
#define int long long

#define MAX 1000100
#define MOD 1000000007
#define INF 0x7f7f7f7f7f7f7f7f
#define endl '\n'

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

int arr[MAX], val[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, res = 0;
    priority_queue<int> pq;
    cin >> N;

    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
        arr[i] -= i;
    }

    for (int i = 1; i <= N; i++) {
        if (!pq.empty())
            pq.pop();
        pq.push(arr[i]);
        pq.push(arr[i]);

        val[i] = pq.top();
    }

    val[N + 1] = INF;

    for (int i = N; i >= 1; i--) {
        if (val[i] > val[i + 1])
            val[i] = val[i + 1];
        res += abs(val[i] - arr[i]);
    }

    cout << res;

    return 0;
}