#include <iostream>
#include <algorithm>
#define MAX 100001
using namespace std;

int arr[MAX], N;

bool solve(int l, int r, int cur, int x)
{
    int to_r = r < N - 1 ? arr[r + 1] - arr[cur] : -1;
    int to_l = l > 0 ? arr[cur] - arr[l - 1] : -1;

    if (0 < l && r < N - 1)
    {
        if (min(to_r, to_l) < 2 * x)
            return false;

        if (to_r < to_l)
            return solve(l, r + 1, r + 1, to_r);
        else if (to_r > to_l)
            return solve(l - 1, r, l - 1, to_l);
        else
            return solve(l, r + 1, r + 1, to_r) || solve(l - 1, r, l - 1, to_l);
    }
    else if (0 < l)
        return to_l >= 2 * x ? solve(l - 1, r, l - 1, to_l) : false;
    else if (r < N - 1)
        return to_r >= 2 * x ? solve(l, r + 1, r + 1, to_r) : false;
    else
        return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int T;
    cin >> T;

    while (T--)
    {
        cin >> N;
        for (int i = 0; i < N; i++)
            cin >> arr[i];

        if (N >= 22 || arr[N - 1] - arr[0] < 1 << (N - 2))
        {
            for (int i = 0; i < N; i++)
                cout << "NO\n";
            continue;
        }

        for (int i = 0; i < N; i++)
            cout << (solve(i, i, i, 0) ? "YES" : "NO") << '\n';
    }
}