import numpy as np 
import matplotlib.pylab as plt 




datos_euler = np.genfromtxt("euler.dat")

time_euler = datos[:,0]
position_euler = datos[:,1]
velocity_euler = datos[:,2]


datos_rk4 = np.genfromtxt("rk4.dat")

time_rk4 = datos[:,0]
position_rk4 = datos[:,1]
velocity_rk4 = datos[:,2]


datos_lf = np.genfromtxt("leapfrog.dat")

time_lf = datos[:,0]
position_lf = datos[:,1]
velocity_lf = datos[:,2]



plt.figure(figsize=(10,7))
plt.subplot(3,3,1)
plt.title("Euler")
plt.plot(time_euler,position_euler)
plt.xlabel("Time")
plt.ylabel("Position")
plt.subplot(3,3,2)
plt.title("RK")
plt.plot(time_rk4,position_rk4)
plt.xlabel("Time")
plt.subplot(3,3,3)
plt.title("Leapfrog")
plt.plot(time_lf,position_lf)
plt.xlabel("Time")
plt.subplot(3,3,4)
plt.plot(time_euler,velocity_euler)
plt.xlabel("Time")
plt.ylabel("Velocity")
plt.subplot(3,3,5)
plt.plot(time_rk4,velocity_rk4)
plt.xlabel("Time")
plt.subplot(3,3,6)
plt.plot(time_lf,velocity_lf)
plt.xlabel("Time")
plt.subplot(3,3,7)
plt.plot(position_euler,velocity_euler)
plt.xlabel("Position")
plt.ylabel("Velocity")
plt.subplot(3,3,8)
plt.plot(position_rk4,velocity_rk4)
plt.xlabel("Position")
plt.subplot(3,3,9)
plt.plot(position_lf,velocity_lf)
plt.xlabel("Position")
plt.savefig("plot.png")








