import pylab
from matplotlib import cm
from mpl_toolkits.mplot3d import Axes3D
import matplotlib.pyplot as plt
from matplotlib.colors import LinearSegmentedColormap
import numpy as np

def makeData():
    z = np.arange(0, 20, 0.1)
    y = np.arange(0, 20, 0.1)
    zgrid, ygrid = np.meshgrid(z, y)
    xgrid = 3 - ygrid
    return xgrid, ygrid, zgrid

x, y, z = makeData()

fig = pylab.figure()
axes = Axes3D(fig)

axes.plot_surface(x, y, z, rstride = 7, cstride = 7, color = 'c', cmap = cm.jet)

pylab.show()
