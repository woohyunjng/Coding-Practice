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

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    vector<pr> arr, upper, lower, hull;

    int N, A, B;
    cin >> N;

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

    cout << upper.size() + lower.size() - 2 << endl;

    return 0;
}