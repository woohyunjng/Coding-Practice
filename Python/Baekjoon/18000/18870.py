N = int(input())
X = list(map(int, input().split()))

S = list(sorted(set(X)))
d = {}

for i in range(len(S)):
    d[S[i]] = i

for i in X:
    print(d[i], end=" ")
