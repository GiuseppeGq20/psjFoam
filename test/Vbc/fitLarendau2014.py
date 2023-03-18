import numpy as np
import matplotlib.pyplot as plt
# define fit parameters

f=2e6/3
A=-4000
d=5.7e5

t = np.linspace(0,10e-6,1000)
V=A*np.exp(-d*t)*np.cos(2*np.pi*f*t)

plt.plot(t,V)
plt.show()
