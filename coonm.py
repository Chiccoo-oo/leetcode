t = int(input())
for _ in range(t):
    n = int(input())
    s = input().strip()
    if s[0] == s[-1]:
        print("Yes")
    else:
        print("No")
