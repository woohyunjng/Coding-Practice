#include <bits/stdc++.h>
#define int long long

#define MAX 200100
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

    int N, Q, X, Y, foul = 0;
    vector<int> dis;

    cin >> N;
    while (N--) {
        cin >> X >> Y;
        if (Y >= X && Y >= -X)
            dis.push_back(X * X + Y * Y);
        else
            foul++;
    }
    sort(dis.begin(), dis.end());

    cin >> Q;
    while (Q--) {
        cin >> X;
        Y = lower_bound(dis.begin(), dis.end(), X * X + 1) - dis.begin();
        cout << foul << ' ' << Y << ' ' << dis.size() - Y << '\n';
    }

    return 0;
}