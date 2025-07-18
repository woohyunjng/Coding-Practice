#include <bits/stdc++.h>
using namespace std;

const int MAX = 200001;

int Y[MAX], P[MAX];

int find(int X) { return X == P[X] ? X : P[X] = find(P[X]); }
void uni(int X, int Y) {
    X = find(X), Y = find(Y);
    if (X == Y)
        return;
    P[max(X, Y)] = min(X, Y);
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, ans = 0, X = 1;
    vector<int> arr;
    map<int, int> mp;

    cin >> N;
    for (int i = 1; i <= N; i++)
        cin >> Y[i], P[i] = i;

    for (int i = 1; i <= N;) {
        X = -1;
        while (i <= N && X < Y[i])
            arr.push_back(i), X = Y[i++];

        for (int j = 0; j + 1 < arr.size(); j++) {
            if (Y[arr[j]] + 1 == Y[arr[j + 1]])
                uni(arr[j], arr[j + 1]);
        }
        for (int j : arr) {
            if (mp.find(Y[j]) != mp.end())
                uni(j, mp[Y[j]]);
        }
        mp.clear();
        for (int j : arr)
            mp[Y[j]] = j;
        arr.clear();
    }

    for (int i = 1; i <= N; i++)
        ans += find(i) == i;

    cout << ans << '\n';
    cout << N << '\n';

    return 0;
}