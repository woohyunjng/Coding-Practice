#include <bits/stdc++.h>
#define int long long

#define MAX 1100
#define MOD 1000000007
#define INF 0x7f7f7f7f7f7f7f7f
#define endl '\n'

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

int N;
vector<pr> arr[MAX], tree;
int dis[MAX], cnt[MAX];
bool checked[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, D, A, min_X, min_Y, max_X, max_Y;
    bool cycle;

    queue<int> q;

    while (true) {
        cin >> N >> D;
        if (!N)
            break;

        min_X = INF, min_Y = 0, max_X = 0, max_Y = 0;
        tree.clear();

        for (int i = 1; i <= N; i++) {
            cin >> A;
            tree.push_back({A, i});

            if (A < min_X)
                min_X = A, min_Y = i;
            if (A > max_X)
                max_X = A, max_Y = i;
        }

        for (int i = 1; i < N; i++)
            arr[i + 1].push_back({i, -1});

        sort(tree.begin(), tree.end());
        for (int i = 0; i < N - 1; i++) {
            if (tree[i].second > tree[i + 1].second)
                arr[tree[i + 1].second].push_back({tree[i].second, D});
            else
                arr[tree[i].second].push_back({tree[i + 1].second, D});
        }

        fill(dis, dis + N + 1, INF);
        fill(cnt, cnt + N + 1, 0);
        fill(checked, checked + N + 1, false);

        if (min_Y > max_Y)
            swap(min_Y, max_Y);

        dis[min_Y] = 0;
        cycle = false;

        q.push(min_Y);
        checked[min_Y] = true;

        while (!q.empty()) {
            A = q.front(), q.pop();
            checked[A] = false;

            if (++cnt[A] == N || dis[A] < -INF) {
                cycle = true;
                break;
            }

            for (pr i : arr[A]) {
                if (dis[A] + i.second < dis[i.first]) {
                    dis[i.first] = dis[A] + i.second;
                    if (!checked[i.first]) {
                        checked[i.first] = true;
                        q.push(i.first);
                    }
                }
            }
        }

        if (N == 1)
            cout << 0 << '\n';
        else if (cycle)
            cout << -1 << '\n';
        else
            cout << abs(dis[max_Y]) << '\n';

        for (int i = 1; i <= N; i++)
            arr[i].clear();
    }

    return 0;
}