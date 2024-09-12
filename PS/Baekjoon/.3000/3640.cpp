#include <bits/stdc++.h>
#define int long long

#define MAX 2010
#define MOD 1000000007
#define INF 0x7f7f7f7f7f7f7f7f
#define endl '\n'

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

int dp[MAX], parent[MAX];
bool checked[MAX];

vector<int> arr[MAX];
int source, sink, cap[MAX][MAX], flow[MAX][MAX], cost[MAX][MAX];

void add_path(int A, int B, int cst, int cap_size) {
    arr[A].push_back(B);
    arr[B].push_back(A);

    cost[A][B] = cst;
    cost[B][A] = -cst;

    cap[A][B] = cap_size;
    cap[B][A] = 0;

    flow[A][B] = 0;
    flow[B][A] = 0;
}

pr run_cost_flow() {
    queue<int> q;
    int val, money = 0, res = 0, A;

    while (true) {
        fill(checked, checked + sink + 1, false);
        fill(dp, dp + sink + 1, LLONG_MAX);
        fill(parent, parent + sink + 1, -1);

        dp[source] = 0;
        checked[source] = true;
        q.push(source);

        while (!q.empty()) {
            A = q.front();
            checked[A] = false;
            q.pop();

            for (int i : arr[A]) {
                if (cap[A][i] - flow[A][i] <= 0 || dp[A] + cost[A][i] >= dp[i])
                    continue;
                dp[i] = dp[A] + cost[A][i];
                parent[i] = A;
                if (!checked[i]) {
                    checked[i] = true;
                    q.push(i);
                }
            }
        }

        if (parent[sink] == -1)
            break;

        val = LLONG_MAX;
        for (int i = sink; i != source; i = parent[i])
            val = min(val, cap[parent[i]][i] - flow[parent[i]][i]);

        for (int i = sink; i != source; i = parent[i]) {
            money += val * cost[parent[i]][i];
            flow[parent[i]][i] += val;
            flow[i][parent[i]] -= val;
        }
        res += val;
    }
    return {res, money};
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int V, E, A, B, C;
    pr res;

    while (true) {
        cin >> V >> E;
        if (cin.eof())
            break;

        while (E--) {
            cin >> A >> B >> C;
            add_path(A * 2 - 1, B * 2, C, 1);
        }
        for (int i = 1; i <= V; i++)
            add_path(i * 2, i * 2 - 1, 0, 1);

        add_path(V * 2, V * 2 + 1, 0, 2);

        source = 1, sink = V * 2 + 1;
        res = run_cost_flow();

        cout << res.second << '\n';

        for (int i = 1; i <= V * 2 + 1; i++) {
            arr[i].clear();
            fill(cap[i], cap[i] + V * 2 + 2, 0);
            fill(flow[i], flow[i] + V * 2 + 2, 0);
            fill(cost[i], cost[i] + V * 2 + 2, 0);
        }
    }

    return 0;
}