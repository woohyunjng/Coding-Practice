#include <bits/stdc++.h>
#define int long long
#define MAX 100100
#define INF 0x7f7f7f7f7f7f7f7f
#define MOD 1000000007

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

// X 좌표 단조 증가
class ConvexHullTrick {
  public:
    vector<tp> F;
    int ftop = 0;

    void insert(pr X) {
        tp K = {X.first, X.second, 0};
        while (!F.empty()) {
            K[2] = (F.back()[1] - K[1]) / (K[0] - F.back()[0]);
            if (F.back()[2] < K[2])
                break;
            F.pop_back();
            if (F.size() == ftop)
                --ftop;
        }
        F.push_back(K);
    }

    int query(int x) {
        while (ftop + 1 < F.size() && F[ftop + 1][2] < x)
            ++ftop;
        return F[ftop][0] * x + F[ftop][1];
    }
};

// 그렇지 않은 경우
class ConvexHullTrick {
  public:
    vector<tp> F;

    void insert(tp K) {
        while (!F.empty()) {
            K[2] = (F.back()[1] - K[1]) / (K[0] - F.back()[0]);
            if (F.back()[2] < K[2])
                break;
            F.pop_back();
        }
        F.push_back(K);
    }

    int query(int x) {
        int res = F.size() - 1, st = 0, en = F.size() - 1, mid;
        if (x < F.back()[2]) {
            while (st + 1 < en) {
                mid = (st + en) / 2;
                if (x < F[mid][2])
                    en = mid;
                else
                    st = mid;
            }
            res = st;
        }
        return F[res][0] * x + F[res][1];
    }
};