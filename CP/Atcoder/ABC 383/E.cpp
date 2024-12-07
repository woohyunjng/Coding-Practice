#include <bits/stdc++.h>
#define int long long

#define MAX 200100
#define MOD 1000000007
#define INF 0x7f7f7f7f7f7f7f7f
#define endl '\n'

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

int parent[MAX];
vector<int> A[MAX], B[MAX];

int find(int X) { return parent[X] == X ? X : parent[X] = find(parent[X]); }

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, M, K, X, Y, Z, res = 0;
    vector<tp> adj;
    cin >> N >> M >> K;

    for (int i = 1; i <= N; i++)
        parent[i] = i;

    while (M--) {
        cin >> X >> Y >> Z;
        adj.push_back({Z, X, Y});
    }
    sort(adj.begin(), adj.end());

    for (int i = 1; i <= K; i++)
        cin >> X, A[X].push_back(X);
    for (int i = 1; i <= K; i++)
        cin >> X, B[X].push_back(X);

    for (tp i : adj) {
        X = find(i[1]), Y = find(i[2]), Z = i[0];
        if (X == Y)
            continue;

        if (X > Y)
            swap(X, Y);
        parent[Y] = X;

        if (A[X].size() < A[Y].size())
            swap(A[X], A[Y]);
        while (!A[Y].empty())
            A[X].push_back(A[Y].back()), A[Y].pop_back();

        if (B[X].size() < B[Y].size())
            swap(B[X], B[Y]);
        while (!B[Y].empty())
            B[X].push_back(B[Y].back()), B[Y].pop_back();

        Y = min(A[X].size(), B[X].size());
        res += Z * Y;

        for (int j = 0; j < Y; j++)
            A[X].pop_back();
        for (int j = 0; j < Y; j++)
            B[X].pop_back();
    }

    cout << res << '\n';

    return 0;
}