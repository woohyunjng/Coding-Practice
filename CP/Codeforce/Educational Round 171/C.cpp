#include <bits/stdc++.h>
#define int long long

#define MAX 200100
#define MOD 1000000007
#define INF 0x7f7f7f7f7f7f7f7f
#define endl '\n'

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

void solve() {
    int N, res = 0, X = 0, Y;
    string S;

    vector<int> zero, one;

    cin >> N >> S;

    for (int i = 1; i <= N; i++) {
        if (S[i - 1] == '0')
            zero.push_back(i);
        else
            one.push_back(i);
    }

    for (int i = N; i >= 1; i--) {
        if (S[i - 1] == '0') {
            if (!zero.empty() && zero.back() == i)
                res += i, zero.pop_back();
            continue;
        }

        if (!zero.empty())
            res += zero.back(), zero.pop_back();
        else {
            if (one[X] > i)
                break;
            res += one[X++];
        }
    }

    cout << res << '\n';
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int T, N;
    cin >> T;

    while (T--)
        solve();

    return 0;
}