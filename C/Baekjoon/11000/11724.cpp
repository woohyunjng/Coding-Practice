#include <iostream>
#include <stack>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, M, U, V, res = 0;
    cin >> N >> M;

    int arr[N + 1][N + 1] = {}, checked[N + 1] = {};

    for (int i = 0; i < M; i++)
    {
        cin >> U >> V;
        arr[U][V] = 1;
        arr[V][U] = 1;
    }

    for (int i = 1; i <= N; i++)
    {
        if (checked[i])
            continue;

        checked[i] = 1;
        stack<int> s;
        s.push(i);

        while (!s.empty())
        {
            int p = s.top();
            s.pop();

            for (int j = 1; j <= N; j++)
            {
                if (checked[j] || !arr[p][j])
                    continue;
                checked[j] = 1;
                s.push(j);
            }
        }

        res += 1;
    }

    cout << res;
}
