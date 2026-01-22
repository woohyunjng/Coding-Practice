#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, M, X[6] = {0, 0, 0, 0};
    string S;

    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        cin >> S;
        for (int j = 0; j < M; j++) {
            if (S[j] == '#')
                X[0]++;
            else if (S[j] == 'U' || S[j] == 'D' || S[j] == 'L' || S[j] == 'R')
                X[1]++;
            else if (S[j] == 'A')
                X[2]++;
            else if (S[j] == 'V')
                X[3]++;
            else if (S[j] == 'S')
                X[4]++;
            else if (S[j] == 'E')
                X[5]++;
        }
    }

    if (X[4] != 1 || X[5] != 1)
        cout << -1 << '\n';
    else if (X[2] > 0)
        cout << 4 << '\n';
    else if (X[3] > 0)
        cout << 3 << '\n';
    else if (X[0] > 1 || X[1] > 1)
        cout << 2 << '\n';
    else
        cout << 1 << '\n';

    return 0;
}