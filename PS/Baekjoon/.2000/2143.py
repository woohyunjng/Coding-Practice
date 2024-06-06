from collections import defaultdict

T = int(input())

N = int(input())
A = list(map(int, input().split()))
sm = defaultdict(int)

sum_A = [0]
for i in A:
    sum_A.append(sum_A[-1] + i)

for i in range(N):
    for j in range(i, N):
        sm[sum_A[j + 1] - sum_A[i]] += 1

M = int(input())
B = list(map(int, input().split()))
sum_B = [0]

for i in B:
    sum_B.append(sum_B[-1] + i)

res = 0
for i in range(M):
    for j in range(i, M):
        res += sm[T - (sum_B[j + 1] - sum_B[i])]

print(res)
