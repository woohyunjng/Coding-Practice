#include <bits/stdc++.h>
#define int long long

#define MAX 300000
using namespace std;

typedef array<int, 2> pr;
typedef array<int, 3> tp;

int ans[MAX], in[MAX], val[MAX];
vector<pr> adj[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, M, X, Y;
    char C;

    vector<tp> arr;
    queue<int> q;

    for (int i = 1; i <= 40; i++)
        for (int j = 1; j <= 40; j++)
            for (int k = 1; k <= 40; k++)
                arr.push_back({i, j, k});

    cin >> N >> M;

    for (int i = 1; i <= M; i++) {
        cin >> X >> Y, in[Y]++;
        adj[X].push_back({Y, i});
    }

    X = 0;
    for (int i = 1; i <= N; i++)
        if (!in[i])
            q.push(i);

    while (!q.empty()) {
        Y = q.front(), q.pop(), val[Y] = X++;
        for (pr i : adj[Y])
            if (--in[i[0]] == 0)
                q.push(i[0]);
    }

    for (int i = 1; i <= N; i++) {
        for (pr j : adj[i]) {
            if (arr[val[i]][0] < arr[val[j[0]]][0])
                ans[j[1]] = 1;
            else if (arr[val[i]][1] < arr[val[j[0]]][1])
                ans[j[1]] = 2;
            else
                ans[j[1]] = 3;
        }
    }

    for (int i = 1; i <= M; i++) {
        if (ans[i] == 1)
            C = 'R';
        else if (ans[i] == 2)
            C = 'G';
        else
            C = 'B';
        cout << C << '\n';
    }

    return 0;
}