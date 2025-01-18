import sys
import heapq

MAX = 200100
V = [0] * MAX


input = sys.stdin.readline

N, M = map(int, input().split())
P = list(map(int, input().split()))

st, en = 0, 10**20
res = 0

while st <= en:
    mid = (st + en) // 2
    cur, val = 0, 0

    for i in range(N):
        T = (mid // P[i] + 1) // 2
        cur += P[i] * T * T
        val += T

    if cur <= M:
        res = mid
        st = mid + 1
    else:
        en = mid - 1

val = 0
pq = []

for i in range(N):
    V = (res // P[i] + 1) // 2
    val += V
    M -= P[i] * V**2
    heapq.heappush(pq, (P[i] * (2 * V + 1), i, V + 1))

while True:
    K = heapq.heappop(pq)
    K_value, idx, V = K[0], K[1], K[2]

    if K_value > M:
        break

    M -= K_value
    heapq.heappush(pq, (P[idx] * (2 * V + 1), idx, V + 1))
    val += 1

print(val)
