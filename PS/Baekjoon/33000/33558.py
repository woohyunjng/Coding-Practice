N, M = map(int, input().split())
U, V = map(int, input().split())

A = []
for i in range(U):
    A.append(input())

res = A.copy()

S = input()
if S == "clamp-to-edge":
    for i in range(U):
        res[i] += res[i][-1] * 200
    for i in range(200):
        res.append(res[U - 1])
elif S == "repeat":
    tmp = []
    for i in range(U):
        S = res[i]
        for j in range(200):
            res[i] += S
        tmp.append(res[i])
    for i in range(200):
        for j in tmp:
            res.append(j)
else:
    tmp = []
    for i in range(U):
        S = res[i]
        for j in range(200):
            S = S[::-1]
            res[i] += S
        tmp.append(res[i])
    for i in range(200):
        tmp.reverse()
        for j in tmp:
            res.append(j)

res = res[:N]
for i in range(len(res)):
    res[i] = res[i][:M]

for i in res:
    print(i)
