S = input()
res = set([])

for i in range(0, len(S)):
    for j in range(i, len(S)):
        res.add(S[i : j + 1])

print(len(res))
