def perm(arr,i,n,soln):
    if i == n-1:
        print(arr)
        # Copy because python stores elements as object not as copy of objects
        soln.append(arr.copy())
        return 
    if i > n-1:
        return 
    for k in range(i,n):
        arr[i],arr[k] = arr[k],arr[i]
        perm(arr,i+1,n,soln)
        arr[i],arr[k] = arr[k],arr[i]
    return 

arr = [i for i in range(1,4)]
soln = []
perm(arr,0,3,soln)
print("------------\n",soln)

