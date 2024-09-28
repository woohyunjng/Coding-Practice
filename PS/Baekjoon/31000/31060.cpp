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

    int N, M, K, A, W, res = 0, X, Y, B;
    vector<pr> arr;

    set<pr> st;
    set<pr>::iterator it;

    cin >> N >> M >> K;

    for (int i = 1; i <= N; i++) {
        cin >> W >> A;
        arr.push_back({W, A});
    }

    sort(arr.begin(), arr.end());

    for (pr i : arr) {
        B = 0;
        if (M) {
            B += min(i.second, M);

            if (i.second > M) {
                M = 0;
                i.second -= M;
            } else {
                M -= i.second;
                i.second = 0;
            }
        }

        it = st.upper_bound({i.first - K, INF});
        if (it != st.begin()) {
            --it;
            while (i.second && it != st.end()) {
                X = it->first, Y = it->second;
                st.erase(it);

                B += min(i.second, Y);

                if (Y > i.second) {
                    st.insert({X, Y - i.second});
                    i.second = 0;
                } else
                    i.second -= Y;

                it = st.lower_bound({X, -INF});
                if (it == st.begin())
                    break;
                it--;
            }
        }

        res += B;
        st.insert({i.first, B});
    }

    cout << res;

    return 0;
}