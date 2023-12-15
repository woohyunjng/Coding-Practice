#include <iostream>
#include <tuple>
#include <vector>
#include <algorithm>

using namespace std;
typedef tuple<long long, long long, int> tp;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    long long A, B, N, mx = -10000000000;
    int M;
    cin >> N;
    cin >> M;

    vector<tp> arr;
    for (int i = 1; i <= M; i++)
    {
        cin >> A >> B;
        if (A < B)
            arr.push_back({A, -B, i});
        else
        {
            arr.push_back({A, -B - N, i});
            arr.push_back({A - N, -B, i});
        }
    }
    sort(arr.begin(), arr.end());

    bool checked[M + 1] = {};
    for (tp i : arr)
    {
        if (mx >= (-get<1>(i)))
            checked[get<2>(i)] = true;
        else
            mx = -get<1>(i);
    }

    for (int i = 1; i <= M; i++)
    {
        if (!checked[i])
            cout << i << ' ';
    }
}