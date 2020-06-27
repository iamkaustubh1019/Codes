def maze( arr,sol,i,j,n,m):
    if i==n-1 and j == m-1:
        sol[i][j] =1
        [print(row) for row in sol]
        print("------End---------")
        return True
    if (i>n-1 or j>m-1):
        return False
    if arr[i][j] == "X":
        return False
    sol[i][j] = 1
    right = maze(arr,sol,i+1,j,n,m)
    down  = maze(arr,sol,i,j+1,n,m)
    sol[i][j] = 0
    if right or down:
        return True
    return False
arr = [["0","0","X","0"],["0","0","0","X"],["0","0","X","0"],["0","0","0","0"]]
soln = arr
[print(row) for row in soln]
print("------End---------")
maze(arr,soln,0,0,4,4)