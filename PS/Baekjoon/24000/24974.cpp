#include <bits/stdc++.h>
#define int long long

#define MAX 200100
#define MOD 1000000007
#define INF 0x7f7f7f7f7f7f7f7f
#define endl '\n'

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;
typedef array<int, 4> ftp;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    vector<ftp> arr;
    multiset<pr> st;
    multiset<pr>::iterator it;

    int N, A, B, C, D, X, res = 0;
    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> A >> B >> C >> D;
        arr.push_back({B + C, B - C, D, A});
    }
    sort(arr.begin(), arr.end());

    for (ftp i : arr) {
        if (i[3] == 1) {
            st.insert({i[1], i[2]});
        } else {
            while (true) {
                it = st.lower_bound({i[1] + 1, -INF});
                if (it == st.begin())
                    break;
                it = prev(it);

                A = it->first, B = it->second;
                st.erase(it);

                C = min(i[2], B);
                i[2] -= C, res += C;

                if (!i[2]) {
                    st.insert({A, B - C});
                    break;
                }
            }
        }
    }

    cout << res << '\n';

    return 0;
}