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

    int N, A, X, Y;
    vector<int> up, down, res;

    cin >> N;

    for (int i = 1; i <= N; i++) {
        cin >> A;
        if (A > 0)
            up.push_back(A);
        else
            down.push_back(-A);
    }

    sort(up.begin(), up.end());
    sort(down.begin(), down.end());

    for (int i = 0; i <= N; i++) {
        X = up.end() - lower_bound(up.begin(), up.end(), i + 1);
        Y = lower_bound(down.begin(), down.end(), i) - down.begin();
        if (X + Y == i)
            res.push_back(i);
    }

    cout << res.size() << '\n';
    for (int i : res)
        cout << i << ' ';

    return 0;
}