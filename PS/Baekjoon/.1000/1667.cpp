#include <bits/stdc++.h>
#define int long long

#define MAX 200100
#define MOD 1000000007
#define INF 0x7f7f7f7f7f7f7f7f
#define endl '\n'

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, S, A, B, X, Y;

    set<pr> st;
    set<pr>::iterator it;

    cin >> N >> S;
    st.insert({S, 0});

    for (int i = 1; i <= N; i++) {
        cin >> A >> B;
        X = INF, Y = INF;

        it = st.lower_bound({A, -INF});
        if (it != st.end())
            X = min(X, it->second + abs(it->first - A));
        if (it != st.begin()) {
            it--;
            X = min(X, it->second + abs(it->first - A));
        }

        it = st.lower_bound({B, -INF});
        if (it != st.end())
            Y = min(Y, it->second + abs(it->first - B));
        if (it != st.begin()) {
            it--;
            Y = min(Y, it->second + abs(it->first - B));
        }

        st.erase(st.lower_bound({A, -INF}), st.lower_bound({B, INF}));
        st.insert({A, X});
        st.insert({B, Y});
    }

    it = st.lower_bound({0, -INF}), X = INF;
    if (it != st.end())
        X = min(X, it->second + abs(it->first));
    if (it != st.begin()) {
        it--;
        X = min(X, it->second + abs(it->first));
    }

    cout << X;

    return 0;
}