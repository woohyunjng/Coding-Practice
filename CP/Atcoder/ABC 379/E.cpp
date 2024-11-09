#include <bits/stdc++.h>
#define int long long

#define MAX 400100
#define MOD 1000000007
#define INF 0x7f7f7f7f7f7f7f7f
#define endl '\n'

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

int sm[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, X;
    string S;

    cin >> N >> S;
    reverse(S.begin(), S.end());

    for (int i = 0; i < N; i++) {
        sm[0] += (N - i) * (S[i] - '0');
        sm[i + 1] -= (N - i) * (S[i] - '0');
    }

    for (int i = 0; i < N; i++) {
        sm[i + 1] += sm[i];
    }

    for (int i = 0; sm[i]; i++) {
        sm[i + 1] += sm[i] / 10;
        sm[i] %= 10, X = i;
    }

    for (int i = X; i >= 0; i--)
        cout << sm[i];

    return 0;
}