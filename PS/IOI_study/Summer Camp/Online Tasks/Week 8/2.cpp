#include <bits/stdc++.h>
#define int long long

#define MAX 400100
using namespace std;
typedef pair<int, int> pr;

int A[MAX], B[MAX], parent[MAX], sz[MAX];
bool cycle[MAX], chk[MAX];

int find(int X) { return parent[X] == X ? X : parent[X] = find(parent[X]); }

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, X, Y, res = 0;
    vector<pr> arr;

    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> A[i] >> B[i];
        sz[A[i]] = 1, sz[B[i]] = 1;
    }

    for (int i = 1; i <= 2 * N; i++)
        parent[i] = i;

    for (int i = 1; i <= N; i++) {
        X = find(A[i]), Y = find(B[i]);
        if (X > Y)
            swap(X, Y);
        if (X == Y)
            cycle[X] = true;
        else
            parent[Y] = X, sz[X] += sz[Y], cycle[X] |= cycle[Y];
    }

    for (int i = 1; i <= 2 * N; i++) {
        X = find(i);
        if (chk[X] || sz[X] == 0)
            continue;
        chk[X] = true;
        if (cycle[X])
            res += sz[X];
        else
            res += sz[X] - 1;
    }

    cout << res << '\n';

    return 0;
}