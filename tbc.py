n,q = map(int,input().split())
A = list(map(int,input().split()))
S = [0]*(n+1)
kq = []
for i in range(1,n+1):
    S[i] = S[i-1]+A[i-1]
for i in range(q):
    l,r = map(int,input().split())
    kq.append((S[r]-S[l-1])/(r-l+1))
for i in kq:
    print("{:.3f}".format(i))
