#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define MAX 200001
using namespace std;

int set[MAX];

int find(int i)
{
    if (set[i] != i)
        set[i] = find(set[i]);
    return set[i];
}

void uni(int i, int j)
{
    i = find(i), j = find(j);
    if (i > j)
        swap(i, j);
    set[j] = i;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, Q, x, A, B;
    cin >> N >> Q;
    Q += N - 1;

    int parent[N + 1];
    for (int i = 0; i < N - 1; i++)
    {
        cin >> A;
        parent[i + 2] = A;
    }

    for (int i = 1; i <= N; i++)
        set[i] = i;

    vector<pair<int, int>> vec;
    vector<string> result;

    while (Q--)
    {
        cin >> x;
        if (!x)
        {
            cin >> A;
            vec.push_back({A, 0});
        }
        else
        {
            cin >> A >> B;
            vec.push_back({A, B});
        }
    }
    reverse(vec.begin(), vec.end());

    for (pair<int, int> query : vec)
    {
        if (!query.second)
            uni(query.first, parent[query.first]);
        else
        {
            A = find(query.first), B = find(query.second);
            result.push_back(A == B ? "YES" : "NO");
        }
    }
    reverse(result.begin(), result.end());

    for (string res : result)
        cout << res << '\n';
}