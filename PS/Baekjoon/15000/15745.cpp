#include <bits/stdc++.h>
#define int long long

#define MAX 100100
#define MOD 1000000007
#define INF 0x7f7f7f7f7f7f7f7f
#define endl '\n'

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

int F[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    freopen("snowboots.in", "r", stdin);
    freopen("snowboots.out", "w", stdout);

    int N, B, X, Y, Z = 0;
    vector<pr> arr, res;
    vector<tp> queries;

    set<int> st;
    set<int>::iterator it;

    cin >> N >> B;

    for (int i = 1; i <= N; i++)
        cin >> F[i], arr.push_back({F[i], i}), st.insert(i);
    sort(arr.begin(), arr.end(), greater<pr>());

    for (pr i : arr) {
        if (i.first == 0)
            continue;
        it = st.lower_bound(i.second);
        Z = max(Z, *next(it) - *prev(it));
        st.erase(i.second);

        res.push_back({i.first, -Z});
    }
    sort(res.begin(), res.end());

    for (int i = 1; i <= B; i++) {
        cin >> X >> Y;
        Z = lower_bound(res.begin(), res.end(), pr{X, N + 1}) - res.begin();
        if (Z == res.size())
            Z = 0;
        else
            Z = -res[Z].second;
        cout << (Y >= Z) << '\n';
    }

    return 0;
}