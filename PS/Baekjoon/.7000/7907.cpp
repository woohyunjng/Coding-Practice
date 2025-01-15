#include <bits/stdc++.h>
#define int long long

#define MAX 300000

using namespace std;
typedef array<int, 2> pr;

int X[MAX], Y[MAX], num[MAX][2], in[MAX][2], cnt;
bool st[MAX];
vector<pr> adj[MAX];

void dfs(int K, int M) {
    vector<int> V[2];
    int A;

    num[K][M] = cnt++;
    for (pr i : adj[K])
        if (--in[i[0]][M] == 0)
            V[i[1]].push_back(i[0]);

    for (int i : V[M])
        dfs(i, M);
    for (int i : V[!M])
        dfs(i, M);
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, M, K, A, B, cnt;
    bool res;

    deque<int> dq;
    cin >> N >> M >> K;

    for (int i = 1; i <= N; i++)
        cin >> X[i] >> Y[i];

    while (M--) {
        cin >> A >> B;
        if (X[A] == X[B]) {
            if (Y[A] < Y[B])
                swap(A, B);
            adj[A].push_back({B, 0});
        } else {
            if (X[A] > X[B])
                swap(A, B);
            adj[A].push_back({B, 1});
        }
        in[B][0]++, in[B][1]++;
    }

    for (int i = 1; i <= N; i++)
        st[i] = in[i][0] == 0;

    for (int i = 0; i < 2; i++) {
        cnt = 0;
        for (int j = 1; j <= N; j++)
            if (st[j])
                dfs(j, i);
    }

    while (K--) {
        cin >> A >> B;
        res = (num[A][0] - num[B][0]) * (num[A][1] - num[B][1]) > 0;
        cout << (res ? "TAK" : "NIE") << '\n';
    }

    return 0;
}