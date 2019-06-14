import numpy as np
import matplotlib.pyplot as plt
import imageio

print("Running GrahamScan Visualizer....")
fileName1 = "graham_output.txt"
fileName2 = "points.txt"

with open(fileName2) as f:
    lines = f.readlines()

points = np.ndarray((len(lines), 2))
i = 0
for line in lines:
    x, y = list(map(float, line.split()))[0:2]
    points[i][0] = x
    points[i][1] = y
    i = i+1

x_cord = []
y_cord = []

gif = []

fig, ax = plt.subplots(figsize=(5,5))

for point in points:
    x_cord.append(point[0])
    y_cord.append(point[1])    
ax.axis("off")
ax.scatter(x_cord, y_cord, marker = 'o', s = 15, color = 'blue')

fig.canvas.draw()
image = np.frombuffer(fig.canvas.tostring_rgb(), dtype='uint8')
gif.append(image.reshape(fig.canvas.get_width_height()[::-1] + (3,)))

with open(fileName1) as f:
     lines = f.readlines()

graham = []
fig_list = []

for line in lines:
    if line == '$\n':
        graham.append(fig_list+[0])
        fig_list = []
    elif line == '$$\n':
        graham.append(fig_list+[1])
        fig_list = []
    else:
        fig_list.append(list(map(float, line.split())))

#print(graham)

graham.append(graham[-1][:-1] + [graham[-1][0], graham[-1][-1]])
graham = np.array(graham)
#print(graham[-1])


for figlist in graham:
    #print(figlist)
    flag = figlist[-1]
    fig, ax = plt.subplots(figsize=(5,5))
    figlist = np.array(figlist[:-1])
    ax.axis("off")
    ax.scatter(x_cord, y_cord, color = 'blue', marker = 'o', s = 15)
    if flag == 0:
        ax.plot(figlist[:,0], figlist[:,1], linewidth = 2, color = 'green')    
    else:
        ax.plot(figlist[2:,0], figlist[2:,1], linewidth = 2, color = 'green')
        ax.plot(figlist[:3,0], figlist[:3,1], linewidth = 2, color = 'red')
    fig.canvas.draw()
    image = np.frombuffer(fig.canvas.tostring_rgb(), dtype='uint8')
    gif.append(image.reshape(fig.canvas.get_width_height()[::-1] + (3,)))
    #plt.show()

imageio.mimsave('./graham.gif', gif, fps=2)