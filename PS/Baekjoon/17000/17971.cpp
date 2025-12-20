#include <bits/stdc++.h>
using namespace std;

typedef array<int, 2> pr;

const int MAX = 51;

int D[MAX][MAX], V[MAX], A[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N;
    vector<pr> arr, ans;

    cin >> N;
    for (int i = 1; i <= N; i++)
        V[i] = i;

    for (int i = 1; i < N; i++) {
        for (int j = 1;; j++) {
            cin >> D[i][j];
            if (D[i][j] == 0)
                break;
            arr.push_back({i, j});
        }
    }

    sort(arr.begin(), arr.end(), [&](pr x, pr y) { return D[x[0]][x[1]] < D[y[0]][y[1]]; });

    for (pr i : arr)
        swap(V[i[0]], V[i[0] + 1]);
    for (int i = 1; i <= N; i++)
        A[V[i]] = i, V[i] = i;

    for (pr i : arr) {
        if (A[V[i[0]]] < A[V[i[0] + 1]])
            continue;
        swap(V[i[0]], V[i[0] + 1]), ans.push_back(i);
    }

    cout << ans.size() << '\n';
    for (pr i : ans)
        cout << i[0] << ' ' << i[1] << '\n';

    return 0;
}