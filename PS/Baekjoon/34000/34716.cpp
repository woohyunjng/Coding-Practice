#include <bits/stdc++.h>
using namespace std;

typedef array<int, 2> pr;

const int MAX = 200001;

int H[MAX], V[MAX], ans[MAX],
    uf[MAX], M[MAX], S[MAX], G[MAX];
bool chk[MAX];

deque<pr> arr[MAX];

int find(int X) { return uf[X] == X ? X : uf[X] = find(uf[X]); }
void uni(int X, int Y) {
    int A, B;

    X = find(X), Y = find(Y);
    A = arr[X].back()[0], B = arr[X].back()[1];

    while (!arr[X].empty() && arr[X].back()[1] <= M[Y] && arr[X].back()[1] < M[X])
        G[X] -= (A - arr[X].back()[0]) * B, A = arr[X].back()[0], B = arr[X].back()[1], arr[X].pop_back();
    G[X] -= (A - arr[X].back()[0]) * B;

    A = arr[Y].front()[0], B = arr[Y].front()[1];
    while (!arr[Y].empty() && arr[Y].front()[1] <= M[X] && arr[Y].front()[1] < M[Y])
        G[Y] -= (arr[Y].front()[0] - A) * B, A = arr[Y].front()[0], B = arr[Y].front()[1], arr[Y].pop_front();
    G[Y] -= (arr[Y].front()[0] - A) * B;

    G[X] += (arr[Y].front()[0] - arr[X].back()[0] - 1) * min(arr[X].back()[1], arr[Y].front()[1]);

    if (arr[X].size() < arr[Y].size()) {
        while (!arr[X].empty())
            arr[Y].push_front(arr[X].back()), arr[X].pop_back();
        swap(arr[X], arr[Y]);
    } else
        while (!arr[Y].empty())
            arr[X].push_back(arr[Y].front()), arr[Y].pop_front();

    G[X] += G[Y], S[X] += S[Y], M[X] = max(M[X], M[Y]), uf[Y] = X;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, Q, val = 0;

    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> H[i], G[i] = S[i] = M[i] = H[i];
        uf[i] = i, chk[i] = true;
        arr[i].push_back({i, H[i]});
    }

    cin >> Q;
    for (int i = 1; i <= Q; i++)
        cin >> V[i], chk[V[i]] = false;

    for (int i = 1; i + 1 <= N; i++) {
        if (!chk[i] || !chk[i + 1])
            continue;
        val -= G[find(i)] - S[find(i)], val -= G[find(i + 1)] - S[find(i + 1)];
        uni(i, i + 1), val += G[find(i)] - S[find(i)];
    }

    for (int i = Q; i >= 1; i--) {
        chk[V[i]] = true, ans[i] = val;
        for (int j = -1; j <= 1; j += 2) {
            if (V[i] + j < 1 || V[i] + j > N || !chk[V[i] + j])
                continue;
            val -= G[find(V[i])] - S[find(V[i])], val -= G[find(V[i] + j)] - S[find(V[i] + j)];
            uni(min(V[i], V[i] + j), max(V[i], V[i] + j)), val += G[find(V[i])] - S[find(V[i])];
        }
    }

    cout << val << '\n';
    for (int i = 1; i <= Q; i++)
        cout << ans[i] << '\n';

    return 0;
}