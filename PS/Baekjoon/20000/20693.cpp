#include <bits/stdc++.h>
#define int long long

using namespace std;

const int MAX = 400001;

int V[MAX][3], par[MAX], sz[MAX], edge[MAX], D[MAX];
bool vst[MAX];

vector<int> oadj[MAX], adj[MAX];
map<int, int> mp;

int find(int X) { return par[X] == X ? X : par[X] = find(par[X]); }
void uni(int X, int Y) {
    X = find(X), Y = find(Y);
    if (X == Y) {
        edge[X]++;
        return;
    }
    if (X > Y)
        swap(X, Y);
    par[Y] = X, sz[X] += sz[Y], edge[X] += edge[Y] + 1;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, M = 0, A, C, T, S, X, val, ans = 0;
    bool flag;

    queue<int> q;
    vector<int> arr;

    cin >> A >> C >> T;

    for (int i = 1; i <= A; i++) {
        cin >> S;
        while (S--) {
            cin >> X;
            oadj[i].push_back(A + T + X);
        }
    }

    for (int i = 1; i <= A; i++) {
        cin >> S;
        while (S--) {
            cin >> X;
            oadj[A + X].push_back(i);
        }
    }

    for (int i = 1; i <= C; i++) {
        cin >> S;
        while (S--) {
            cin >> X;
            oadj[A + T + i].push_back(A + X);
        }
    }

    N = A + T + C;

    for (int i = 1; i <= A; i++) {
        for (int j : oadj[i])
            for (int k : oadj[j])
                for (int l : oadj[k]) {
                    if (i != l)
                        continue;
                    par[M] = ++M, sz[M] = 1;
                    V[M][0] = i, V[M][1] = j, V[M][2] = k;
                    for (int x = 0; x < 3; x++) {
                        if (mp.find(MAX * V[M][x] + V[M][(x + 1) % 3]) == mp.end())
                            mp[MAX * V[M][x] + V[M][(x + 1) % 3]] = M;
                        else {
                            X = mp[MAX * V[M][x] + V[M][(x + 1) % 3]];
                            adj[X].push_back(M), adj[M].push_back(X);
                            uni(X, M);
                        }
                    }
                }
    }

    for (int i = 1; i <= M; i++) {
        if (find(i) != i)
            continue;
        vst[i] = true, X = find(i), arr.clear();
        if (sz[X] > 8) {
            if (edge[X] == sz[X])
                ans += sz[X] / 2;
            else
                ans += (sz[X] + 1) / 2;
            continue;
        }

        q.push(i);
        while (!q.empty()) {
            C = q.front(), q.pop();
            D[C] = arr.size(), arr.push_back(C);

            for (int j : adj[C]) {
                if (vst[j])
                    continue;
                vst[j] = true, q.push(j);
            }
        }

        A = arr.size(), val = 0;
        for (int j = 0; j < (1 << A); j++) {
            flag = true;
            for (int k = 0; k < A; k++) {
                if (!(j & (1 << k)))
                    continue;
                for (int l : adj[arr[k]])
                    flag &= !(j & (1 << D[l]));
            }
            if (flag)
                val = max(val, (int)__builtin_popcountll(j));
        }
        ans += val;
    }

    cout << ans << '\n';

    return 0;
}