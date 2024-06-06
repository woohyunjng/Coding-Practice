#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int parent[1001];

int find(int i)
{
    if (i != parent[i])
    {
        parent[i] = find(parent[i]);
    }
    return parent[i];
}

void uni(int i, int j)
{
    i = find(i);
    j = find(j);
    if (i > j)
        swap(i, j);
    parent[j] = i;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);

    int N, M, K, F, T, A, B, mn, mx;
    char C;

    while (true)
    {
        vector<pair<int, pair<int, int>>> arr;

        cin >> N >> M >> K;
        if (!N)
            break;

        for (int i = 0; i < M; i++)
        {
            cin >> C >> F >> T;
            if (C == 'R')
                arr.push_back({1, {F, T}});
            else
                arr.push_back({0, {F, T}});
        }
        sort(arr.begin(), arr.end());
        mn = 0, mx = 0;

        for (int i = 1; i <= N; i++)
        {
            parent[i] = i;
        }
        for (pair<int, pair<int, int>> i : arr)
        {
            A = find(i.second.first), B = find(i.second.second);
            if (A == B)
                continue;

            if (!i.first)
                mx++;
            uni(A, B);
        }

        reverse(arr.begin(), arr.end());
        for (int i = 1; i <= N; i++)
        {
            parent[i] = i;
        }
        for (pair<int, pair<int, int>> i : arr)
        {
            A = find(i.second.first), B = find(i.second.second);
            if (A == B)
                continue;

            if (!i.first)
                mn++;
            uni(A, B);
        }

        cout << ((mn <= K && K <= mx) ? 1 : 0) << '\n';
    }
}