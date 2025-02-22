#include <bits/stdc++.h>
#define int long long

using namespace std;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    string S;
    cin >> S;

    int X;

    int N = S.size();

    for (int i = 0; i + 1 < N; i++) {
        if (S[i] == 'W' && S[i + 1] == 'A') {
            S[i] = 'A', S[i + 1] = 'C';
            X = i;
            while (X > 0 && S[X - 1] == 'W')
                S[X] = 'C', S[--X] = 'A';
        }
    }

    cout << S << '\n';

    return 0;
}