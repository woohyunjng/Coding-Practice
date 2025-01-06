#include <bits/stdc++.h>
#define int long long

#define MAX 2100
using namespace std;
typedef array<int, 3> tp;

int a[MAX], b[MAX], parent[MAX * MAX];

int find(int X) { return parent[X] = parent[X] == X ? X : find(parent[X]); }
void uni(int X, int Y) {
    X = find(X), Y = find(Y);
    if (X > Y)
        swap(X, Y);
    if (X != Y)
        parent[Y] = X;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int A, B, N, M, res = 0;
    vector<tp> arr;

    cin >> A >> B >> N >> M;

    for (int i = 1; i <= N; i++)
        cin >> a[i];
    a[N + 1] = A;
    sort(a + 1, a + N + 2);

    for (int i = 1; i <= M; i++)
        cin >> b[i];
    b[M + 1] = B;
    sort(b + 1, b + M + 2);

    for (int i = 1; i <= N + 1; i++)
        for (int j = 1; j <= M + 1; j++)
            parent[(i - 1) * (M + 1) + j] = (i - 1) * (M + 1) + j;

    for (int i = 1; i <= N + 1; i++)
        for (int j = 1; j <= M; j++)
            arr.push_back({a[i] - a[i - 1], (i - 1) * (M + 1) + j, (i - 1) * (M + 1) + j + 1});

    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= M + 1; j++)
            arr.push_back({b[j] - b[j - 1], (i - 1) * (M + 1) + j, i * (M + 1) + j});

    sort(arr.begin(), arr.end());
    for (tp i : arr) {
        A = i[1], B = i[2];
        if (find(A) != find(B))
            uni(A, B), res += i[0];
    }
    cout << res << '\n';

    return 0;
}