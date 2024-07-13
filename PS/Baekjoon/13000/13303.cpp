#include <bits/stdc++.h>
#define int long long
#define MAX 100100

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, st, en, A, B, C, D, X, Y, res = LLONG_MAX;
    set<pr> s;
    vector<tp> vec;
    vector<int> res_val;

    cin >> N;
    cin >> st >> en;
    s.insert({st, 0});

    for (int i = 1; i <= N; i++) {
        cin >> A >> B >> C;
        vec.push_back({A, B, C});
    }
    sort(vec.begin(), vec.end());

    for (tp i : vec) {
        A = i[1], B = i[2];
        if (A > B)
            swap(A, B);

        auto X = s.lower_bound({A, 0});
        if (X == s.end()) {
            X--;
            C = X->second + abs(A - X->first);
            X++;
        } else if (X == s.begin())
            C = X->second + abs(A - X->first);
        else {
            C = X->second + abs(A - X->first);
            X--;
            C = min(C, X->second + abs(A - X->first));
            X++;
        }

        auto Y = s.lower_bound({B, 0});
        if (Y == s.end()) {
            Y--;
            D = Y->second + abs(B - Y->first);
            Y++;
        } else if (Y == s.begin())
            D = Y->second + abs(B - Y->first);
        else {
            D = Y->second + abs(B - Y->first);
            Y--;
            D = min(D, Y->second + abs(B - Y->first));
            Y++;
        }

        if (Y->first == B)
            Y++;
        s.erase(X, Y);
        s.insert({A, C});
        s.insert({B, D});
    }

    for (pr i : s)
        res = min(res, i.second);

    for (pr i : s) {
        if (i.second == res)
            res_val.push_back(i.first);
    }

    cout << res + en << '\n';
    cout << res_val.size() << ' ';
    for (int i : res_val)
        cout << i << ' ';

    return 0;
}