# 100 (0:06)

from collections import defaultdict

T = int(input())
for t in range(T):
    N, C, D = map(int, input().split())
    arr = list(map(int, input().split()))
    avail = defaultdict(int)
    for i in arr:
        avail[i] += 1

    a = min(arr)
    res = True
    for i in range(N):
        for j in range(N):
            if not i and not j:
                continue
            val = a + i * C + j * D
            if avail[val]:
                avail[val] -= 1
            else:
                res = False
                break
        if not res:
            break

    print("YES" if res else "NO")
