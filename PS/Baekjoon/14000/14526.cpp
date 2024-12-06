#include <bits/stdc++.h>
#define int long long

#define MAX 200100
#define MOD 1000000007
#define INF 0x7f7f7f7f7f7f7f7f
#define endl '\n'

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

int st[MAX], en[MAX], A[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, res = 0;
    vector<int> vec;

    freopen("art2.in", "r", stdin);
    freopen("art2.out", "w", stdout);

    cin >> N;

    fill(st, st + N + 1, INF);

    st[0] = 0, en[0] = N + 1;
    for (int i = 1; i <= N; i++)
        cin >> A[i], st[A[i]] = min(st[A[i]], i), en[A[i]] = max(en[A[i]], i);

    for (int i = 0; i <= N + 1; i++) {
        if (st[A[i]] == i) {
            vec.push_back(A[i]);
            res = max(res, (int)vec.size());
        }

        if (vec.back() != A[i]) {
            cout << -1 << '\n';
            return 0;
        }

        if (en[A[i]] == i)
            vec.pop_back();
    }

    if (!vec.empty())
        res = 0;
    cout << res - 1 << '\n';

    return 0;
}