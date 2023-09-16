#include <iostream>
#include <vector>
#include <utility>
#define MAX_INT 0x3f3f3f3f3f3f3f3f
using namespace std;

typedef pair<pair<int, int>, long long> pl;

int main()
{
    int N, ML, MD, A, B, D;
    bool cycle = false;

    vector<pl> arr;

    cin >> N >> ML >> MD;
    long long min_dis[N + 1];

    for (int i = 2; i <= N; i++)
    {
        min_dis[i + 1] = MAX_INT;
    }
    min_dis[1] = 0;

    while (ML--)
    {
        cin >> A >> B >> D;
        arr.push_back(make_pair(make_pair(A, B), D));
    }

    while (MD--)
    {
        cin >> A >> B >> D;
        arr.push_back(make_pair(make_pair(B, A), -D));
    }

    for (int i = 0; i < N; i++)
    {
        for (pl j : arr)
        {
            if (min_dis[j.first.first] != MAX_INT && j.second + min_dis[j.first.first] < min_dis[j.first.second])
            {
                min_dis[j.first.second] = j.second + min_dis[j.first.first];
                if (i == N - 1)
                    cycle = true;
            }
        }
    }

    if (cycle)
        cout << -1;
    else if (min_dis[N] == MAX_INT)
        cout << -2;
    else
        cout << min_dis[N];
}