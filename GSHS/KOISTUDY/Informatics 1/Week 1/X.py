num = int(input())
S = input()

for i in S:
    print(chr(ord(i) + num), end="")
