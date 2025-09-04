#include <bits/stdc++.h>
#define int long long
using namespace std;

const int MAX = 100001;
const int BUCKET = 300;

int parent[MAX], sz[MAX], A[MAX], B[MAX], L[MAX], R[MAX], ans[MAX], val;
vector<int> rollback_st, arr[MAX];

int find(int X) { return parent[X] == X ? X : find(parent[X]); }
bool uni(int X, int Y) {
    X = find(X), Y = find(Y);
    if (X == Y)
        return false;
    if (sz[X] < sz[Y])
        swap(X, Y);
    rollback_st.push_back(Y);
    val -= sz[X] * (sz[X] - 1) / 2 + sz[Y] * (sz[Y] - 1) / 2;
    sz[X] += sz[Y], parent[Y] = X;
    val += sz[X] * (sz[X] - 1) / 2;
    return true;
}

void rollback() {
    int K = rollback_st.back();
    rollback_st.pop_back();
    val -= sz[parent[K]] * (sz[parent[K]] - 1) / 2;
    sz[parent[K]] -= sz[K];
    val += sz[K] * (sz[K] - 1) / 2 + sz[parent[K]] * (sz[parent[K]] - 1) / 2;
    parent[K] = K;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, M, Q, X, cnt = 0;

    cin >> N >> M >> Q;
    for (int i = 0; i < M; i++)
        cin >> A[i] >> B[i];

    for (int i = 1; i <= N; i++)
        parent[i] = i, sz[i] = 1;

    for (int i = 1; i <= Q; i++) {
        cin >> L[i] >> R[i], L[i]--, R[i]--;
        arr[L[i] / BUCKET].push_back(i);
    }

    for (int i = 0; i * BUCKET < M; i++) {
        sort(arr[i].begin(), arr[i].end(), [](int a, int b) { return R[a] < R[b]; }), X = (i + 1) * BUCKET;
        for (int j : arr[i]) {
            if (R[j] / BUCKET == i) {
                for (int k = L[j]; k <= R[j]; k++)
                    uni(A[k], B[k]);
                ans[j] = val;
                while (!rollback_st.empty())
                    rollback();
            } else {
                while (X <= R[j])
                    uni(A[X], B[X]), X++;
                for (int k = (i + 1) * BUCKET - 1; k >= L[j]; k--)
                    cnt += uni(A[k], B[k]);
                ans[j] = val;
                while (cnt--)
                    rollback();
                cnt = 0;
            }
        }

        while (!rollback_st.empty())
            rollback();
    }

    for (int i = 1; i <= Q; i++)
        cout << ans[i] << '\n';

    return 0;
}