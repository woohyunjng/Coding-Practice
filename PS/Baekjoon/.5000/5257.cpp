#include <bits/stdc++.h>
#define int long long

using namespace std;

typedef array<int, 2> pr;

const int MAX = 10001;

int N, M, U[MAX], V[MAX], T[MAX], C[MAX], ans_T = 1e9, ans_C = 1e9, uf[MAX];
vector<int> ans;

int gcd(int X, int Y) { return Y == 0 ? X : gcd(Y, X % Y); }

int find(int X) { return X == uf[X] ? X : uf[X] = find(uf[X]); }
void uni(int X, int Y) {
    X = find(X), Y = find(Y);
    uf[X] = Y;
}

pr mst(int X, int Y) {
    vector<int> arr, tre;
    for (int i = 0; i < M; i++)
        arr.push_back(i);
    for (int i = 0; i < N; i++)
        uf[i] = i;

    int ST = 0, SC = 0;
    sort(arr.begin(), arr.end(), [&](int x, int y) { return X * T[x] + Y * C[x] < X * T[y] + Y * C[y]; });

    for (int i : arr) {
        if (find(U[i]) == find(V[i]))
            continue;
        ST += T[i], SC += C[i], uni(U[i], V[i]);
        tre.push_back(i);
    }

    if (ST * SC < ans_T * ans_C)
        ans_T = ST, ans_C = SC, ans = tre;
    return {ST, SC};
}

void dnc(pr X, pr Y) {
    if (X == Y)
        return;

    int A = abs(X[1] - Y[1]), B = abs(X[0] - Y[0]), G = gcd(A, B);
    A /= G, B /= G;
    pr K = mst(A, B);

    if (K == X || K == Y)
        return;

    dnc(X, K), dnc(K, Y);
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> N >> M;
    for (int i = 0; i < M; i++)
        cin >> U[i] >> V[i] >> T[i] >> C[i];

    dnc(mst(1, 0), mst(0, 1));

    cout << ans_T << ' ' << ans_C << "\n\n";
    for (int i : ans)
        cout << U[i] << ' ' << V[i] << '\n';

    return 0;
}