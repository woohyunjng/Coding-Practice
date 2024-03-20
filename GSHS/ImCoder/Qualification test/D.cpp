#include <iostream>
#include <utility>
#include <algorithm>
#include <vector>
#include <tuple>
#include <queue>
#define MAX 2000000002
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, S, E, A, B;
    cin >> N >> S >> E;

    vector<pair<int, int>> arr;
    for (int i = 0; i < N; i++)
    {
        cin >> A >> B;
        if (B <= S || E <= A)
            continue;
        arr.push_back({max(S, A) - S, min(E, B) - S});
    }
    E -= S;
    sort(arr.begin(), arr.end());

    priority_queue<tuple<int, int, int>> end;
    int res = MAX;

    if (arr.empty())
    {
        cout << -1;
        return 0;
    }
    end.push({0, 0, 0});

    for (pair<int, int> K : arr)
    {
        while (!end.empty() && -get<0>(end.top()) < K.first)
            end.pop();

        if (end.empty())
            break;

        int first = -get<1>(end.top()) - get<0>(end.top()) - K.first;
        int second = -get<2>(end.top()) + 1;
        if (K.second == E)
            res = min(res, first);
        else if (second < 3)
            end.push({-K.second, -first, -second});
    }

    cout << (res < MAX ? res : -1);
}
