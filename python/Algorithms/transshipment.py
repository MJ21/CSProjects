#Michael Flath
#Group 24
#CS325 Project 3

import pulp
from pulp import *

# declare your variables
x1 = LpVariable("Xp1w1", 0, 1000)   # 0<= x1 <= 1000
x2 = LpVariable("Xp1w2", 0, 1000) # 0<= x2 <= 1000
x3 = LpVariable("Xp2w1", 0, 1000)   # 0<= x3 <= 1000
x4 = LpVariable("Xp2w2", 0, 1000) # 0<= x4 <= 1000
x5 = LpVariable("Xp3w1", 0, 1000)   # 0<= x5 <= 1000
x6 = LpVariable("Xp3w2", 0, 1000) # 0<= x6 <= 1000
x7 = LpVariable("Xp3w3", 0, 1000)   # 0<= x7 <= 1000
x8 = LpVariable("Xp4w2", 0, 1000) # 0<= x8 <= 1000
x9 = LpVariable("Xp4w3", 0, 1000)   # 0<= x9 <= 1000
x10 = LpVariable("Xw1r1", 0, 1000) # 0<= x10 <= 1000
x11 = LpVariable("Xw1r2", 0, 1000)   # 0<= x11 <= 1000
x12 = LpVariable("Xw1r3", 0, 1000) # 0<= x12 <= 1000
x13 = LpVariable("Xw1r4", 0, 1000) # 0<= x13 <= 1000
x14 = LpVariable("Xw2r3", 0, 1000)   # 0<= x14 <= 1000
x15 = LpVariable("Xw2r4", 0, 1000) # 0<= x15 <= 1000
x16 = LpVariable("Xw2r5", 0, 1000) # 0<= x16 <= 1000
x17 = LpVariable("Xw2r6", 0, 1000)   # 0<= x17 <= 1000
x18 = LpVariable("Xw3r4", 0, 1000) # 0<= x18 <= 1000
x19 = LpVariable("Xw3r5", 0, 1000) # 0<= x19 <= 1000
x20 = LpVariable("Xw3r6", 0, 1000)   # 0<= x20 <= 1000
x21 = LpVariable("Xw3r7", 0, 1000) # 0<= x21 <= 1000

# defines the problem
prob = LpProblem("problem", LpMinimize)
 
# defines the constraints
#Supply constraints 
prob += x1+x2 <= 150 
prob += x3+x4 <= 450
prob += x5+x6+x7 <= 250
prob += x8+x9 <= 150

#plant->warehouse == warehouse->retailer
prob += x1+x3+x5 == x10+x11+x12+x13 
prob += x2+x4+x6+x8 == x14+x15+x16+x17
prob += x7+x9 == x18+x19+x20+x21 

#Demand constraints
prob += x10 >= 100
prob += x11 >= 150 
prob += x12+x14 >= 100
prob += x13+x15+x18 >= 200
prob += x16+x19 >= 200
prob += x17+x20 >= 150
prob += x21 >= 100 

# defines the objective function to maximize
prob += 10*x1+15*x2+11*x3+8*x4+13*x5+8*x6+9*x7+14*x8+8*x9+5*x10+6*x11+7*x12+10*x13+12*x14+8*x15+10*x16+14*x17+14*x18+12*x19+12*x20+6*x21
 
# solve the problem
status = prob.solve()
print LpStatus[status]
 
# print the results

print "Xp1w1 %s " % value(x1)
print "Xp1w2 %s " % value(x2)
print "Xp2w1 %s " % value(x3)
print "Xp2w2 %s " % value(x4)
print "Xp3w1 %s " % value(x5)
print "Xp3w2 %s " % value(x6)
print "Xp3w3 %s " % value(x7)
print "Xp4w2 %s " % value(x8)
print "Xp4w3 %s " % value(x9)
print "Xw1r1 %s " % value(x10)
print "Xw1r2 %s " % value(x11)
print "Xw1r3 %s " % value(x12)
print "Xw1r4 %s " % value(x13)
print "Xw2r3 %s " % value(x14)
print "Xw2r4 %s " % value(x15)
print "Xw2r5 %s " % value(x16)
print "Xw2r6 %s " % value(x17)
print "Xw3r4 %s " % value(x18)
print "Xw3r5 %s " % value(x19)
print "Xw3r6 %s " % value(x20)
print "Xw3r7 %s " % value(x21)

