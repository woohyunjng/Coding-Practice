#include <bits/stdc++.h>
#define int long long

using namespace std;
typedef array<int, 3> tp;

const int MAX = 200000;

int X[MAX], Y[MAX], parent[MAX];

int find(int X) { return parent[X] == X ? X : parent[X] = find(parent[X]); }
void uni(int X, int Y) {
    X = find(X), Y = find(Y);
    parent[max(X, Y)] = min(X, Y);
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int V, E, Q, L, R, ans;
    vector<int> prefix, suffix;

    cin >> V >> E;

    for (int i = 1; i <= E; i++)
        cin >> X[i] >> Y[i];

    for (int i = 1; i <= V; i++)
        parent[i] = i;
    for (int i = 1; i <= E; i++) {
        if (find(X[i]) == find(Y[i]))
            continue;
        prefix.push_back(i), uni(X[i], Y[i]);
    }

    for (int i = 1; i <= V; i++)
        parent[i] = i;
    for (int i = E; i >= 1; i--) {
        if (find(X[i]) == find(Y[i]))
            continue;
        suffix.push_back(i), uni(X[i], Y[i]);
    }

    cin >> Q;
    for (int i = 1; i <= Q; i++) {
        cin >> L >> R, ans = 0;
        for (int i = 1; i <= V; i++)
            parent[i] = i;

        for (int j : prefix) {
            if (j >= L)
                break;
            if (find(X[j]) == find(Y[j]))
                continue;
            uni(X[j], Y[j]);
        }

        for (int j : suffix) {
            if (j <= R)
                break;
            if (find(X[j]) == find(Y[j]))
                continue;
            uni(X[j], Y[j]);
        }

        for (int i = 1; i <= V; i++)
            ans += find(i) == i;
        cout << ans << '\n';
    }

    return 0;
}