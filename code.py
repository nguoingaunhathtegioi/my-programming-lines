n = int(input())
A = [0]*(n+1)
for i in range(n+1):
    if i <= 10:
        A[i] = str(i)
    else:
        k = str(A[i-1])
        if '9' in k:
            if '0' in k:
                A[i] = '1'*(len(k)+1)
            else:
                A[i] = '2'+'0'*len(k)
        else:
            if ('0' in k) and ('1' in k):
                A[i] = '2'*len(k)
            elif '0' in k:
                A[i] = str(int(k[0])+1) + '1'*(len(k)-1)
            else:
                A[i] = str(int(k[0])+1) + '0'*(len(k)-1)
print(A[n])
