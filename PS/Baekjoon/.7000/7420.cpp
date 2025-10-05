#include <bits/stdc++.h>

#define int long long
#define double long double

using namespace std;

typedef array<int, 2> pr; // pair<int, int>

const int MAX = 1001;

int CCW(pr A, pr B, pr C) { // A-B-C 양수 반시계 / 0 일직선 / 음수 시계
    int val = (B[0] - A[0]) * (C[1] - A[1]) - (C[0] - A[0]) * (B[1] - A[1]);
    if (val > 0)
        return 1;
    else if (val < 0)
        return -1;
    else
        return 0;
}

double dis(pr A, pr B) { return (double)sqrt((A[0] - B[0]) * (A[0] - B[0]) + (A[1] - B[1]) * (A[1] - B[1])); }

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, L, X, Y, int_ans;
    double ans;
    vector<pr> arr, upper, lower, hull;

    cin >> N >> L, ans = 2 * 3.14159265358979323846 * L;
    while (N--)
        cin >> X >> Y, arr.push_back({X, Y});

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
    for (int i = 1; i < (int)lower.size() - 1; i++)
        hull.push_back(lower[i]);

    for (int i = 0; i < (int)hull.size(); i++)
        ans += dis(hull[i], hull[(i + 1) % hull.size()]);

    int_ans = (int)(ans + 0.5);
    cout << int_ans << '\n';

    return 0;
}