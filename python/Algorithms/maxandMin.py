#Find the maximum and minimum numbers in an array in which numbers are first increasing then decreasing.
#
#The first algorithm finds the max and min in O(n) linear time.
#The second algorithm is a modified binary search which finds the max and min in O(logn) in logarithmic time. 

def linearMaxnMin(alist):
  if alist[0] < alist[len(alist)-1]:
    min = alist[0]
  else: 
    min = alist[len(alist)-1]
    
  max = alist[0]
  for i in range(1,len(alist)):
    if max < alist[i]:
      max = alist[i]
      
  return max, min 
  
#Iterative Modified Binary Search for max number in an array
def binaryMax(alist):
  first = 0
  last = len(alist) - 1
  max = alist[0]
  
  #If only 2 integers in array, max equals the greater element
  if len(alist) == 2:
    if alist[0] > alist[1]:
      return alist[0] 
    else:
      return alist[1] 
  
  while first <= last:
    mid = (first + last) // 2
    #mid cannot == 0
    if mid == 0:
      mid += 1
      
    if alist[mid] > alist[mid-1] and alist[mid] > alist[mid+1]:
      max = alist[mid] 
      return max 
    elif alist[mid] > alist[mid-1] and alist[mid] < alist[mid+1]:
      first = mid + 1 
    else:
      last = mid - 1 

#Recursive Modified Binary search for max int
def recBinMax(alist, first, last):
  if first == last:
    return alist[first]
  
  #two elements left: the first is greater than the last
  if first == last and alist[first] > alist[last]:
    return alist[first]
    
  #two elements left: the last is greater than the first
  if first == last and alist[first] < alist[last]:
    return alist[last]
    
  mid = first + last // 2

  if alist[mid] > alist[mid-1] and alist[mid] > alist[mid+1]:
    return alist[mid]
  elif alist[mid] > alist[mid-1] and alist[mid] < alist[mid+1]:
    return recBinMax(alist, mid+1, last)
  else:
    return recBinMax(alist, first, mid-1)
    

arr = [-2, -1, 5, 10, 18, 15, 11, 8, 1]  

arra = [-3, 1, 5, 11, 23, 6]

arrb = [1, 3, 28, 15, 13, 10, -2] 

arrc = [-1, 10] 

arrd = [1, 52, 23, 18, 10]

a, b = linearMaxnMin(arr)
print "Linear max and min: %i : %i" % (a, b)
'''
x = binaryMax(arr)
print "Iterative Binary Max: %i " % x 

y = binaryMax(arra)
print "Iterative Binary Max: %i " % y 

z = binaryMax(arrb)
print "Iterative Binary Max: %i " % z 

w = binaryMax(arrc)
print "Iterative Binary Max: %i " % w 

v = binaryMax(arrd)
print "Iterative Binary Max: %i " % v 

'''
z = recBinMax(arr, 0, len(arr)-1)
print "Recursive Binary Max: %i" % z 

x = recBinMax(arra, 0, len(arr)-1)
print "Recursive Binary Max: %i" % x 

y = recBinMax(arrb, 0, len(arr)-1)
print "Recursive Binary Max: %i" % y 

v = recBinMax(arrd, 0, len(arr)-1)
print "Recursive Binary Max: %i" % v 
  
  