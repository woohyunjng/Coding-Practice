#include <bits/stdc++.h>
using namespace std;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, A, B;
    string S;

    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> S;
        if (S == "korea")
            A = i;
        else if (S == "yonsei")
            B = i;
    }

    cout << (A < B ? "Yonsei Lost..." : "Yonsei Won!") << '\n';

    return 0;
}