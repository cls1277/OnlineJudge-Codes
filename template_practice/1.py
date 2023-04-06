from cmath import pi
import math
T = 10
h = 20
g = 9.8
x0 = 1e-8
x = (4*math.pi*math.pi*h)/(g*T*T*math.tanh(x0))
while math.fabs(x-x0)>1e-8 :
    x0 = x
    x = (4*math.pi*math.pi*h)/(g*T*T*math.tanh(x0))
L = 2*math.pi*h/x
k = 2*math.pi/L
c = L/T
print("L=%lf, k=%lf, c=%lf" %(L, k, c))