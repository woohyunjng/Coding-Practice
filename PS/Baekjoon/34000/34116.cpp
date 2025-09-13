#include <bits/stdc++.h>
using namespace std;

const int MAX = 1e9;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, X, Y, A[2] = {MAX, -MAX}, B[2] = {MAX, -MAX}, C[2] = {MAX, -MAX};

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> X >> Y;
        A[0] = min(A[0], X + Y), A[1] = max(A[1], X + Y);
        B[0] = min(B[0], Y - X), B[1] = max(B[1], Y - X);
        C[0] = min(C[0], Y), C[1] = max(C[1], Y);
    }

    cout << min((A[1] - C[0]) - (C[0] - B[1]), ((C[1] - B[0]) - (A[0] - C[1]))) << '\n';

    return 0;
}