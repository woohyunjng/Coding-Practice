#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, a, b;
    vector<pair<int, int>> line, dp;
    vector<int> ln, res;

    cin >> N;
    for (int i = 0 ; i < N ; i ++) {
        cin >> a >> b;
        line.push_back(make_pair(a, b));
    }

    sort(line.begin(), line.end());

    for (int i = 0 ; i < N ; i ++) {
        if (dp.empty() || dp.back().second < line[i].second) {
            dp.push_back(line[i]);
            ln.push_back(dp.size() - 1);
            continue;
        }

        int st = 0, ed = dp.size() - 1, md;
        while (st < ed) {
            md = (st + ed) / 2;
            if (dp[md].second < line[i].second) {
                st = md + 1;
            } else {
                ed = md;
            }
        }

        dp[st] = line[i];
        ln.push_back(st);
    }

    a = dp.size() - 1;
    for (int i = N - 1; i >= 0 ; i --) {
        if (ln[i] == a) {
            a --;
        } else {
            res.push_back(line[i].first);
        }
    }

    cout << res.size() << "\n";
    for (int i = res.size() - 1 ; i >= 0 ; i --)
        cout << res[i] << "\n";
}
