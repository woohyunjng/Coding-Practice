#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, mx_height = -1, mx = -1;
    cin >> N;
    int arr[N][N];

    for (int i = 0 ; i < N ; i ++) {
        for (int j = 0 ; j < N ; j ++) {
            cin >> arr[i][j];
            mx_height = max(mx_height, arr[i][j]);
        }
    }

    for (int a = 0 ; a < mx_height ; a ++) {
        int res = 0, checked[N][N] = {};

        for (int b = 0 ; b < N ; b ++) {
            for (int c = 0 ; c < N ; c ++) {
                if (checked[b][c] || arr[b][c] <= a)
                    continue;

                checked[b][c] = 1;
                stack<pair<int, int>> s;
                s.push({ b, c });

                while (!s.empty()) {
                    pair<int, int> p(s.top());
                    s.pop();

                    pair<int, int> go[4] = { { p.first + 1, p.second }, { p.first - 1, p.second }, { p.first, p.second + 1 }, { p.first, p.second - 1 } };
                    for (pair<int, int> q: go) {
                        if ((q.first >= N) || (q.first < 0) || (q.second >= N) || (q.second < 0) || checked[q.first][q.second] || (arr[q.first][q.second] <= a))
                            continue;
                        checked[q.first][q.second] = 1;
                        s.push(q);
                    }
                }

                res += 1;
            }
        }

        mx = max(mx, res);
    }

    cout << mx;
}
