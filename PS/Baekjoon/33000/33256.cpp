#include <bits/stdc++.h>
using namespace std;

typedef array<int, 3> tp;

const int MAX = 200001;

int C[MAX], V[MAX], chk[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, X;
    vector<tp> ans;

    cin >> N;
    for (int i = 1; i <= N; i++)
        cin >> C[i];

    for (int i = 1; i <= N; i++) {
        X = i;
        while (!chk[X])
            chk[X] = i, X = C[X];
        if (chk[X] != i)
            continue;
        while (chk[X] != -i)
            V[C[C[X]]] = C[X], chk[X] = -i, X = C[X];
    }

    for (int i = 1; i <= N; i++) {
        if (V[C[i]] == 0)
            V[C[i]] = i;
        if (V[C[i]] != i)
            ans.push_back({2, V[C[i]], i}), C[i] = 0;
    }

    for (int i = 1; i <= N; i++) {
        while (C[i] != 0 && C[i] != i)
            ans.push_back({1, i, C[i]}), swap(C[i], C[C[i]]);
    }

    cout << ans.size() << '\n';
    for (tp i : ans)
        cout << i[0] << ' ' << i[1] << ' ' << i[2] << '\n';

    return 0;
}