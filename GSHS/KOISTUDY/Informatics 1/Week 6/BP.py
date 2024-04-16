A, B = input().split()
res = 0

for i in map(int, A):
    for j in map(int, B):
        res += i * j

print(res)
