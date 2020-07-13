import pylab
from matplotlib import cm
from mpl_toolkits.mplot3d import Axes3D
import numpy as np

np.seterr(divide='ignore', invalid='ignore')


def makeData():
    um = np.arange(0, 2 * np.pi, 0.008)
    vm = np.arange(-1, 1, 0.008)
    u, v = np.meshgrid(um, vm)
    xgrid = (1 + (v / 2) * np.cos(u / 2)) * np.cos(u)
    ygrid = (1 + (v / 2) * np.cos(u / 2)) * np.sin(u)
    zgrid = (v / 2) * np.sin(u / 2)
    return xgrid, ygrid, zgrid