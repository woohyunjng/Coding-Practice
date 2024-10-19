#include <bits/stdc++.h>
#define int long long

#define MAX 100100
#define MOD 1000000007
#define INF 0x7f7f7f7f7f7f7f7f
#define endl '\n'

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

int C[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, L, res = 0, st, en, md, cnt = 0, X;
    bool check;
    cin >> N >> L;

    for (int i = 1; i <= N; i++)
        cin >> C[i];

    st = 0, en = N;
    while (st <= en) {
        md = st + en >> 1, check = true;
        cnt = 0, X = L;

        for (int i = 1; i <= N; i++) {
            if (C[i] >= md)
                cnt++;
            else if (C[i] == md - 1 && X > 0)
                X--, cnt++;
        }

        if (cnt >= md)
            res = md, st = md + 1;
        else
            en = md - 1;
    }

    cout << res;

    return 0;
}