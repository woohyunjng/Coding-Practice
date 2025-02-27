#include <bits/stdc++.h>
#define int long long

using namespace std;

const int MAX = 15000000;

int A[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, ans = 0;
    string S;

    cin >> N >> S;
    for (int i = 0; i < N; i++)
        A[i] = S[i] - '0';
    N--;

    while (N > 0) {
        if (A[N] == 0)
            N--;
        else {
            ans++;
            while (A[N] == 1)
                N--;
            A[N] = 1;
        }
    }

    cout << ans << '\n';

    return 0;
}