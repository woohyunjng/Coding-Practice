#include <bits/stdc++.h>
using namespace std;

typedef array<int, 3> tp;

const int MAX = 200001;

int uf[MAX];

int find(int X) { return X == uf[X] ? X : uf[X] = find(uf[X]); }
void uni(int X, int Y) {
    X = find(X), Y = find(Y);
    if (X != Y)
        uf[max(X, Y)] = min(X, Y);
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, M, U, V, C, ans;
    vector<tp> arr;

    while (true) {
        cin >> N >> M, arr.clear(), ans = 0;
        if (!N && !M)
            break;

        for (int i = 1; i <= N; i++)
            uf[i] = i;

        while (M--)
            cin >> U >> V >> C, arr.push_back({C, U, V}), ans += C;

        sort(arr.begin(), arr.end());
        for (tp i : arr) {
            if (find(i[1]) != find(i[2]))
                ans -= i[0], uni(i[1], i[2]);
        }

        cout << ans << '\n';
    }

    return 0;
}