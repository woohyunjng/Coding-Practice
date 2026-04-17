#include <bits/stdc++.h>
#define int long long

using namespace std;

const int MAX = 101;

int A[MAX], ans[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N;

    cin >> N;
    for (int i = 1; i <= N; i++)
        cin >> A[i];

    sort(A + 1, A + N + 1);

    for (int i = 1; i <= (N + 1) / 2; i++)
        ans[i * 2 - 1] = A[(N + 1) / 2 - i + 1];

    for (int i = 1; i <= N / 2; i++)
        ans[i * 2] = A[(N + 1) / 2 + i];

    for (int i = 1; i <= N; i++)
        cout << ans[i] << ' ';
    cout << '\n';

    return 0;
}