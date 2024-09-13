K = int(input())
S = list(input())

res = []
for i in S:
    res.append(chr((ord(i) + K)))

print("".join(res))
