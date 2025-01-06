#include <bits/stdc++.h>
#define int long long

#define MAX 100100
#define MOD 1000000007
#define INF 0x7f7f7f7f7f7f7f7f
#define endl '\n'

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

int T[MAX], V[MAX], D;

int get_val(int X, int Y) { return (Y - X) * T[Y] + V[X]; }

int divide_and_conquer(int s, int e, int l, int r) {
    if (s > e)
        return 0;
    int mid = (s + e) / 2, res = 0, X = max(mid - D, l);

    for (int i = X; i <= min(mid, r); i++) {
        if (get_val(X, mid) < get_val(i, mid))
            X = i;
    }
    res = get_val(X, mid);

    res = max(res, divide_and_conquer(s, mid - 1, l, X));
    res = max(res, divide_and_conquer(mid + 1, e, X, r));

    return res;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, res;
    cin >> N >> D;

    for (int i = 1; i <= N; i++)
        cin >> T[i];

    for (int i = 1; i <= N; i++)
        cin >> V[i];

    res = divide_and_conquer(1, N, 1, N);
    cout << res;

    return 0;
}