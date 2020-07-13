import matplotlib.pyplot as plt
import numpy as np
import pylab
from matplotlib import cm #gradient
from mpl_toolkits.mplot3d import Axes3D
import matplotlib.animation as animation
from matplotlib.colors import LinearSegmentedColormap
import PIL
from PIL import Image, ImageDraw

def init():
    line.set_data([], [])
    return line,

def animate(i):
    t = 0.1 * i
    x = t * np.sin(t)
    y = t * np.cos(t)
    xdata.append(x)
    ydata.append(y)
    line.set_data(xdata, ydata)
    return line,

def makeDataM():
    um = np.arange(0, 2 * np.pi, 0.008)
    vm = np.arange(-1, 1, 0.008)
    u, v = np.meshgrid(um, vm)
    xgrid = (1 + (v / 2) * np.cos(u / 2)) * np.cos(u)
    ygrid = (1 + (v / 2) * np.cos(u / 2)) * np.sin(u)
    zgrid = (v / 2) * np.sin(u / 2)
    return xgrid, ygrid, zgrid

def makeData():
    x = np.arange(-10, 10, 0.1)
    y = np.arange(-10, 10, 0.1)
    xgrid, ygrid = np.meshgrid(x, y)
    zgrid = np.sin(xgrid) * np.sin(ygrid) / (xgrid * ygrid)
    return xgrid, ygrid, zgrid

np.seterr(divide='ignore', invalid='ignore')
key = 27
while key != 0:
    print("\nEnter the type of graphics you wanna see:\n1 - 2D\n2 - 3D\n3 - MOBIUS and formula\n4 - Спиралька\n0 - exit")
    key = input()

    if key == '1':
        x = np.linspace(0, 100, 200) #масштаб х, у, шаг
        y = np.sin(x) / x
        plt.title("затухающий синус")
        plt.xlabel("x")
        plt.ylabel("y")
        plt.grid() # сетка
        plt.plot(x, y) # создает график
        plt.show()

    elif key == '3':
        x, y, z = makeDataM()
        fig = pylab.figure()
        axes = Axes3D(fig)
        axes.plot_surface(x, y, z, rstride=18, cstride=18, color='b', cmap=cm.jet)
        pylab.show()
        img = Image.open("mob.png")
        img.show()

    elif key == '2':
        x, y, z = makeData()
        fig = pylab.figure()
        axes = Axes3D(fig)
        axes.plot_surface(x, y, z, rstride=7, cstride=7, color='c', cmap=cm.hot)
        pylab.show()

    elif key == '4':
        plt.style.use('dark_background')
        fig = plt.figure()
        ax = plt.axes(xlim=(-50, 50), ylim=(-50, 50))
        line, = ax.plot([], [], lw=2)
        xdata, ydata = [], []
        plt.title('Создание спирали')
        plt.axis('off') #скрыть оси
        anim = animation.FuncAnimation(fig, animate, init_func=init, frames=500, interval=20, blit=True)
        plt.show()
    elif key == '0':
        exit()
