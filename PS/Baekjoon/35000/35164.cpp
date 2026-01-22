#include <bits/stdc++.h>
using namespace std;

int V[100001];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, M, C[2] = {0, 0};

    cin >> N >> M;
    for (int i = 1; i <= M; i++)
        cin >> V[i], C[V[i]]++;

    if (N == 2) {
        if (C[0] > 0 && C[1] > 0)
            cout << -1 << '\n';
        else if (C[0] > 0) {
            cout << 1 << '\n';
            cout << 1 << ' ' << 1 << ' ' << 3 << '\n';
            cout << 1 << ' ' << 4 << ' ' << 5 << '\n';
            for (int i = 1; i <= M; i++)
                cout << 2 << ' ' << 1 << ' ' << 2 << '\n';
        } else {
            cout << 1 << '\n';
            cout << 1 << ' ' << 1 << ' ' << 3 << '\n';
            cout << 1 << ' ' << 0 << ' ' << 2 << '\n';
            for (int i = 1; i <= M; i++)
                cout << 2 << ' ' << 1 << ' ' << 2 << '\n';
        }
    } else {
        cout << 1 << '\n';
        cout << 1 << ' ' << 0 << ' ' << 2 << '\n';
        cout << 1 << ' ' << 1 << ' ' << 3 << '\n';
        cout << 1 << ' ' << 4 << ' ' << 5 << '\n';
        for (int i = 0; i < N - 3; i++)
            cout << 1 << ' ' << i + 10 << ' ' << i + 11 << '\n';

        for (int i = 1; i <= M; i++) {
            if (V[i] == 0)
                cout << 2 << ' ' << 2 << ' ' << 3 << '\n';
            else
                cout << 2 << ' ' << 1 << ' ' << 2 << '\n';
        }
    }

    return 0;
}