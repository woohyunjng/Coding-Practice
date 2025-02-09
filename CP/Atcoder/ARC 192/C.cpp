#include <bits/stdc++.h>
#define int long long

using namespace std;

const int MAX = 6000;

int val[MAX][MAX], P[MAX], A[MAX], B[MAX], V[MAX], K[2][MAX];

int get(int X, int Y) {
    if (val[X][Y] == 0) {
        cout << "? " << X << ' ' << Y << '\n', cout.flush();
        cin >> val[X][Y];
    }
    return val[X][Y];
}

signed main() {
    int N, X;
    vector<int> arr[3], perm;
    cin >> N;

    X = get(1, 2);
    for (int i = 3; i <= N; i++)
        K[0][i] = get(1, i);
    for (int i = 3; i <= N; i++)
        K[1][i] = get(2, i);

    for (int i = 3; i <= N; i++) {
        if (K[0][i] < X && K[1][i] < X)
            arr[1].push_back(i);
        else if (K[0][i] < K[1][i])
            arr[0].push_back(i);
        else
            arr[2].push_back(i);
    }

    sort(arr[0].begin(), arr[0].end(), [&](int x, int y) { return K[0][x] > K[0][y]; });
    sort(arr[1].begin(), arr[1].end(), [&](int x, int y) { return K[0][x] < K[0][y]; });
    sort(arr[2].begin(), arr[2].end(), [&](int x, int y) { return K[0][x] < K[0][y]; });

    for (int i = 0; i < arr[0].size(); i++) {
        if (i == arr[0].size() - 1)
            A[arr[0][i]] = get(2, arr[0][i]) - get(1, 2);
        else
            A[arr[0][i]] = get(1, arr[0][i]) - get(1, arr[0][i + 1]);
    }

    for (int i = 0; i < arr[2].size(); i++) {
        if (i == 0)
            A[arr[2][i]] = get(1, arr[2][i]) - get(1, 2);
        else
            A[arr[2][i]] = get(1, arr[2][i]) - get(1, arr[2][i - 1]);
    }

    if (!arr[1].empty()) {
        A[2] = get(1, 2) - get(1, arr[1].back());
        for (int i = arr[1].size() - 1; i > 0; i--)
            A[arr[1][i]] = get(1, arr[1][i]) - get(1, arr[1][i - 1]);
        A[arr[1][0]] = get(2, arr[1][0]) - (arr[1].size() == 1 ? A[2] : get(2, arr[1][1])), A[1] = get(1, 2) - get(2, arr[1][0]);
    } else {
        if (!arr[0].empty())
            X = arr[0].back(), A[2] = get(2, X) - get(1, X), A[1] = get(1, 2) - A[2];
        else
            X = arr[2].front(), A[1] = get(1, X) - get(2, X), A[2] = get(1, 2) - A[1];
    }

    reverse(arr[0].begin(), arr[0].end()), reverse(arr[1].begin(), arr[1].end()), reverse(arr[2].begin(), arr[2].end());
    while (!arr[0].empty())
        perm.push_back(arr[0].back()), arr[0].pop_back();
    perm.push_back(1);
    while (!arr[1].empty())
        perm.push_back(arr[1].back()), arr[1].pop_back();
    perm.push_back(2);
    while (!arr[2].empty())
        perm.push_back(arr[2].back()), arr[2].pop_back();
    for (int i = 1; i <= N; i++)
        P[perm[i - 1]] = i;

    for (int i = 1; i <= N; i++)
        B[P[i]] = A[i];

    cout << "! ";
    for (int i = 1; i <= N; i++)
        cout << P[i] << ' ';
    for (int i = 1; i <= N; i++)
        cout << B[i] << ' ';
    cout << '\n', cout.flush();

    return 0;
}