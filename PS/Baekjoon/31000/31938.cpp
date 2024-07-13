#include <bits/stdc++.h>
#define int long long
#define MAX 200100

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

int V;
vector<pr> arr[MAX];
pr dis[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, M, A, B, C, res = 0;
    cin >> N >> M;

    while (M--) {
        cin >> A >> B >> C;
        arr[A].push_back({C, B});
        arr[B].push_back({C, A});
    }

    pr def = {LLONG_MAX, 0};
    fill(dis, dis + N + 1, def);

    priority_queue<pr, vector<pr>, greater<pr>> pq;
    pq.push({0, 1});
    dis[1] = {0, 0};

    while (!pq.empty()) {
        pr p = pq.top();
        pq.pop();

        if (dis[p.second].first != p.first)
            continue;

        for (pr i : arr[p.second]) {
            if ((int)i.first * 9 / 10 + p.first < dis[i.second].first) {
                dis[i.second] = {(int)i.first * 9 / 10 + p.first, (int)i.first / 10};
                pq.push({dis[i.second].first, i.second});
            } else if ((int)i.first * 9 / 10 + p.first == dis[i.second].first) {
                dis[i.second].second = min(dis[i.second].second, (int)i.first / 10);
            }
        }
    }

    for (int i = 1; i <= N; i++)
        res += dis[i].first + dis[i].second;
    cout << res;

    return 0;
}