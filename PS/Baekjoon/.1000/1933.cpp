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

    int N, A, B, C, X = 0, Y = 0;
    vector<tp> arr;
    set<pr> st;
    set<pr>::iterator it;

    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> A >> B >> C;
        arr.push_back({A, -B, C});
    }
    sort(arr.begin(), arr.end());

    st.insert({INF, 0});

    for (tp i : arr) {
        it = st.begin();
        while (it->first < i[0]) {
            cout << it->first << ' ' << next(it)->second << ' ';
            it = st.erase(it);
        }

        if (it->first == i[0]) {
            if (it->second != -i[1]) {
                it = st.erase(it);
                if (it->second < -i[1])
                    cout << i[0] << ' ' << -i[1] << ' ';
            } else
                st.erase(it);
        } else {
            if (it->second < -i[1])
                cout << i[0] << ' ' << -i[1] << ' ';
        }

        it = st.lower_bound({i[2], -INF});
        if (it != st.end() && it->second >= -i[1])
            continue;
        if (it != st.end() && (it->first == i[2] && it->second < -i[1]))
            it = st.erase(it);

        if (it != st.begin()) {
            it = prev(it);
            while (true) {
                if (it->second > -i[1])
                    break;
                it = st.erase(it);
                if (it == st.begin())
                    break;
                it = prev(it);
            }
        }

        st.insert({i[2], -i[1]});
    }

    it = st.lower_bound({0, -INF});
    while (it->first < INF) {
        cout << it->first << ' ' << next(it)->second << ' ';
        it = st.erase(it);
    }

    return 0;
}