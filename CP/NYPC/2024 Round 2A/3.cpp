#include <bits/stdc++.h>
#define int long long

#define MAX 100100
#define MOD 1000000007
#define INF 0x7f7f7f7f7f7f7f7f
#define endl '\n'

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

vector<tp> arr[MAX];
set<pr> dis[MAX];

int get_dis(int A, int B) {
    auto iter = dis[A].lower_bound({B, 0});
    if (iter == dis[A].end())
        return -1;
    return iter->second;
}

void insert(int A, int B, int C) {
    auto iter = dis[A].lower_bound({B, C});
    while (iter != dis[A].begin() && prev(iter)->second >= C)
        iter = dis[A].erase(prev(iter));
    dis[A].insert({B, C});
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, M, K, Q, A, B, C, D;
    tp X;
    cin >> N >> M >> K >> Q;

    while (M--) {
        cin >> A >> B >> C >> D;
        if (A == K)
            continue;
        arr[C].push_back({B, D, A});
    }

    for (int i = 1; i <= N; i++)
        sort(arr[i].begin(), arr[i].end());

    priority_queue<tp, vector<tp>, greater<tp>> pq;
    pq.push({INF, INF, K}); // 도착 시간, 시작 시간, 정점

    while (!pq.empty()) {
        X = pq.top(), pq.pop();

        for (tp i : arr[X[2]]) {
            A = get_dis(i[2], i[0]);
            if (i[1] <= X[1] && (A == -1 || A > X[0])) {
                if (X[2] == K) {
                    insert(i[2], i[0], i[1]);
                    pq.push({i[1], i[0], i[2]});
                } else {
                    insert(i[2], i[0], X[0]);
                    pq.push({X[0], i[0], i[2]});
                }
            }
        }
    }

    while (Q--) {
        cin >> A >> B;
        cout << get_dis(A, B) << '\n';
    }

    return 0;
}