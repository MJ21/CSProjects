class Stack:
  def __init__(self):
    self.items = []
    
  def isEmpty(self):
    return self.items == []
    
  def push(self, item):
    self.items.append(item)
    
  def pop(self):
    return self.items.pop()
    
  def peek(self):
    return self.items[len(self.items)-1]
    
  def size(self):
    return len(self.items)
  
def bitConvert(number):
  theStack = Stack()
  
  while number > 0:
    result = number % 2
    theStack.push(result)
    number = number // 2
  
  binString = ""
  while not theStack.isEmpty():
    binString = binString + str(theStack.pop())
  return binString
  
finalBit = bitConvert(200)
print(finalBit)

s = Stack()
print(s.isEmpty())
s.push(4)
s.push("Hello")
s.push(2)

print(s.pop())
print(s.pop())
print(s.size())
