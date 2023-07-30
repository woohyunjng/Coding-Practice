while True:
    A = list(sorted(map(int, input().split())))
    if not sum(A):
        break

    S = len(set(A))

    if sum(A) <= A[-1] * 2:
        print("Invalid")
    elif S == 1:
        print("Equilateral")
    elif S == 2:
        print("Isosceles")
    else:
        print("Scalene")
