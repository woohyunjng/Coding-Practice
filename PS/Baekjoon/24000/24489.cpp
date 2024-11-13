#include <bits/stdc++.h>
#define int long long

#define MAX 200100
#define MOD 1000000007
#define INF 0x7f7f7f7f7f7f7f7f
#define endl '\n'

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

bool disabled_edge[MAX], group[MAX];
int parent[MAX], res[MAX];
pr edge[MAX], queries[MAX];

vector<int> child[MAX];

int find(int K) { return parent[K] == K ? K : parent[K] = find(parent[K]); }

void uni(int A, int B, int X) {
    A = find(A), B = find(B);
    if (A == B)
        return;
    if (A > B)
        swap(A, B);

    if (child[A].size() < child[B].size())
        swap(child[A], child[B]);

    for (int i : child[B])
        child[A].push_back(i);

    parent[B] = A;
    group[A] = group[A] || group[B];

    if (group[A]) {
        while (!child[A].empty())
            res[child[A].back()] = X, child[A].pop_back();
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, Q, A, B, M = 0, X, Y;
    char T;

    cin >> N >> Q;

    for (int i = 1; i <= N; i++) {
        parent[i] = i;
        child[i].push_back(i);
    }

    fill(group + 1, group + N + 1, true);

    for (int i = 1; i <= Q; i++) {
        cin >> T;
        if (T == 'A') {
            cin >> A >> B;
            edge[++M] = {A, B};
            queries[i] = {-1, -1};
        } else if (T == 'R') {
            cin >> A;
            disabled_edge[A] = true;
            queries[i] = {0, A};
        } else {
            cin >> A;
            group[A] = false;
            queries[i] = {1, A};
        }
    }

    for (int i = 1; i <= M; i++) {
        if (disabled_edge[i])
            continue;
        uni(edge[i].first, edge[i].second, Q);
    }

    for (int i = 1; i <= N; i++) {
        X = find(i);
        if (!group[X])
            continue;
        while (!child[X].empty())
            res[child[X].back()] = Q, child[X].pop_back();
    }

    for (int i = Q; i >= 1; i--) {
        if (queries[i].first == -1)
            continue;
        else if (queries[i].first == 0) {
            uni(edge[queries[i].second].first, edge[queries[i].second].second, i - 1);
        } else {
            X = find(queries[i].second);
            if (group[X])
                continue;
            group[X] = true;
            while (!child[X].empty())
                res[child[X].back()] = i - 1, child[X].pop_back();
        }
    }

    for (int i = 1; i <= N; i++)
        cout << res[i] << '\n';

    return 0;
}