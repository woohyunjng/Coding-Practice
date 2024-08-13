#include <bits/stdc++.h>
#define int long long

#define MAX 1100
#define MOD 1000000007
#define INF 0x7f7f7f7f7f7f7f7f
#define endl '\n'

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

vector<pr> arr[MAX];
priority_queue<int> kth[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, M, K, A, B, C;
    pr X;
    cin >> N >> M >> K;

    priority_queue<pr, vector<pr>, greater<pr>> pq;

    while (M--) {
        cin >> A >> B >> C;
        arr[A].push_back({C, B});
    }

    pq.push({0, 1});
    kth[1].push(0);

    while (!pq.empty()) {
        X = pq.top(), pq.pop();
        for (pr i : arr[X.second]) {
            if (kth[i.second].size() == K) {
                if (kth[i.second].top() > i.first + X.first) {
                    kth[i.second].pop();
                    kth[i.second].push(i.first + X.first);
                    pq.push({i.first + X.first, i.second});
                }
            } else {
                kth[i.second].push(i.first + X.first);
                pq.push({i.first + X.first, i.second});
            }
        }
    }

    for (int i = 1; i <= N; i++) {
        if (kth[i].size() < K)
            cout << -1 << '\n';
        else
            cout << kth[i].top() << '\n';
    }

    return 0;
}