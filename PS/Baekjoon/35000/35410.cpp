#include <bits/stdc++.h>
using namespace std;

const int MAX = 1001;

int T[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, S = 0;

    cin >> N;
    for (int i = 1; i <= N; i++)
        cin >> T[i];
    sort(T + 1, T + N + 1);

    for (int i = 1; i <= N; i++)
        S = T[i] <= S ? S + 1 : T[i] + 1;
    cout << S << '\n';

    return 0;
}