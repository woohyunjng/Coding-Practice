#include <bits/stdc++.h>
#define int long long

#define MAX 2500
#define MOD 1000000007
#define INF 0x7f7f7f7f7f7f7f7f
#define endl '\n'

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

pair<vector<int>, vector<int>> get(int N, vector<int> &arr) {
    int X = 0, sm[3] = {0}, K = N >> 1;
    vector<int> res, left, temp, ret[3];
    pair<vector<int>, vector<int>> val;

    if (N == 2) {
        if (((arr[0] + arr[1]) & 1) == 0) {
            res.push_back(arr[0]), res.push_back(arr[1]);
            left.push_back(arr[2]);
        } else if (((arr[0] + arr[2]) & 1) == 0) {
            res.push_back(arr[0]), res.push_back(arr[2]);
            left.push_back(arr[1]);
        } else {
            res.push_back(arr[1]), res.push_back(arr[2]);
            left.push_back(arr[0]);
        }
        return {res, left};
    }

    for (X = 0; temp.size() < N - 1; X++)
        temp.push_back(arr[X]);
    val = get(K, temp);
    temp = val.second, ret[0] = val.first;

    for (; temp.size() < N - 1; X++)
        temp.push_back(arr[X]);
    val = get(K, temp);
    temp = val.second, ret[1] = val.first;

    for (; temp.size() < N - 1; X++)
        temp.push_back(arr[X]);
    val = get(K, temp);
    left = val.second, ret[2] = val.first;

    for (int i = 0; i < 3; i++)
        sm[i] = accumulate(ret[i].begin(), ret[i].end(), 0LL);

    if ((sm[0] + sm[1]) % N == 0) {
        for (int i : ret[0])
            res.push_back(i);
        for (int i : ret[1])
            res.push_back(i);
        for (int i : ret[2])
            left.push_back(i);
    } else if ((sm[0] + sm[2]) % N == 0) {
        for (int i : ret[0])
            res.push_back(i);
        for (int i : ret[2])
            res.push_back(i);
        for (int i : ret[1])
            left.push_back(i);
    } else {
        for (int i : ret[1])
            res.push_back(i);
        for (int i : ret[2])
            res.push_back(i);
        for (int i : ret[0])
            left.push_back(i);
    }

    return {res, left};
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, X;
    vector<int> arr;
    cin >> N;

    for (int i = 1; i <= 2 * N - 1; i++) {
        cin >> X;
        arr.push_back(X);
    }

    pair<vector<int>, vector<int>> res = get(N, arr);
    for (int i : res.first)
        cout << i << ' ';
    cout << '\n';

    return 0;
}