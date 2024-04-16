first = int("".join(input().split()), 2)
second = int("".join(input().split()), 2)
print(bin(first + second)[2:].rjust(6, "0"))
