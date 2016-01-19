#Chain Matrix Multiplication algorithm
#Given a sequence of matrices, the goal is to find the most efficient way to multiply these matrices. -Wiki

#Naive algorithm - computes all possible parenthesizations.
#Time Complexity: Exponential O(4^n)

import sys

def recMatrixChain(arr, i, j):
  if i == j:
    return 0
  else:
    max = sys.maxint
    for k in range(i, j):
      cost = recMatrixChain(arr, i, k) + recMatrixChain(arr, k+1, j) + arr[i-1]*arr[k]*arr[j] 
      if cost < max:
        max = cost 
  return max 
  
def keyify(a,b):
  return str(a)+','+str(b)

#Dynamic programming: Bottum-up Matrix Chain Multiplication
#Time complexity: O(n^3)

def MatrixChainDP(arr, n):
  m, s = {}, {}
  for i in range(1, n+1):
    m[keyify(i,i)] = 0
  for L in range(2, n+1):
    for i in range(1, n-L+2):
      j = i+L-1
      m[keyify(i,j)] = sys.maxint 
      for k in range(i, j):
        cost = m[keyify(i,k)]+m[keyify(k+1,j)]+arr[i-1]*arr[k]*arr[j]
        if cost < m[keyify(i,j)]:
          m[keyify(i,j)] = cost 
          s[keyify(i,j)] = k 
  return m, s 
  
def print_parens(s, i, j):
  result = ''
  if i == j:
    return "A"+str(i)
  else:
    result += "("
    result += print_parens(s, i, s[keyify(i,j)])
    result += print_parens(s, s[keyify(i,j)]+1,j)
    result += ")"
  return result 
 
#Given matrices 50 x 20, 20 x 50, 50 x 1
#initial i = 1, Total matrices n = 3
arr = [50, 20, 50, 1]
print(recMatrixChain(arr, 1, len(arr)-1))
 
arr1 = [30,35,15,5,10,20,25]
best, order = MatrixChainDP(arr1, len(arr1)-1)
print "Optimal solution: # of multiplications: ", best[keyify(1,len(arr1)-1)]
print "Order of operations", print_parens(order,1, len(arr1)-1)

