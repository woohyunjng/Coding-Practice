#include <bits/stdc++.h>
using namespace std;

const int MAX = 300001;

int S[MAX], A[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, ans = 0;
    string ST;

    cin >> N >> ST;
    for (int i = 1; i <= N; i++)
        A[i] = ST[i - 1] == 'P' ? 1 : -2, S[i] = S[i - 1] + A[i];

    ans |= A[1] == -2, ans |= A[N] == -2;
    for (int i = 1; i + 1 <= N; i++)
        ans |= A[i] == -2 && A[i + 1] == -2 & S[i] == 0;
    ans &= S[N] == 0;

    cout << (ans ? "YES" : "NO") << '\n';

    return 0;
}