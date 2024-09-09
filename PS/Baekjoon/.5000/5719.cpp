#include <bits/stdc++.h>
#define int long long

#define MAX 10100
#define MOD 1000000007
#define INF 0x7f7f7f7f7f7f7f7f
#define endl '\n'

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

vector<tp> arr[MAX], rev_arr[MAX];
int dis[MAX];
bool checked_edge[MAX], checked[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, M, S, D, A, B, C;
    pr K;
    priority_queue<pr, vector<pr>, greater<pr>> pq;
    queue<int> q;

    while (true) {
        cin >> N >> M;
        if (!N)
            break;
        cin >> S >> D;

        for (int i = 1; i <= M; i++) {
            cin >> A >> B >> C;
            arr[A].push_back({C, B, i});
            rev_arr[B].push_back({C, A, i});
        }

        fill(dis, dis + N, INF);
        dis[S] = 0;
        pq.push({0, S});

        while (!pq.empty()) {
            K = pq.top(), pq.pop();
            if (dis[K.second] < K.first)
                continue;

            for (tp i : arr[K.second]) {
                if (dis[i[1]] > K.first + i[0]) {
                    dis[i[1]] = K.first + i[0];
                    pq.push({dis[i[1]], i[1]});
                }
            }
        }

        fill(checked_edge, checked_edge + M + 1, true);
        fill(checked, checked + N, false);
        q.push(D);

        while (!q.empty()) {
            A = q.front(), q.pop();

            for (tp i : rev_arr[A]) {
                if (dis[A] == dis[i[1]] + i[0]) {
                    checked_edge[i[2]] = false;
                    if (!checked[i[1]]) {
                        checked[i[1]] = true;
                        q.push(i[1]);
                    }
                }
            }
        }

        fill(dis, dis + N, INF);
        dis[S] = 0;
        pq.push({0, S});

        while (!pq.empty()) {
            K = pq.top(), pq.pop();
            if (dis[K.second] < K.first)
                continue;

            for (tp i : arr[K.second]) {
                if (dis[i[1]] > K.first + i[0] && checked_edge[i[2]]) {
                    dis[i[1]] = K.first + i[0];
                    pq.push({dis[i[1]], i[1]});
                }
            }
        }

        cout << (dis[D] < INF ? dis[D] : -1) << '\n';

        for (int i = 0; i < N; i++)
            arr[i].clear(), rev_arr[i].clear();
    }

    return 0;
}