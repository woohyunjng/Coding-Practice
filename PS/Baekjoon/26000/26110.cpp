#include <bits/stdc++.h>
using namespace std;

const int MAX = 100001;

int A[MAX];

int chk(int l, int r, int k) {
    if (l > r || k > 3)
        return k;
    else if (A[l] == A[r])
        return chk(l + 1, r - 1, k);
    else
        return min(chk(l + 1, r, k + 1), chk(l, r - 1, k + 1));
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, ans;
    string S;

    cin >> S, N = S.size();
    for (int i = 1; i <= N; i++)
        A[i] = S[i - 1] - 'a' + 1;

    ans = chk(1, N, 0), ans = ans > 3 ? -1 : ans;
    cout << ans << '\n';

    return 0;
}