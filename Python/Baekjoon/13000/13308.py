from heapq import heappop, heappush

N, M = map(int, input().split())
res = 10**20

money = [0] + list(map(int, input().split()))
min_money = [[res for j in range(2501)] for i in range(N + 1)]
arr = [[] for i in range(N + 1)]

for i in range(M):
    A, B, C = map(int, input().split())
    arr[A].append((C, B))
    arr[B].append((C, A))

hp = []
heappush(hp, (0, 1, money[1]))
min_money[1][money[1]] = 0

while hp:
    A, B, C = heappop(hp)

    if B == N:
        print(A)
        break

    if A > min_money[B][C]:
        continue

    for x, y in arr[B]:
        mn = min(C, money[y])
        if x * C + A < min_money[y][mn]:
            min_money[y][mn] = x * C + A
            heappush(hp, ((x * C + A), y, mn))
