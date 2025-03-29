#include <bits/stdc++.h>
#define int long long

#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2,fma")

using namespace std;

typedef array<int, 2> pr;
typedef array<int, 3> tp;

const int MAX_N = 6;
const int MAX = 100001;

const int INF = 0x3f3f3f3f3f3f3f3f;

pr go[4] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

int N, M, A[MAX_N][MAX], dis[MAX_N][MAX], ans[MAX], R1[MAX], R2[MAX], C1[MAX], C2[MAX];

void dnc(int l, int r, vector<int> arr) {
    if (l > r || arr.empty())
        return;

    priority_queue<tp, vector<tp>, greater<tp>> pq;
    tp K;

    int m = l + r >> 1, B, C, X, Y, Z;

    for (int i = 1; i <= N; i++) {
        for (int j = l; j <= r; j++)
            for (int k = 1; k <= N; k++)
                dis[k][j] = INF;

        pq.push({A[i][m], i, m}), dis[i][m] = A[i][m];

        while (!pq.empty()) {
            K = pq.top(), pq.pop();
            if (dis[K[1]][K[2]] < K[0])
                continue;

            for (pr j : go) {
                X = K[1] + j[0], Y = K[2] + j[1];
                if (X < 1 || X > N || Y < l || Y > r)
                    continue;

                if (dis[X][Y] > K[0] + A[X][Y]) {
                    dis[X][Y] = K[0] + A[X][Y];
                    pq.push({dis[X][Y], X, Y});
                }
            }
        }

        for (int j : arr)
            ans[j] = min(ans[j], dis[R1[j]][C1[j]] + dis[R2[j]][C2[j]] - A[i][m]);
    }

    vector<int> left, right;

    for (int i : arr) {
        if (C2[i] < m)
            left.push_back(i);
        else if (m < C1[i])
            right.push_back(i);
    }

    dnc(l, m - 1, left), dnc(m + 1, r, right);
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int Q;
    vector<int> arr;

    cin >> N >> M;
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= M; j++)
            cin >> A[i][j];

    cin >> Q;
    for (int i = 1; i <= Q; i++) {
        cin >> R1[i] >> C1[i] >> R2[i] >> C2[i], ans[i] = INF;
        if (C1[i] > C2[i])
            swap(R1[i], R2[i]), swap(C1[i], C2[i]);
        arr.push_back(i);
    }

    dnc(1, M, arr);

    for (int i = 1; i <= Q; i++)
        cout << ans[i] << '\n';

    return 0;
}