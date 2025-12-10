#include <bits/stdc++.h>
using namespace std;

const int MAX = 100002;

int C[MAX][2], V[MAX][2], uf[MAX], L[MAX];
vector<int> arr[MAX], adj[MAX];

int find(int X) { return X == uf[X] ? X : uf[X] = find(uf[X]); }
void uni(int X, int Y) {
    X = find(X), Y = find(Y);
    if (X != Y)
        uf[max(X, Y)] = min(X, Y);
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, M, S, X, Y, ans = -1;
    vector<int> comp;

    cin >> N >> M, comp.push_back(0);
    for (int i = 1; i <= N; i++)
        cin >> L[i], comp.push_back(L[i]);

    sort(comp.begin(), comp.end()), comp.erase(unique(comp.begin(), comp.end()), comp.end()), S = (int)comp.size() - 1;
    for (int i = 1; i <= N; i++) {
        L[i] = (int)(lower_bound(comp.begin(), comp.end(), L[i]) - comp.begin());
        arr[L[i]].push_back(i);
    }

    while (M--) {
        cin >> X >> Y;
        adj[X].push_back(Y), adj[Y].push_back(X);
    }

    for (int i = 1; i <= N; i++)
        uf[i] = i;
    for (int i = 1; i <= S; i++) {
        C[i][0] = C[i - 1][0], V[i][0] = V[i - 1][0];
        for (int j : arr[i]) {
            V[i][0]++, C[i][0]++;
            for (int k : adj[j]) {
                if (L[k] > i)
                    continue;
                if (find(j) != find(k))
                    uni(j, k), C[i][0]--;
            }
        }
    }

    for (int i = 1; i <= N; i++)
        uf[i] = i;
    for (int i = S; i >= 1; i--) {
        C[i][1] = C[i + 1][1], V[i][1] = V[i + 1][1];
        for (int j : arr[i]) {
            V[i][1]++, C[i][1]++;
            for (int k : adj[j]) {
                if (L[k] < i)
                    continue;
                if (find(j) != find(k))
                    uni(j, k), C[i][1]--;
            }
        }
    }

    for (int i = 1; i < S; i++) {
        if (C[i][0] + C[i + 1][1] - 1 <= min(V[i][0], V[i + 1][1])) {
            cout << comp[i] << '\n';
            return 0;
        }
    }

    cout << -1 << '\n';
    return 0;
}