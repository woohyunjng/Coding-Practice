#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

int parent[101];

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
    int N, A, B;
    double arr[101][2], res = 0;

    cin >> N;

    vector<pair<double, pair<int, int>>> link;

    for (int i = 1; i <= N; i++)
    {
        parent[i] = i;
        cin >> arr[i][0] >> arr[i][1];
    }

    for (int i = 1; i <= N; i++)
    {
        for (int j = i + 1; j <= N; j++)
        {
            link.push_back(make_pair(sqrt(pow(arr[i][0] - arr[j][0], 2) + pow(arr[i][1] - arr[j][1], 2)), make_pair(i, j)));
        }
    }
    sort(link.begin(), link.end());

    for (pair<double, pair<int, int>> i : link)
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
