#include <bitset>
#include <iostream>
#include <limits.h>
#include <map>
#include <math.h>
#include <memory.h>
#include <queue>
#include <string>
#include <vector>
using namespace std;

int bfs(int mid);
int n, k;
vector<pair<int, int>> v;
struct s {
    int x;
    int y;
    int cur;
} typedef s;
int main() {
    cin >> n >> k;
    v.push_back({0, 0});
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        v.push_back({y, x});
    }
    int l = 0;
    int r = 987654321;
    int ans = 987654321;
    while (l <= r) {
        int mid = (l + r) / 2;

        if (bfs(mid)) {
            r = mid - 1;
            ans = min(mid, ans);
        } else
            l = mid + 1;
    }
    cout << ans;
}

long get_oil(int x1, int y1, int x2, int y2) {
    int dis = (int)ceil(sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2)));
    if (dis % 10 == 0)
        return dis / 10;
    else
        return dis / 10 + 1;
}
int bfs(int mid) {
    queue<s> q;
    q.push({0, 0, 0});
    bool visit[1001];
    memset(visit, 0, sizeof(visit));
    visit[0] = 1;
    while (!q.empty()) {
        int x = q.front().x;
        int y = q.front().y;
        int cur = q.front().cur;

        q.pop();
        if (mid >= get_oil(x, y, 10000, 10000))
            return true;
        if (cur == k + 1)
            continue;
        for (int i = 1; i < v.size(); i++) {
            int nx = v[i].second;
            int ny = v[i].first;
            if (get_oil(x, y, nx, ny) <= mid && !visit[i]) {
                visit[i] = 1;
                q.push({nx, ny, cur + 1});
            }
        }
    }
    return false;
}