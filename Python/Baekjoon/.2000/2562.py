mx, index = -1, 0

for i in range(1, 10):
    N = int(input())
    if N > mx:
        mx = N
        index = i

print(mx)
print(index)
