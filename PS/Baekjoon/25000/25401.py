from collections import defaultdict

N = int(input())
x = list(map(int, input().split()))
y = [x[i] - x[i - 1] for i in range(1, N)]

res = -1

for i in range(N):
    a = defaultdict(int)
    for j in range(N):
        if i != j:
            a[(x[j] - x[i]) / (j - i)] += 1

    res = max(res, max(a.values()))

print(N - res - 1)
