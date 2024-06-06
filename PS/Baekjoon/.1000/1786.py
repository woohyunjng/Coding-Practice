from sys import stdin

T = stdin.readline().rstrip()
P = stdin.readline().rstrip()

res = []
pi = [0 for i in range(len(P))]
j = 0

for i in range(1, len(P)):
    while j > 0 and P[i] != P[j]:
        j = pi[j - 1]
    if P[i] == P[j]:
        j += 1
        pi[i] = j

j = 0
for i in range(len(T)):
    while j > 0 and T[i] != P[j]:
        j = pi[j - 1]

    if T[i] == P[j]:
        if j == len(P) - 1:
            res.append(i - len(P) + 2)
            j = pi[j]
        else:
            j += 1

print(len(res))
for i in res:
    print(i)
