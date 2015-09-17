"""
Michael Flath
Practicing Python
This is a Unordered Linked List!
"""
"""************ Node Class *************"""
class Node:
  def __init__(self, initData):
    self.data = initData
    self.next = None
    
  def getData(self):
    return self.data 
    
  def getNext(self):
    return self.next 
  
  def setData(self, newData):
    self.data = newData 
    
  def setNext(self, newNext): 
    self.next = newNext 
    
"""************ List Class *************"""

class UnorderedList:
  def __init__(self):
    self.head = None 
    self.tail = None
    self.size = 0
    
  def isEmpty(self):
    return self.head == None 
    
  def add(self, item):
    temp = Node(item) 
    
    if self.head == None:
      self.head = self.tail = temp 
      self.size = 1
    else:
      temp.setNext(self.head)
      self.head = temp
      self.size += 1
    
  def remove(self, item):
    current = self.head 
    prev = None 
    found = False 
    
    while not found:
      if current.getData() == item:
        found = True 
      else:
        prev = current 
        current = current.getNext()
        
    if prev == None:
      self.head = current.getNext()
    else:
      prev.setNext(current.getNext())
    
    self.size -= 1
      
  def size(self):
    '''current = self.head 
    count = 0 
    while current != None: 
      count += 1 
      current = current.getNext() 
    return count '''
    return self.size 
  
  def search(self, item):
    current = self.head 
    found = False 
    
    while current != None and not found: 
      if current.getData() == item:
        found = True 
      else: 
        current = current.getNext()
        
    return found
    
  def append(self, item):
    newNode = Node(item)
    
    if self.head == None:
      self.head = self.tail = newNode
    else:
      self.tail.setNext(newNode)
      self.tail = newNode
    
    self.size += 1
      
  def index(self, item):
    current = self.head
    position = 0
    while current != None:
      if current.data == item:
        return position
      else:
        position += 1
        current = current.getNext() 
        
    print "Item not present in list"
    return None     
  
  #find index in linked list
  #make sure index is not greater than size of linked list
  #add new item to linked list 
  def insert(self, item, index):
    current = self.head     
    prev = None
    position = 0  
 
    if index < 0 or index > self.size-1:
      print "Insert Error: Invalid index"
      return 
    #else if the index is 0 add item to the front of linked list in Theta(1) time.
    elif index == 0:
      self.add(item)
    #else if the index is the last item, add to the end of the linked list in Theta(1) time.
    elif index == self.size-1:
      self.append(item)
    else:
      while current != None:
        if position == index:
          newNode = Node(item)
          newNode.setNext(current)
          prev.setNext(newNode)
          self.size += 1
          break
        else:
          position += 1
          prev = current
          current = current.next
    
    
#test linked list data structure
list = UnorderedList()
print "Add to list 3, 2, 1"
list.add(3) 
list.add(2)
list.add(1)
print "Append to list 4, 5, 6"
list.append(4)
list.append(5)
list.append(6)
print "Size = %i" % list.size
print "index for 3 is %i" % list.index(3)
print "Remove 3"
list.remove(3)
print "Size = %i" % list.size
print "Add 10 to index 2"
list.insert(10,2)
print "index for 10 is %i" % list.index(10)
print "Search for 5 in list: %s" % list.search(5)
print "Search for 3 in list: %s" % list.search(3)
print "Search for 10 in list: %s" % list.search(10)
print "Add 25 to index 10"
list.insert(25,10)
print "Add 25 to index 5"
list.insert(25,5)
print "Size = %i" % list.size
print "Insert B at index 0"
list.insert("B",0)
print "Size = %i" % list.size
print "Search for B in list: %s" % list.search("B")
print "index for B is %i" % list.index("B")
print "Remove 6"
list.remove(6)
print "Remove 5"
list.remove(5) 
print "Size = %i" % list.size

x = list.head 
while x != None:
  print x.getData()
  x = x.getNext()
