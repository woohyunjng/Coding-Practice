#include <bits/stdc++.h>
#define int long long

#define MAX 200
using namespace std;

int A[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N;
    bool res = true;

    cin >> N;
    for (int i = 1; i <= N; i++)
        cin >> A[i];

    for (int i = 2; i + 1 <= N; i++)
        res &= A[i - 1] * A[i + 1] == A[i] * A[i];

    cout << (res ? "Yes" : "No") << '\n';

    return 0;
}