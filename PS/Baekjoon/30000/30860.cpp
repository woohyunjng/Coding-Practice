#include <bits/stdc++.h>
using namespace std;

const int MAX = 1000001;

int L[MAX], M[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, V = 1'000'000'000, ans = 1;

    cin >> N;
    for (int i = 1; i <= N; i++)
        cin >> L[i] >> M[i];

    for (int i = N; i >= 1; i--) {
        if (V < L[i])
            ans++, V = M[i];
        else if (V > M[i])
            V = M[i];
    }

    cout << ans << '\n';

    return 0;
}