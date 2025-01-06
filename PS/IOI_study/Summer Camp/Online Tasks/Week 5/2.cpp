#include <bits/stdc++.h>
#define int long long

#define MAX 200000
#define MOD 1000000007
#define INF 0x7f7f7f7f7f7f7f7f
#define endl '\n'

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

vector<pr> arr[MAX];
int edge[MAX][2], dis[MAX], parent[MAX], res[MAX];
bool vst[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, M, A, B;
    vector<int> used;
    cin >> N >> M;

    for (int i = 1; i <= M; i++) {
        cin >> A >> B;
        arr[A].push_back({B, i});
        edge[i][0] = A, edge[i][1] = B;
    }

    queue<int> q;
    fill(dis, dis + N + 1, -1);

    q.push(1);
    vst[1] = true, dis[1] = 0;

    while (!q.empty()) {
        A = q.front(), q.pop();

        for (pr i : arr[A]) {
            if (vst[i.first])
                continue;
            vst[i.first] = true;
            dis[i.first] = dis[A] + 1;
            parent[i.first] = i.second;
            q.push(i.first);
        }
    }

    for (int i = 1; i <= M; i++)
        res[i] = dis[N];

    A = N;
    while (A > 1) {
        used.push_back(parent[A]);
        A = edge[parent[A]][0];
    }

    for (int i : used) {
        fill(vst, vst + N + 1, false);
        fill(dis, dis + N + 1, -1);

        q.push(1);
        vst[1] = true, dis[1] = 0;

        while (!q.empty()) {
            A = q.front(), q.pop();

            for (pr j : arr[A]) {
                if (vst[j.first] || j.second == i)
                    continue;
                vst[j.first] = true;
                dis[j.first] = dis[A] + 1;
                parent[j.first] = j.second;
                q.push(j.first);
            }
        }

        res[i] = dis[N];
    }

    for (int i = 1; i <= M; i++)
        cout << res[i] << '\n';

    return 0;
}