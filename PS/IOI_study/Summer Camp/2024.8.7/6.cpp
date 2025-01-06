#include <bits/stdc++.h>
#define int long long

#define MAX 200100
#define MOD 1000000007
#define INF 0x7f7f7f7f7f7f7f7f
#define endl '\n'

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

vector<pr> arr;

int dist(pr a, pr b) { return (a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second); }

int divide_and_conquer(int A, int B) {
    int N = B - A + 1;
    if (N == 2)
        return dist(arr[A], arr[B]);
    if (N == 3)
        return min({dist(arr[A], arr[A + 1]), dist(arr[A + 1], arr[B]), dist(arr[B], arr[A])});

    int mid = (A + B) / 2, res, line;
    res = min(divide_and_conquer(A, mid), divide_and_conquer(mid + 1, B));

    vector<pr> tmp;
    line = (arr[mid].first + arr[mid + 1].first) / 2;

    for (int i = A; i <= B; i++) {
        if ((arr[i].first - line) * (arr[i].first - line) < res)
            tmp.push_back(arr[i]);
    }

    sort(tmp.begin(), tmp.end(), [](pr a, pr b) {
        if (a.second == b.second)
            return a.first < b.first;
        return a.second < b.second;
    });

    for (int i = 0; i < tmp.size(); i++)
        for (int j = i + 1; j < tmp.size() && (tmp[j].second - tmp[i].second) * (tmp[j].second - tmp[i].second) < res; j++)
            res = min(res, dist(tmp[i], tmp[j]));

    return res;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, A, B, res;

    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> A >> B;
        arr.push_back({A, B});
    }

    sort(arr.begin(), arr.end());

    res = divide_and_conquer(0, N - 1);
    cout << res;

    return 0;
}