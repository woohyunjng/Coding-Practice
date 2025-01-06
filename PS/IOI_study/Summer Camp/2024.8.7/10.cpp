#include <bits/stdc++.h>
#define int long long

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

vector<pr> A, B, arr_A, arr_B;

int get_val(int X, int Y) { return (arr_B[Y].first - arr_A[X].first) * (arr_B[Y].second - arr_A[X].second); }

int divide_and_conquer(int s, int e, int l, int r) {
    if (s > e)
        return 0;
    int mid = (s + e) >> 1, res = -LLONG_MAX, X = l;

    for (int i = l; i <= r; i++) {
        if (arr_B[mid].first <= arr_A[i].first && arr_B[mid].second <= arr_A[i].second)
            continue;
        if (res <= get_val(i, mid))
            X = i, res = get_val(i, mid);
    }

    res = max(res, divide_and_conquer(s, mid - 1, l, X));
    res = max(res, divide_and_conquer(mid + 1, e, X, r));

    return res;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, M, res, X, Y;
    cin >> N >> M;

    for (int i = 1; i <= N; i++) {
        cin >> X >> Y;
        A.push_back({X, Y});
    }

    for (int i = 1; i <= M; i++) {
        cin >> X >> Y;
        B.push_back({X, Y});
    }

    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    for (pr i : A) {
        if (!arr_A.empty() && arr_A.back().second <= i.second)
            continue;
        arr_A.push_back(i);
    }

    for (pr i : B) {
        while (!arr_B.empty() && arr_B.back().second <= i.second)
            arr_B.pop_back();
        arr_B.push_back(i);
    }

    N = arr_A.size(), M = arr_B.size();

    res = divide_and_conquer(0, M - 1, 0, N - 1);
    cout << res;

    return 0;
}