#include <bits/stdc++.h>
#define int long long

using namespace std;

const int MAX = 200;

int A[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N;
    bool ans = false;

    cin >> N;
    for (int i = 1; i <= N; i++)
        cin >> A[i];

    for (int i = 1; i <= N - 2; i++)
        ans |= A[i] == A[i + 1] && A[i + 1] == A[i + 2];

    cout << (ans ? "Yes" : "No") << '\n';

    return 0;
}