#include <bits/stdc++.h>
#define int long long

#define MAX 100

using namespace std;
typedef array<int, 2> pr;

int S[MAX];

pr get(int k, int x, int y, int v) {
    if (v == 0)
        return {x, y};
    if (S[k] == 1)
        return get(k + 1, x + v, y + v, v / 2);
    else if (S[k] == 2)
        return get(k + 1, x, y + v, v / 2);
    else if (S[k] == 3)
        return get(k + 1, x, y, v / 2);
    else if (S[k] == 4)
        return get(k + 1, x + v, y, v / 2);
}

string get(int x, int y, int v) {
    if (v == 0)
        return "";
    if (x >= v && y >= v)
        return "1" + get(x - v, y - v, v / 2);
    else if (x < v && y >= v)
        return "2" + get(x, y - v, v / 2);
    else if (x < v && y < v)
        return "3" + get(x, y, v / 2);
    else
        return "4" + get(x - v, y, v / 2);
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int D, X, Y, A, B;
    pr K;
    string s, ans;

    cin >> D >> s >> X >> Y;

    for (int i = 1; i <= D; i++)
        S[i] = s[i - 1] - '0';

    K = get(1, 0, 0, 1ll << (D - 1));
    A = K[0], B = K[1];
    A += X, B += Y;

    if (A < 0 || A >= (1ll << D) || B < 0 || B >= (1ll << D)) {
        cout << -1 << '\n';
        return 0;
    }

    ans = get(A, B, 1ll << (D - 1));
    cout << ans << '\n';

    return 0;
}