#include <bits/stdc++.h>
#define double long double

using namespace std;

const int MAX_N = 6;
const int MAX_D = 101;

int A[MAX_N], B[MAX_N], N, M;

map<pair<vector<int>, int>, double> dp;

double get(vector<int> arr, int D) {
    if (dp.find({arr, D}) != dp.end())
        return dp[{arr, D}];

    double res = 0;
    bool flag = true;

    for (int i = N; i < N + M; i++)
        flag &= arr[i] == 0;

    if (flag)
        return dp[{arr, D}] = 1;
    else if (D == 0)
        return dp[{arr, D}] = 0;

    int cnt = 0;
    vector<int> arrA, arrB, val;

    for (int i : arr)
        cnt += i > 0;

    for (int i = 0; i < N + M; i++) {
        if (arr[i] == 0)
            continue;

        arrA.clear(), arrB.clear(), val.clear();
        for (int j = 0; j < N; j++)
            arrA.push_back(arr[j] + (i == j ? -1 : 0));
        for (int j = N; j < N + M; j++)
            arrB.push_back(arr[j] + (i == j ? -1 : 0));

        sort(arrA.begin(), arrA.end()), sort(arrB.begin(), arrB.end());
        for (int j : arrA)
            val.push_back(j);
        for (int j : arrB)
            val.push_back(j);

        res += get(val, D - 1) / cnt;
    }

    return dp[{arr, D}] = res;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int D;
    vector<int> arrA, arrB, arr;

    cin >> N >> M >> D;

    for (int i = 1; i <= N; i++)
        cin >> A[i], arrA.push_back(A[i]);
    for (int i = 1; i <= M; i++)
        cin >> B[i], arrB.push_back(B[i]);

    sort(arrA.begin(), arrA.end()), sort(arrB.begin(), arrB.end());
    for (int i : arrA)
        arr.push_back(i);
    for (int i : arrB)
        arr.push_back(i);

    cout << fixed << setprecision(10) << get(arr, D) << '\n';

    return 0;
}