#include <bits/stdc++.h>
#define int long long

using namespace std;
typedef pair<int, string> pr;
typedef tuple<int, int, int> tp;

map<string, int> dis;

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, M, A, B, C;
    cin >> N;

    string S = "", E = "";
    vector<int> sorted;

    for (int i = 1; i <= N; i++)
    {
        cin >> A;
        S += to_string(A - 1);
        sorted.push_back(A - 1);
    }

    sort(sorted.begin(), sorted.end());
    for (int i : sorted)
        E += to_string(i);

    cin >> M;
    vector<tp> arr;

    while (M--)
    {
        cin >> A >> B >> C;
        arr.push_back({A - 1, B - 1, C});
    }

    priority_queue<pr, vector<pr>, greater<pr>> pq;
    pq.push({0, S});
    dis[S] = 0;

    while (!pq.empty())
    {
        pr i = pq.top();
        pq.pop();

        if (i.second == E)
            break;

        if (dis[i.second] < i.first)
            continue;

        for (tp k : arr)
        {
            S = i.second;
            swap(S[get<0>(k)], S[get<1>(k)]);
            if (dis.find(S) == dis.end() || i.first + get<2>(k) < dis[S])
            {
                dis[S] = i.first + get<2>(k);
                pq.push({dis[S], S});
            }
        }
    }

    cout << (dis.find(E) != dis.end() ? dis[E] : -1);
    return 0;
}