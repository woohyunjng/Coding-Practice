from sys import stdin

input = stdin.readline

cnt = [0] * 1000100
res = 0

Q = int(input())
for q in range(Q):
    query = list(map(int, input().split()))
    if len(query) == 1:
        print(res)
    elif query[0] == 1:
        cnt[query[1]] += 1
        if cnt[query[1]] == 1:
            res += 1
    else:
        cnt[query[1]] -= 1
        if cnt[query[1]] == 0:
            res -= 1
