#include <bits/stdc++.h>
#define int long long

#define MAX 200100
#define MOD 1000000007
#define INF 0x7f7f7f7f7f7f7f7f
#define endl '\n'

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

map<pr, int> dp;

int divide_and_conquer(int X, int Y) {
    if (dp.count({X, Y}))
        return dp[{X, Y}];

    if (X == 0 && Y == 0)
        return 0;

    int A = 0, B = 0, x = X + 1, y = Y + 1, res;

    while (x) {
        A++;
        x >>= 1;
    }
    while (y) {
        B++;
        y >>= 1;
    }

    A--, B--;

    if (A == B)
        res = divide_and_conquer(X - (1ll << A) + 1, Y - (1ll << B) + 1) + A;
    else {
        res = divide_and_conquer(X - (1ll << A) + 1, (1ll << A) - 1) + A;
        for (int i = A + 1; i < B; i++)
            res = max(res, divide_and_conquer(0, (1ll << i) - 1) + i);
        res = max(res, divide_and_conquer(0, Y - (1ll << B) + 1) + B);
    }
    return dp[{X, Y}] = res;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int X, Y, T;
    cin >> T;

    while (T--) {
        cin >> X >> Y;
        cout << divide_and_conquer(X, Y) << '\n';
    }

    return 0;
}