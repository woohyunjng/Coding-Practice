#include <bits/stdc++.h>
#define int long long

#define MAX 100100
#define MOD 1000000007
#define INF 0x7f7f7f7f7f7f7f7f
#define endl '\n'

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

int N, arr[MAX];

int get_sm(int K) {
    int res = 0;
    for (int i = 1; i <= N; i++)
        res += abs(arr[i] - K * (i - 1));
    return res;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int st, en, f_th, s_th, res = INF;
    cin >> N;

    for (int i = 1; i <= N; i++)
        cin >> arr[i];

    st = 0, en = arr[N];
    while (en - st > 2) {
        f_th = st + (en - st) / 3;
        s_th = en - (en - st) / 3;

        if (get_sm(f_th) < get_sm(s_th))
            en = s_th;
        else
            st = f_th;
    }

    for (int i = st; i <= en; i++)
        res = min(res, get_sm(i));

    cout << res;

    return 0;
}