def mergesort(arr):
    if len(arr) < 2:
        return arr, 0
    else: 
        half = len(arr) // 2
        left = arr[:half]  
        right = arr[half:]
        left, inv  = mergesort(left)
        right, inv2 = mergesort(right)
        merged, inv3 = merge(left, right)
        return merged, (inv + inv2 + inv3)

    


def merge(left, right):
    srted = []
    i = j = inv =  0
    while i < len(left) and j < len(right):
        if left[i] <= right[j]:
                srted.append(left[i])        
                i+=1 
        else:
                srted.append(right[j])
                inv += (len(left) - i)
                j+=1

    if i < len(left):
        srted.extend(left[i:])

    if j < len(right):
        srted.extend(right[j:])


    return srted, inv


arr3 = []
f = open("numbers.txt", "r")
for line in f:
    arr3.append(int(line.strip('\n'))) 

print(mergesort(arr3))
