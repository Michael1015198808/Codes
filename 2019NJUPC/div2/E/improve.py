n,m=map(int,input().split())
mat=[ list(map(int,input().split())) for _ in range(0,n)]
tmp=max(max(num) for num in mat)
    print('\n'.join([''.join([("." if mat[i][j]==0 else "#") for j in range(0,m)])for i in range(0,n)]))#front
print()
    print('\n'.join([''.join([("#" if max(mat[k][i] for k in range(0,n))>j else ".") for i in range(0,m) ])for j in range(0,tmp)]))#left
print()
    print('\n'.join([''.join([("#" if max(mat[i][k] for k in range(0,m))>j else ".") for i in range(0,n) ])for j in range(0,tmp)]))#upper
