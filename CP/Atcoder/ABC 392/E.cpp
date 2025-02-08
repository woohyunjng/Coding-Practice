#include <bits/stdc++.h>
#define int long long

#define MAX 300000

using namespace std;
typedef array<int, 2> pr;
typedef array<int, 3> tp;

int parent[MAX];
vector<tp> edge[MAX];

int find(int X) { return parent[X] = parent[X] == X ? X : find(parent[X]); }
void uni(int X, int Y) {
    X = find(X), Y = find(Y);
    if (X != Y)
        parent[max(X, Y)] = min(X, Y);
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, M, X, Y;
    pr A, B;
    tp K;

    vector<tp> ans, lft;
    priority_queue<pr> pq;

    cin >> N >> M;
    for (int i = 1; i <= N; i++)
        parent[i] = i;

    for (int i = 1; i <= M; i++) {
        cin >> X >> Y;
        if (find(X) != find(Y))
            uni(X, Y);
        else
            lft.push_back({X, Y, i});
    }

    for (tp i : lft)
        edge[find(i[0])].push_back(i);

    for (int i = 1; i <= N; i++) {
        if (find(i) != i)
            continue;
        pq.push({(int)edge[i].size(), i});
    }

    while (pq.size() > 1) {
        A = pq.top(), pq.pop();
        B = pq.top(), pq.pop();

        K = edge[A[1]].back(), edge[A[1]].pop_back();
        ans.push_back({K[2], K[1], B[1]});

        while (!edge[B[1]].empty())
            edge[A[1]].push_back(edge[B[1]].back()), edge[B[1]].pop_back();
        pq.push({(int)edge[A[1]].size(), A[1]});
    }

    cout << ans.size() << '\n';
    for (tp i : ans)
        cout << i[0] << ' ' << i[1] << ' ' << i[2] << '\n';

    return 0;
}