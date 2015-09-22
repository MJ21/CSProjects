#Priority Queue using a Binary Heap implementation 
#Min Heap 

class BinHeap:
  def __init__(self):
    self.heapList = [0]
    self.size = 0 
    
  #Percolate values upward
  def buildUp(self, i):
    while i // 2 > 0:
      #if child is less than parent value swap positions
      if self.heapList[i] < self.heapList[i//2]:
        tmp = self.heapList[i//2]
        self.heapList[i//2] = self.heapList[i]
        self.heapList[i] = tmp 
        
      i = i // 2
      
  def insert(self, k):
    self.heapList.append(k) 
    self.size += 1
    self.buildUp(self.size) 
    
  #Percolate values downward
  def buildDown(self, i):
    while (i * 2) <= self.size:
      min = self.minChild(i)
      if self.heapList[i] > self.heapList[min]:
        tmp = self.heapList[i]
        self.heapList[i] = self.heapList[min]
        self.heapList[min] = tmp 
      
      i = min 
      
  def minChild(self, i):
    if i * 2 + 1 > self.size:
      return i * 2
    else:
      return i * 2 + 1
      
  def deleteMin(self):
    value = self.heapList[1]
    self.heapList[1] = self.heapList[self.size]
    self.size -= 1
    self.heapList.pop()
    self.buildDown(1)
    return value 
    
  def BuildHeap(self, newlist):
    i = len(newlist) // 2
    self.size = len(newlist)
    self.heapList = [0] + newlist[:]
    while (i > 0):
      self.buildDown(i)
      i -= 1
      
  def showMin(self):
    return self.heapList[1]
    
tree = BinHeap()
tree.insert(100)
tree.insert(55)
tree.insert(23)
tree.insert(500)
tree.insert(250)
tree.insert(5) 
tree.insert(89)


print "Top priority: %i" % tree.showMin()
print "Delete: %i" % tree.deleteMin()
print "Delete: %i" % tree.deleteMin()
print "New Top priority: %i" % tree.showMin()
print "Delete: %i" % tree.deleteMin()
print "Delete: %i" % tree.deleteMin()
print "New Top priority: %i" % tree.showMin()
print "Delete: %i" % tree.deleteMin()
print "Delete: %i" % tree.deleteMin()
print "New Top priority: %i" % tree.showMin()
print "Delete: %i" % tree.deleteMin()
