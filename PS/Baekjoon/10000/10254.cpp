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

int CCCW(pr A, pr B, pr C, pr D) {
    pr tmp = D;
    D.first -= (C.first - B.first);
    D.second -= (C.second - B.second);
    return CCW(A, B, D);
}

int dis(pr A, pr B) {
    return (A.first - B.first) * (A.first - B.first) + (A.second - B.second) * (A.second - B.second);
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int T, N, A, B, res;
    vector<pr> arr, hull, upper, lower;
    pr res_1, res_2;

    cin >> T;
    while (T--) {
        cin >> N;

        arr.clear(), upper.clear(), lower.clear();
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

        N = hull.size(), A = 1, res = 0;
        for (int i = 0; i < N; i++) {
            while (A + 1 != i && CCCW(hull[i], hull[(i + 1) % N], hull[A % N], hull[(A + 1) % N]) < 0) {
                B = dis(hull[i], hull[A % N]);
                if (B > res)
                    res = B, res_1 = hull[i], res_2 = hull[A % N];
                A++;
            }

            B = dis(hull[i], hull[A % N]);
            if (B > res)
                res = B, res_1 = hull[i], res_2 = hull[A % N];
        }

        cout << res_1.first << ' ' << res_1.second << ' ' << res_2.first << ' ' << res_2.second << '\n';
    }

    return 0;
}