#Michael Flath
#isPrime returns if a number is prime or not 
#optPrime is the optimized function of isPrime.
import math

class Primes:
  def __init__(self):
    self.primes = {}
    self.mem = {}
    
  def addPrime(self, newKey, newPrime):
    self.primes[newKey] = newPrime

  def addMem(self, newKey, newCache):
    self.mem[newKey] = newCache
    
def isPrime(num):
  for i in range(2,int(math.sqrt(num)+1)):
    if num % i == 0:
      return False
  return True
    
def optPrime(n):
  p = Primes()  #create Dictionary
  
  #First this conditional checks for even numbers. Even numbers can be excluded and cuts half the list of numbers to check.
  #Secondly, the number is checked with a dictionary of saved odd prime numbers discovered by the function isPrime().
  #Thirdly, the number is checked with a dictionary of already saved non-prime numbers.
  #Finally, a number that is neither in the saved list of primes or non-primes is computed. 
  
  if n % 2 == 0:
    return False  #number is even
  elif n in p.primes:  #hold primes 
    return True 
  elif n in p.mem:   #hold non-primes
    return False 
  else: 
    result = isPrime(n) #if number has not been computed
    if result:
      p.primes[n] = True
    else:
      p.mem[n] = False 
    return result 
    
for x in range(100):
  print "%d %s " % (x, optPrime(x))
  
  
print "Manual input solution"
print("2 %s" % optPrime(2))
print("5 %s" % optPrime(5))
print("98 %s" % optPrime(98))
print("50 %s" % optPrime(50))
print("25 %s" % optPrime(25))
print("100 %s" % optPrime(100))



  
      