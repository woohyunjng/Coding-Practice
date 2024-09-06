#include <bits/stdc++.h>
#define int long long

#define MAX 200100
#define MOD 1000000007
#define INF 0x7f7f7f7f7f7f7f7f
#define endl '\n'

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, val = 0;
    string S, res;
    char before;

    cin >> N;
    cin >> S;

    before = S[0], val = 1;

    for (int i = 1; i < N; i++) {
        if (before == S[i])
            val++;
        else {
            res += to_string(val) + before;
            before = S[i], val = 1;
        }
    }

    res += to_string(val) + before;

    cout << res;

    return 0;
}