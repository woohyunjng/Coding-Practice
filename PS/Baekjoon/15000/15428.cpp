#include <bits/stdc++.h>

#define int long long
#define double long double

#define MAX 200
#define INF 0x3f3f3f3f3f3f3f3f

using namespace std;
typedef array<double, 2> pr;
typedef array<double, 3> tp;

double dis(pr A, pr B) {
    return sqrt((A[0] - B[0]) * (A[0] - B[0]) + (A[1] - B[1]) * (A[1] - B[1]));
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, T;
    double X, Y, K;
    pr P;
    double val[2] = {0, 0};

    vector<tp> arr;
    vector<pr> ans;

    cin >> N >> T;

    while (N--) {
        cin >> X >> Y >> K;
        if (!arr.empty())
            val[0] += dis((pr){X, Y}, {arr.back()[1], arr.back()[2]});
        arr.push_back({K, X, Y});
    }

    K = 0;
    while (true) {
        X = lower_bound(arr.begin(), arr.end(), (tp){K, INF, INF}) - arr.begin() - 1;
        if (K == arr[X][0] || X == arr.size() - 1)
            P = {arr[X][1], arr[X][2]};
        else {
            double d = K - arr[X][0];
            P = {arr[X][1] + (arr[X + 1][1] - arr[X][1]) * d / (arr[X + 1][0] - arr[X][0]),
                 arr[X][2] + (arr[X + 1][2] - arr[X][2]) * d / (arr[X + 1][0] - arr[X][0])};
        }

        if (!ans.empty())
            val[1] += dis(ans.back(), P);
        ans.push_back(P);

        if (K >= arr.back()[0])
            break;
        K += T;
    }

    cout << fixed << setprecision(10) << (val[0] - val[1]) / val[0] * 100 << '\n';

    return 0;
}