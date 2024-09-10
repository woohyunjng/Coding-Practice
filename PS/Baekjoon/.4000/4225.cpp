#include <bits/stdc++.h>
#define int long long

#define MAX 200100
#define MOD 1000000007
#define INF 0x7f7f7f7f7f7f7f7f
#define endl '\n'

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

int CCW(pr A, pr B, pr C) { // A-B-C 양수 반시계 / 0 일직선 / 음수 시계
    int val = (B.first - A.first) * (C.second - A.second) - (C.first - A.first) * (B.second - A.second);
    if (val > 0)
        return 1;
    else if (val < 0)
        return -1;
    else
        return 0;
}

long double distance_line_point(pr A, pr B, pr C) {
    long double a, b, c, s, S;
    a = sqrt(pow(B.first - C.first, 2) + pow(B.second - C.second, 2));
    b = sqrt(pow(A.first - C.first, 2) + pow(A.second - C.second, 2));
    c = sqrt(pow(A.first - B.first, 2) + pow(A.second - B.second, 2));
    s = (a + b + c) / 2;
    S = sqrt(s * (s - a) * (s - b) * (s - c));
    return 2 * S / c;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, A, B, T = 1;
    long double res, val;
    vector<pr> upper, lower, hull, arr;

    cout << fixed << setprecision(2);

    while (true) {
        cin >> N;
        if (!N)
            break;

        arr.clear();
        upper.clear();
        lower.clear();
        hull.clear();

        for (int i = 1; i <= N; i++) {
            cin >> A >> B;
            arr.push_back({A, B});
        }

        sort(arr.begin(), arr.end());

        for (pr i : arr) {
            while (upper.size() >= 2 && CCW(upper[upper.size() - 2], upper[upper.size() - 1], i) >= 0)
                upper.pop_back();
            upper.push_back(i);
        }

        reverse(arr.begin(), arr.end());
        for (pr i : arr) {
            while (lower.size() >= 2 && CCW(lower[lower.size() - 2], lower[lower.size() - 1], i) >= 0)
                lower.pop_back();
            lower.push_back(i);
        }

        hull = upper;
        for (int i = 1; i < lower.size() - 1; i++)
            hull.push_back(lower[i]);

        N = hull.size();
        res = INF;

        for (int i = 0; i < N; i++) {
            val = 0;
            for (int j = 0; j < N; j++) {
                val = max(val, distance_line_point(hull[i], hull[(i + 1) % N], hull[j]));
            }
            res = min(res, val);
        }

        cout << "Case " << T++ << ": " << ceil(res * 100 - (1e-12)) / 100 << '\n';
    }

    return 0;
}