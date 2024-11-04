#include <bits/stdc++.h>
#define int long long
#define double long double

#define MAX 2010
#define MOD 1000000007
#define INF 0x7f7f7f7f7f7f7f7f
#define endl '\n'

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

int H[MAX];

set<pair<double, int>> st[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, Q, res = 0, X, Y;
    double val;
    multiset<pair<double, int>>::iterator it;

    cin >> N;

    for (int i = 1; i <= N; i++)
        cin >> H[i];

    for (int i = 1; i <= N; i++) {
        for (int j = i + 1; j <= N; j++) {
            val = (double)(H[j] - H[i]) / (j - i);
            if (st[i].empty() || prev(st[i].end())->first <= val)
                st[i].insert({val, j}), res++;
        }
    }

    cin >> Q;
    while (Q--) {
        cin >> X >> Y;
        res -= st[X].size(), H[X] += Y;
        st[X].clear();

        for (int i = X + 1; i <= N; i++) {
            val = (double)(H[i] - H[X]) / (i - X);
            if (st[X].empty() || prev(st[X].end())->first <= val)
                st[X].insert({val, i}), res++;
        }

        for (int i = 1; i < X; i++) {
            it = st[i].lower_bound({(double)(H[X] - H[i]) / (X - i), X});
            if (it != st[i].end() && it->second < X)
                continue;

            if (it != st[i].begin())
                it--;

            while (it->second >= X) {
                res--;
                if (it == st[i].begin()) {
                    st[i].erase(it);
                    break;
                }
                st[i].erase(it--);
            }

            st[i].insert({(double)(H[X] - H[i]) / (X - i), X});
            res++;
        }

        cout << res << '\n';
    }

    return 0;
}