n = int(input())
s = list(map(int,input().split()))
A = [0]*(n+1)
chan = 1
le = 0
kq = 0
for i in range(1,n+1):
    A[i] = A[i-1] + s[i-1]
    if A[i] %2 == 0:
        kq += chan
        chan += 1
    else:
        kq += le
        le += 1
print(kq)
