A = input()
B = input()
C = input()


def get(N):
    if not N % 3 and not N % 5:
        return "FizzBuzz"
    elif not N % 3:
        return "Fizz"
    elif not N % 5:
        return "Buzz"
    else:
        return N


if A.isdigit():
    print(get(int(A) + 3))
elif B.isdigit():
    print(get(int(B) + 2))
else:
    print(get(int(C) + 1))
