#include <bits/stdc++.h>
#define int long long

#define MAX 1000100
#define MOD 1000000007
#define INF 0x7f7f7f7f7f7f7f7f
#define endl '\n'

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

vector<pr> adj[MAX];
pr arr[MAX], before[MAX];
int parent[MAX], res[MAX];
bool cycle[MAX], checked[MAX], contain_cycle[MAX];

int find(int X) {
    if (parent[X] == X)
        return X;
    return parent[X] = find(parent[X]);
}

void no_cycle_dfs(int X) {
    checked[X] = true;

    for (pr i : adj[X]) {
        if (res[i.second] || contain_cycle[i.first])
            continue;
        res[i.second] = i.first;
        no_cycle_dfs(i.first);
    }
}

bool dfs(int X) {
    int K;
    checked[X] = true;

    for (pr i : adj[X]) {
        if (checked[i.first]) {
            if (i.second == before[X].second)
                continue;
            else {
                K = X;
                while (K != i.first) {
                    contain_cycle[K] = true;
                    res[before[K].second] = before[K].first;
                    K = before[K].first;
                }
                contain_cycle[i.first] = true;
                res[i.second] = X;

                K = X;
                while (K != i.first) {
                    no_cycle_dfs(K);
                    K = before[K].first;
                }
                no_cycle_dfs(i.first);

                return true;
            }
        } else {
            before[i.first] = {X, i.second};
            if (dfs(i.first))
                return true;
        }
    }

    return false;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, A, B;
    bool check = true;

    cin >> N;

    for (int i = 1; i <= N; i++)
        parent[i] = i;

    for (int i = 1; i <= N; i++) {
        cin >> A >> B;
        arr[i] = {A, B};

        adj[A].push_back({B, i});
        adj[B].push_back({A, i});

        A = find(A), B = find(B);
        if (A == B) {
            if (cycle[A])
                check = false;
            else
                cycle[A] = true;
        } else {
            if (A > B)
                swap(A, B);
            parent[B] = A;
            if (cycle[A] && cycle[B])
                check = false;
            cycle[A] |= cycle[B];
        }
    }

    if (!check) {
        cout << -1;
        return 0;
    }

    for (int i = 1; i <= 1000000; i++) {
        if (adj[i].empty() || checked[i])
            continue;

        if (cycle[find(i)]) {
            dfs(i);
        } else
            no_cycle_dfs(i);
    }

    for (int i = 1; i <= N; i++)
        cout << res[i] << '\n';

    return 0;
}