#include <bits/stdc++.h>
#define int long long

#define MAX 20010
#define MOD 1000000007
#define INF 0x7f7f7f7f7f7f7f7f
#define endl '\n'

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

int N, arr[MAX][3];

int get_numbers(int X) {
    int res = 0;
    for (int i = 1; i <= N; i++) {
        if (arr[i][0] + arr[i][1] * arr[i][2] <= X)
            res += arr[i][2] + 1;
        else if (arr[i][0] <= X)
            res += (X - arr[i][0]) / arr[i][1] + 1;
    }
    return res;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int st = 0, en = 1ll << 32, md;
    cin >> N;

    for (int i = 1; i <= N; i++) {
        cin >> arr[i][0] >> arr[i][2] >> arr[i][1];
        arr[i][2] = (arr[i][2] - arr[i][0]) / arr[i][1];
    }

    while (st <= en) {
        md = st + en >> 1;
        if (get_numbers(md) & 1)
            en = md - 1;
        else
            st = md + 1;
    }

    if (st > 1ll << 32)
        cout << "NOTHING";
    else
        cout << st << ' ' << get_numbers(st) - get_numbers(st - 1);

    return 0;
}