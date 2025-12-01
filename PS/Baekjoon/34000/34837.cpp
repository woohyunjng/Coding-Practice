#include <bits/stdc++.h>
#define int long long

using namespace std;

const int MAX = 300000;

vector<int> pos[30];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, M, ans = 0, X;
    string S, T;

    cin >> N >> M;
    cin >> S >> T;

    for (int i = 0; i < N; i++)
        pos[S[i] - 'a'].push_back(i);

    for (int i = 0; i < M; i++)
        ans += upper_bound(pos[T[i] - 'a'].begin(), pos[T[i] - 'a'].end(), N - (M - i)) - lower_bound(pos[T[i] - 'a'].begin(), pos[T[i] - 'a'].end(), i);

    cout << ans << '\n';

    return 0;
}