N = int(input())
checked = [True for i in range(N + 1)]
checked[1] = False

for i in range(2, int(N**0.5) + 1):
    if not checked[i]:
        continue
    for j in range(i * 2, N + 1, i):
        checked[j] = False

sm = [0]
for i in range(2, N + 1):
    if not checked[i]:
        continue
    sm.append(sm[-1] + i)

i, j = 0, 1
res = 0

while j < len(sm):
    if sm[j] - sm[i] == N:
        res += 1

    if sm[j] - sm[i] > N:
        i += 1
    else:
        j += 1

print(res)
