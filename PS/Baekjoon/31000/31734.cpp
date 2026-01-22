#include <bits/stdc++.h>
#define int long long

using namespace std;

typedef array<int, 2> pr;

const int MAX = 200001;
const int INF = 0x3f3f3f3f3f3f3f3f;

int P[MAX], S[MAX], T[MAX], D;
vector<pr> ban, arr;

int calc(int X, int Y) {
    if (T[X] == -1 || Y < arr[X][0] + T[X])
        return S[X];
    else
        return (Y - arr[X][0] - T[X]) / D + S[X] + 1;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, Q, A, B, L, R, X, Y, K;

    cin >> N >> Q >> D >> A >> B;
    for (int i = 0; i < N; i++) {
        cin >> L >> R;
        ban.push_back({L, R});
    }

    L = 0;
    for (pr i : ban)
        arr.push_back({L, i[0] - 1}), L = i[1] + 1;
    arr.push_back({L, INF}), ban = arr, arr.clear();

    P[0] = 0, arr.push_back(ban[0]), ban.erase(ban.begin());
    for (pr i : ban) {
        X = lower_bound(arr.begin(), arr.end(), (pr){i[0] - D, INF + 1}) - arr.begin();
        if (X > 0 && arr[X - 1][1] >= i[0] - D)
            P[arr.size()] = P[X - 1] + 1, arr.push_back(i);
        else if (X < arr.size() && arr[X][0] + D <= i[1])
            P[arr.size()] = P[X] + 1, arr.push_back({arr[X][0] + D, i[1]});
        else if (X == arr.size())
            break;
    }

    S[0] = 0, T[0] = arr[0][1] >= D ? D : -1;
    for (int i = 1; i < arr.size(); i++) {
        L = arr[i][0], R = arr[i][1], X = lower_bound(arr.begin(), arr.end(), (pr){L - D, INF + 1}) - arr.begin() - 1;
        S[i] = calc(X, L - D) + 1, T[i] = (R - L >= D) ? D : -1;
        for (int st = 1, en = min(R - L, D - 1), md; st <= en;) {
            md = st + en >> 1, X = lower_bound(arr.begin(), arr.end(), (pr){L + md - D, INF + 1}) - arr.begin() - 1;
            Y = min(arr[X][1], L + md - D);
            if (calc(X, Y) >= S[i])
                T[i] = md, en = md - 1;
            else
                st = md + 1;
        }
    }

    while (Q--) {
        cin >> K, X = lower_bound(arr.begin(), arr.end(), (pr){K, INF + 1}) - arr.begin() - 1;
        if (arr[X][1] < K)
            cout << -1 << '\n';
        else if (A * D <= B)
            cout << K * A + (B - A * D) * P[X] << '\n';
        else
            cout << K * A + (B - A * D) * calc(X, K) << '\n';
    }

    return 0;
}