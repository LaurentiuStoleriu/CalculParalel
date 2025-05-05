import numpy as np
from scipy.integrate import solve_ivp
import matplotlib.pyplot as plt

def syst(t, sol_ini):
    sol0 = sol_ini[1]
    sol1 = 0
    sol2 = sol_ini[3]
    sol3 = -g
    return [sol0, sol1, sol2, sol3]

tmax = 4; numpoints = 100
t_limits = [0, tmax]
t = np.linspace(0, tmax, numpoints)

x0 = 0; y0 = 19; v0 = 27; th = 30; g = 9.81
v0x = v0 * np.cos(np.deg2rad(th)) 
v0y = v0 * np.sin(np.deg2rad(th))

cond_ini = [x0, v0x, y0, v0y]

solvec = solve_ivp(syst, t_limits, cond_ini, t_eval = t)

fig, ax = plt.subplots()
ax.scatter(solvec.y[0], solvec.y[2], s=100, c=solvec.y[2], cmap=plt.cm.viridis)
plt.show()