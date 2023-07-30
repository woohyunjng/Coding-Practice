a = int(input())
b = int(input())
c = int(input())

A = list(sorted([a, b, c]))
S = len(set(A))

if sum(A) != 180:
    print("Error")
elif S == 1:
    print("Equilateral")
elif S == 2:
    print("Isosceles")
else:
    print("Scalene")
