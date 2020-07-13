import matplotlib.pyplot as plt
import numpy as np

key = input()
if key == "1":
    print("zalupa")
else:
    np.seterr(divide='ignore', invalid='ignore')
    x = np.linspace(0, 100, 200)
    y = pow(x,-1)*np.sin(x)
    plt.title("затухающий синус")
    plt.xlabel("x")
    plt.ylabel("y")
    plt.grid()
    plt.plot(x, y)
    plt.show()
