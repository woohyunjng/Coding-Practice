#include <bits/stdc++.h>
#define int long long

#define MAX 200100
#define MOD 1000000007
#define INF 0x7f7f7f7f7f7f7f7f
#define endl '\n'

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

int sm[11], num[11];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int T, K, res = 0, X;
    string S;
    cin >> T;

    for (int i = 1; i < 11; i++) {
        for (int j = 0; j < i - 1; j++)
            sm[i] = sm[i] * 10 + 5;
        sm[i] += sm[i - 1], num[i] = num[i - 1] * 10 + 4;
    }

    while (T--) {
        cin >> S, K = S.size(), res = sm[K - 1];
        if (S[0] >= '5')
            res = sm[K];
        else if (S[0] == '4') {
            X = stoi(S);
            res += max(0ll, X - num[K - 1] * 10 - 4);
        }

        cout << res << '\n';
    }

    return 0;
}