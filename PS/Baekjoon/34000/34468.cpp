#include <bits/stdc++.h>
#define int long long

using namespace std;

const int MAX = 200001;

int V[MAX], C[MAX], P[MAX], ans;
multiset<int> st[MAX], val, sec;

void clear(int X) {
    if (V[X] == 0)
        return;
    sec.erase(sec.find(*st[X].rbegin())), val.erase(val.find(V[X]));
    ans -= V[X], st[X].insert(V[X]), V[X] = 0;
}

void update(int X) {
    V[X] = *st[X].rbegin(), val.insert(V[X]), ans += V[X];
    st[X].erase(prev(st[X].end())), sec.insert(*st[X].rbegin());
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, M, Q, T, X, Y;

    cin >> N >> M >> Q;
    for (int i = 1; i <= N; i++)
        cin >> C[i] >> P[i], st[C[i]].insert(P[i]);

    for (int i = 1; i <= M; i++)
        st[i].insert(0), update(i);

    cout << ans + max(0ll, *sec.rbegin() - *val.begin()) << '\n';

    while (Q--) {
        cin >> T >> X >> Y;
        if (T == 1) {
            clear(C[X]), clear(Y);
            st[C[X]].erase(st[C[X]].find(P[X])), st[Y].insert(P[X]);
            update(C[X]), update(Y), C[X] = Y;
        } else {
            clear(C[X]), st[C[X]].erase(st[C[X]].find(P[X])), P[X] = Y;
            st[C[X]].insert(P[X]), update(C[X]);
        }

        cout << ans + max(0ll, *sec.rbegin() - *val.begin()) << '\n';
    }

    return 0;
}