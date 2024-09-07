#include <bits/stdc++.h>
#define int long long

#define MAX 3010
#define MOD 1000000007
#define INF 0x7f7f7f7f7f7f7f7f
#define endl '\n'

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

int N;
vector<pr> arr[MAX];
int dis[MAX], cnt[MAX], vst[MAX];
bool checked[MAX];

tp query[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, A, B, D, S, E;
    bool cycle = false;

    vector<int> comp;
    queue<int> q;

    cin >> N;

    for (int i = 1; i <= N; i++) {
        cin >> A >> B >> D;
        query[i] = {A, B + 1, D};

        comp.push_back(A);
        comp.push_back(B + 1);
    }

    sort(comp.begin(), comp.end());
    comp.erase(unique(comp.begin(), comp.end()), comp.end());

    for (int i = 1; i <= N; i++) {
        A = lower_bound(comp.begin(), comp.end(), query[i][0]) - comp.begin();
        B = lower_bound(comp.begin(), comp.end(), query[i][1]) - comp.begin();

        arr[A].push_back({B, query[i][2]});
        arr[B].push_back({A, -query[i][2]});

        vst[A]++, vst[B]--;
    }

    N = comp.size();
    for (int i = 1; i < N; i++)
        vst[i] += vst[i - 1];

    for (int i = 0; i < N; i++) {
        arr[i + 1].push_back({i, 0});
        if (!vst[i])
            arr[i].push_back({i + 1, 0});
    }

    for (int x = 0; x < 2; x++) {
        fill(dis, dis + N + 1, INF);
        fill(cnt, cnt + N + 1, 0);
        fill(checked, checked + N + 1, false);

        if (x)
            S = 0, E = N - 1;
        else
            S = N - 1, E = 0;

        dis[S] = 0;

        q.push(S);
        checked[S] = true;

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

        if (cycle)
            cout << -1 << ' ';
        else
            cout << abs(dis[E]) << ' ';
    }

    return 0;
}