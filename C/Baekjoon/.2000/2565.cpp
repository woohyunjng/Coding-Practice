#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N, a, b;
    vector<pair<int, int>> line;

    cin >> N;
    for (int i = 0 ; i < N ; i ++) {
        cin >> a >> b;
        line.push_back(make_pair(a, b));
    }

    sort(line.begin(), line.end());

    int arr[N];
    vector<int> dp;
    for (int i = 0 ; i < N ; i ++)
        arr[i] = line[i].second;

    for (int i = 0 ; i < N ; i ++) {
        if (dp.empty() || dp.back() < arr[i]) {
            dp.push_back(arr[i]);
            continue;
        }

        int st = 0, ed = dp.size() - 1, md;
        while (st < ed) {
            md = (st + ed) / 2;
            if (dp[md] < arr[i]) {
                st = md + 1;
            } else {
                ed = md;
            }
        }

        dp[st] = arr[i];
    }

    cout << N - dp.size();
}
