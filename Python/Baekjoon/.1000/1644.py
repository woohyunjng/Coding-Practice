N = int(input())
prime = [True for i in range(N + 1)]
prime[0] = prime[1] = False

for i in range(2, int(N**0.5) + 1):
    if not prime[i]:
        continue
    for j in range(i * 2, N + 1, i):
        prime[j] = False

sum = [0]
for i in range(N + 1):
    if prime[i]:
        sum.append(sum[-1] + i)

i, j = 0, 1
res = 0
while j < len(sum):
    if sum[j] - sum[i] > N:
        i += 1
    elif sum[j] - sum[i] < N:
        j += 1
    else:
        res += 1
        j += 1
print(res)
