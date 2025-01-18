#include <bits/stdc++.h>
#define int long long

#define MAX 300100
using namespace std;

int sm[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int Q, T, K, A = 0, B = 0;
    vector<int> arr;

    cin >> Q;

    while (Q--) {
        cin >> T;
        if (T == 1) {
            cin >> K, sm[B + 1] = sm[B] + K, B++;
        } else if (T == 2)
            A++;
        else {
            cin >> K;
            cout << sm[A + K - 1] - sm[A] << '\n';
        }
    }

    return 0;
}