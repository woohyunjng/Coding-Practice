N = int(input())
arr = []

for i in range(N):
    arr.append(input())

lst = [
    "Never gonna give you up",
    "Never gonna let you down",
    "Never gonna run around and desert you",
    "Never gonna make you cry",
    "Never gonna say goodbye",
    "Never gonna tell a lie and hurt you",
    "Never gonna stop",
]

if all([i in lst for i in arr]):
    print("No")
else:
    print("Yes")
