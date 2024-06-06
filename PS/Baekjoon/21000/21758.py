N = int(input())
mx = -1
hn, hnSum = [0], [0]

hn.extend(map(int, input().split()))

for i in range(1, N + 1):
    hnSum.append(hnSum[i - 1] + hn[i])

for i in range(2, N):
    mx = max(mx, hnSum[N] * 2 - hnSum[i] - hn[1] - hn[i])

for i in range(2, N):
    mx = max(mx, hnSum[N - 1] + hnSum[i - 1] - hn[i])

for i in range(2, N):
    mx = max(mx, hnSum[N - 1] + hn[i] - hn[1])

print(mx)
