N = int(input())
two, five = 0, 0

while not N % 2:
    N //= 2
    two += 1

while not N % 5:
    N //= 5
    five += 1

if N != 1:
    res = -1
elif two > five:
    res = -1
else:
    res = five * 2 - two

print(res)
