#include <iostream>
#include <vector>
#include <algorithm>
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
    int N, M, A, B, C, res = 0;

    cin >> N;
    cin >> M;

    vector<pair<int, pair<int, int>>> link;

    for (int i = 1; i <= N; i++)
    {
        parent[i] = i;
    }

    for (int i = 0; i < M; i++)
    {
        cin >> A >> B >> C;
        link.push_back(make_pair(C, make_pair(A, B)));
    }
    sort(link.begin(), link.end());

    for (pair<int, pair<int, int>> i : link)
    {
        A = find(i.second.first);
        B = find(i.second.second);
        if (A == B)
            continue;

        uni(A, B);
        res += i.first;
    }

    cout << res;
}
