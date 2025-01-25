#include <bits/stdc++.h>

using namespace std;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int A[5];
    bool res = false, flag;

    for (int i = 0; i < 5; i++)
        cin >> A[i];

    for (int i = 0; i < 4; i++) {
        swap(A[i], A[i + 1]), flag = true;
        for (int j = 0; j < 5; j++)
            flag &= A[j] == j + 1;
        swap(A[i], A[i + 1]), res |= flag;
    }

    cout << (res ? "Yes" : "No") << '\n';

    return 0;
}