#include <bits/stdc++.h>
#define int long long

using namespace std;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int A[3];
    bool ans = false;

    cin >> A[0] >> A[1] >> A[2];
    ans |= A[0] * A[1] == A[2];
    ans |= A[1] * A[2] == A[0];
    ans |= A[2] * A[0] == A[1];

    cout << (ans ? "Yes" : "No") << '\n';

    return 0;
}