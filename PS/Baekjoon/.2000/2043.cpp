#include <bits/stdc++.h>
#define int long long
#define MAX 1000

using namespace std;
typedef pair<int, int> pr;

vector<int> arr[MAX];
pr go[4] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
int cap[MAX][MAX], flow[MAX][MAX], cost[MAX][MAX], dp[MAX], parent[MAX], board[MAX][MAX];
bool checked[MAX];

int convert(int A, int B, int K) { return (A - 1) * K + B; }

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

int minimum_cost_flow(int start, int end) {
    queue<int> q;
    int val, res = LLONG_MAX, money = 0, A;

    while (true) {
        fill(checked, checked + end + 1, false);
        fill(dp, dp + end + 1, LLONG_MAX);
        fill(parent, parent + end + 1, -1);

        dp[start] = 0;
        checked[start] = true;
        q.push(start);

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

        if (parent[end] == -1)
            break;

        val = LLONG_MAX;
        for (int i = end; i != start; i = parent[i])
            val = min(val, cap[parent[i]][i] - flow[parent[i]][i]);

        for (int i = end; i != start; i = parent[i]) {
            money += val * cost[parent[i]][i];
            flow[parent[i]][i] += val;
            flow[i][parent[i]] -= val;
        }
        res = min(res, money);
    }
    return res;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, M, K, T;
    cin >> N >> M >> T;
    K = N * M + 1;

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            cin >> board[i][j];
            if ((i + j) & 1)
                add_path(convert(i, j, M), K, 0, 1);
            else
                add_path(0, convert(i, j, M), 0, 1);
        }
    }

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            if ((i + j) & 1)
                continue;
            for (pr k : go) {
                int x = i + k.first, y = j + k.second;
                if (x <= 0 || x > N || y <= 0 || y > M)
                    continue;
                if (abs(board[x][y] - board[i][j]) > T)
                    continue;
                add_path(convert(i, j, M), convert(x, y, M), -abs(board[x][y] - board[i][j]), 1);
            }
        }
    }
    int res = minimum_cost_flow(0, K);
    cout << -res;

    return 0;
}