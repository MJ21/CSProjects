"""
Michael Flath
1)Program a Queue
A Queue data structure operates in the order of First in First out

2)Program a Deque 
A Deque data structure operates as a stack or a queue. Items can be added/removed at the front or the rear.
"""

"""**************** QUEUE *******************"""
class Queue:
  def __init__(self):
    self.items = []
    
  def enque(self, item):
    self.items.insert(0,item)
    
  def deque(self):
    return self.items.pop()
    
  def isEmpty(self):
    return self.items == []
    
  def size(self):
    return len(self.items)
    
"""**************** DEQUE *******************"""  
class Deque:
  def __init__(self):
    self.items = []
    
  def addFront(self, item):
    self.items.append(item)
    
  def addRear(self, item):
    self.items.insert(0,item)
    
  def removeFront(self):
    return self.items.pop()
    
  def removeRear(self):
    return self.items.pop(0)
    
  def isEmpty(self):
    return self.items == []
    
  def size(self):
    return len(self.items)
    
def palChecker(newString):
  chardeq = Deque()
  
  for ch in newString:
    chardeq.addRear(ch)
    
  stillEqual = True 
  while chardeq.size() > 1 & stillEqual:
    first = chardeq.removeFront()
    last = chardeq.removeRear()
    if first != last:
      stillEqual = False 
      
  return stillEqual
    
    
"""
Demonstrate Queue operations:

"""    
"""
q = Queue()

print q.isEmpty()

for x in range(2,40, 2):
  q.enque(x)
  print "Enque %d" % (x)

print "Deque: "
  
print q.deque()
print q.deque()
print q.deque()

print "Size: "

print q.size()
"""

"""
Demonstrate Deque operations:

"""
d = Deque()

for num in range(1, 25, 2):
  d.addFront(num)
  
for num in range(24, 50, 2):
  d.addRear(num)
  
print d.items 

print "Remove Front: "
print d.removeFront()
print d.removeFront()

print "Remove Rear: "
print d.removeRear()
print d.removeRear()

stringOne = "ThisISnotApalindrome"
stringTwo = "abcdcba"

print "Palindrome Results: "
print palChecker(stringOne)
print palChecker(stringTwo)