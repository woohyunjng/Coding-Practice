#include <bits/stdc++.h>
#define int long long

#define MAX 100100
#define MOD 1000000007
#define INF 0x7f7f7f7f7f7f7f7f
#define endl '\n'

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

int arr[MAX][2], fr[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, M, res = 0, bef = INF;
    priority_queue<pr> pq;
    pr K;

    cin >> N >> M;

    for (int i = 1; i <= N; i++) {
        cin >> arr[i][0] >> arr[i][1];
        pq.push({arr[i][1], arr[i][0]});
    }

    for (int i = 1; i <= M; i++)
        cin >> fr[i];
    sort(fr + 1, fr + M + 1);

    for (int i = M; i >= 1; i--) {
        while (!pq.empty() && pq.top().second > fr[i])
            pq.pop();
        if (!pq.empty()) {
            pq.pop();
            res++;
        }
    }

    cout << res;

    return 0;
}