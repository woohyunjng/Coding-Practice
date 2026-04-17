#include <bits/stdc++.h>
using namespace std;
vector<int> v[100010];
int n, m, r, sum = 1;
bool visited[100010];
int v2[100010];
void DFS(int x) {
    v2[x] = sum;
    sum++;
    for (int i : v[x]) {
        if (!visited[i])
            visited[i] = true, DFS(i);
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> n >> m >> r;
    int x, y;
    for (int i = 1; i <= m; i++) {
        cin >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    for (int i = 1; i <= n; i++) {
        sort(v[i].begin(), v[i].end());
    }
    visited[r] = true, DFS(r);
    for (int i = 1; i <= n; i++)
        cout << v2[i] << '\n';
}
