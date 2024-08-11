#include <bits/stdc++.h>
#define int long long

#define MAX 300100
#define MOD 1000000007
#define INF 0x7f7f7f7f7f7f7f7f
#define endl '\n'

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

int N, A[MAX], P[MAX], in[MAX], out[MAX], dfs_order = 0;
bitset<MAX> cur;
vector<int> child[MAX];

void dfs(int K) {
    in[K] = ++dfs_order;
    for (int X : child[K])
        dfs(X);
    out[K] = dfs_order;
}

bool ifDfsOrder(int X) {
    if (X > N || X < 1)
        return false;
    if (X == 1 || P[X] == 1)
        return (X == 1) && (P[X] == 1);
    if (P[X - 1] == A[P[X]])
        return true;

    if (child[P[X - 1]].size() == 0 && in[A[P[X]]] <= in[P[X - 1]] && out[P[X - 1]] <= out[A[P[X]]])
        return true;
    return false;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int T, Q, X, Y, val;
    cin >> T;

    while (T--) {
        cin >> N >> Q;
        for (int i = 2; i <= N; i++) {
            cin >> A[i];
            child[A[i]].push_back(i);
        }

        for (int i = 1; i <= N; i++)
            cin >> P[i];

        dfs_order = 0;
        dfs(1);

        val = 0;
        for (int i = 1; i <= N; i++) {
            if (ifDfsOrder(i)) {
                cur[i] = 1;
                val++;
            }
        }

        while (Q--) {
            cin >> X >> Y;
            if (X > Y)
                swap(X, Y);

            if (X + 1 == Y) {
                if (cur[X] == 1)
                    cur[X] = 0, val--;
                if (cur[Y] == 1)
                    cur[Y] = 0, val--;
                if (cur[Y + 1] == 1)
                    cur[Y + 1] = 0, val--;

                swap(P[X], P[Y]);

                if (ifDfsOrder(X))
                    cur[X] = 1, val++;
                if (ifDfsOrder(Y))
                    cur[Y] = 1, val++;
                if (ifDfsOrder(Y + 1))
                    cur[Y + 1] = 1, val++;
            } else {
                if (cur[X] == 1)
                    cur[X] = 0, val--;
                if (cur[X + 1] == 1)
                    cur[X + 1] = 0, val--;
                if (cur[Y] == 1)
                    cur[Y] = 0, val--;
                if (cur[Y + 1] == 1)
                    cur[Y + 1] = 0, val--;

                swap(P[X], P[Y]);

                if (ifDfsOrder(X))
                    cur[X] = 1, val++;
                if (ifDfsOrder(X + 1))
                    cur[X + 1] = 1, val++;
                if (ifDfsOrder(Y))
                    cur[Y] = 1, val++;
                if (ifDfsOrder(Y + 1))
                    cur[Y + 1] = 1, val++;
            }

            cout << (val == N ? "YES" : "NO") << '\n';
        }

        for (int i = 0; i <= N; i++) {
            P[i] = A[i] = cur[i] = 0;
            child[i].clear();
        }
    }

    return 0;
}