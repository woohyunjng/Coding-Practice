#include <bits/stdc++.h>
#define int long long

using namespace std;
typedef pair<int, int> pr;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, M, K, T, X, Y, A, B, res;
    set<pr> st;
    set<pr>::iterator it, it1, it2;

    cin >> N >> M >> K;

    while (N--)
        cin >> X >> Y, st.insert({X, Y});

    while (M--) {
        cin >> T;
        if (T == 1)
            cin >> X >> Y, st.insert({X, Y});
        else if (T == 2) {
            cin >> X >> Y;
            it = st.lower_bound({X, 0x3f3f3f3f3f3f3f3f});
            if (it == st.begin()) {
                A = abs(it->first - X);
                if (A > K)
                    continue;
                st.insert({it->first, Y}), st.erase(it);
            } else if (it == st.end()) {
                it = prev(it);
                A = abs(it->first - X);
                if (A > K)
                    continue;

                st.insert({it->first, Y}), st.erase(it);
            } else {
                it1 = prev(it), it2 = it;
                A = abs(it1->first - X), B = abs(it2->first - X);
                if (A == B)
                    continue;
                else if (min(A, B) > K)
                    continue;
                else if (A < B)
                    st.insert({it1->first, Y}), st.erase(it1);
                else
                    st.insert({it2->first, Y}), st.erase(it2);
            }
        } else {
            cin >> X;
            it = st.lower_bound({X, 0x3f3f3f3f3f3f3f3f});
            if (it == st.begin()) {
                A = abs(it->first - X);
                if (A > K)
                    res = -1;
                else
                    res = it->second;
            } else if (it == st.end()) {
                it = prev(it);
                A = abs(it->first - X);
                if (A > K)
                    res = -1;
                else
                    res = it->second;
            } else {
                it1 = prev(it), it2 = it;
                A = abs(it1->first - X), B = abs(it2->first - X);
                if (min(A, B) > K)
                    res = -1;
                else if (A == B)
                    res = -2;
                else if (A < B)
                    res = it1->second;
                else
                    res = it2->second;
            }

            if (res == -2)
                cout << "?\n";
            else
                cout << res << '\n';
        }
    }

    return 0;
}