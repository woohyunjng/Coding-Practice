A = int(input())
B = list(map(int, input()))

for i in reversed(B):
    print(A * i)

print(A * int("".join(map(str, B))))
