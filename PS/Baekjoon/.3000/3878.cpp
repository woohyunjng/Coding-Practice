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

bool is_intersect(pr A, pr B, pr C, pr D) { // A-B C-D 교차판정
    int AtoC = CCW(A, B, C) * CCW(A, B, D);
    int CtoA = CCW(C, D, A) * CCW(C, D, B);

    if (AtoC == 0 && CtoA == 0) {
        if (A > B)
            swap(A, B);
        if (C > D)
            swap(C, D);

        return C <= B && A <= D;
    }

    return AtoC <= 0 && CtoA <= 0;
}

vector<pr> convex_hull(vector<pr> &arr) {
    vector<pr> upper, lower, hull;
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

    return hull;
}

bool is_in_hull(vector<pr> &hull, pr P) {
    int N = hull.size(), first = CCW(hull[0], hull[1], P);
    for (int i = 1; i < N; i++) {
        if (CCW(hull[i], hull[(i + 1) % N], P) != first)
            return false;
    }
    return true;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int T, N, M, A, B;
    bool res;
    vector<pr> black, black_hull, white, white_hull;

    cin >> T;
    while (T--) {
        black.clear(), black_hull.clear(), white.clear(), white_hull.clear();
        cin >> N >> M;

        while (N--) {
            cin >> A >> B;
            black.push_back({A, B});
        }

        while (M--) {
            cin >> A >> B;
            white.push_back({A, B});
        }

        black_hull = convex_hull(black), white_hull = convex_hull(white);
        if (black_hull.size() > white_hull.size())
            swap(black_hull, white_hull);
        N = black_hull.size(), M = white_hull.size();

        res = true;

        if (N == 1 && M == 1)
            res = true;
        else if (N == 1 && M == 2)
            res = !(CCW(white_hull[0], white_hull[1], black_hull.front()) == 0);
        else if (N == 1)
            res = !is_in_hull(white_hull, black_hull.front());
        else if (N == 2) {
            for (int i = 0; i < M; i++) {
                if (is_intersect(black_hull[0], black_hull[1], white_hull[i], white_hull[(i + 1) % M])) {
                    res = false;
                    break;
                }
            }
        } else {
            for (pr i : black_hull) {
                if (is_in_hull(white_hull, i)) {
                    res = false;
                    break;
                }
            }

            for (pr i : white_hull) {
                if (is_in_hull(black_hull, i)) {
                    res = false;
                    break;
                }
            }

            for (int i = 0; i < N; i++) {
                for (int j = 0; j < M; j++) {
                    if (is_intersect(black_hull[i], black_hull[(i + 1) % N], white_hull[j], white_hull[(j + 1) % M])) {
                        res = false;
                        break;
                    }
                }
            }
        }

        cout << (res ? "YES" : "NO") << '\n';
    }

    return 0;
}