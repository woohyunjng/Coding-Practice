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

    string S, res = "";
    int N, i = 0, cnt;

    cin >> S;
    N = S.size();

    while (i < N) {
        cnt = 0;
        while (i < N && '0' <= S[i] && S[i] <= '9') {
            cnt = cnt * 10 + S[i] - '0';
            i++;
        }

        res += string(cnt, S[i]);
        i++;
    }

    cout << res;

    return 0;
}