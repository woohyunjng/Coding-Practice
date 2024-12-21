#include <bits/stdc++.h>
#define int long long
#define double long double

#define MAX 200100

using namespace std;
typedef pair<int, int> pr;

double get(int X_1, int H_1, int X_2, int H_2) {
    return (double)(H_1 * X_2 - H_2 * X_1) / (X_2 - X_1);
}

int CCW(pr A, pr B, pr C) {
    int val = (B.first - A.first) * (C.second - A.second) - (C.first - A.first) * (B.second - A.second);
    if (val > 0)
        return 1;
    else if (val < 0)
        return -1;
    else
        return 0;
}

int X[MAX], H[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, val, K;
    double res = 0;
    bool flag = false;

    vector<pr> vec;
    cin >> N;

    for (int i = 1; i <= N; i++) {
        cin >> X[i] >> H[i];
        while (vec.size() >= 2) {
            val = CCW(vec[vec.size() - 2], vec[vec.size() - 1], {X[i], H[i]});
            if (val <= 0)
                break;
            vec.pop_back();
        }
        if (!vec.empty())
            res = max(res, get(vec.back().first, vec.back().second, X[i], H[i])), flag |= get(vec.back().first, vec.back().second, X[i], H[i]) >= 0;
        vec.push_back({X[i], H[i]});
    }

    if (!flag)
        cout << -1 << '\n';
    else
        cout << fixed << setprecision(10) << res << '\n';

    return 0;
}