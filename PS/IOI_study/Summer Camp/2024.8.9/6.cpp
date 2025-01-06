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

    int N, A, B, C, res = 0, cur_Z = 0, cur_X, Z, X, Y, K = 0, area, x, y;
    set<tp>::iterator iter;
    cin >> N;

    vector<tp> arr;

    for (int i = 1; i <= N; i++) {
        cin >> A >> B >> C;
        arr.push_back({C, A, B});
    }
    sort(arr.begin(), arr.end(), greater<tp>());

    set<tp> st;
    st.insert({0, INF, 0});
    cur_Z = arr[0][0];

    for (tp i : arr) {
        Z = i[0], X = i[1], Y = i[2];
        res += K * (cur_Z - Z);

        cur_Z = Z;

        iter = st.lower_bound({X, Y, 0});

        if (iter != st.end()) {
            if ((*iter)[1] >= Y)
                continue;
            x = (*iter)[0], y = (*iter)[1], area = (*iter)[2];
            K -= area;
            area = y * (x - X);
            K += area;
            st.erase(iter);
            st.insert({x, y, area});
        }

        iter = st.lower_bound({X, Y, 0});

        while (true) {
            auto prv = prev(iter);
            if ((*prv)[1] <= Y) {
                K -= (*prv)[2];
                iter = st.erase(prv);
            } else {
                area = Y * (X - (*prv)[0]);
                K += area;
                st.insert({X, Y, area});
                break;
            }
        }
    }

    res += K * cur_Z;
    cout << res;

    return 0;
}
