mx, index = -1, 0
for i in range(1, 10):
    A = int(input())
    if A > mx:
        mx = A
        index = i
print(mx)
print(index)
