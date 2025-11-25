import matplotlib.pyplot as plt
from matplotlib.animation import FuncAnimation, PillowWriter

# ====== 데이터 ======
points = [
    (0,0,1),
    (0.507093,0.169031,0.845154),
    (0.456792,0.433953,0.776547),
    (0.439371,0.519008,0.733201),
    (0.432316,0.546288,0.717406),
    (0.429966,0.554928,0.712168),
    (0.429206,0.557674,0.71048),
    (0.428963,0.558547,0.709941),
    (0.428885,0.558825,0.709769),
    (0.428861,0.558914,0.709714),
    (0.428853,0.558942,0.709697),
    (0.42885,0.558951,0.709691),
    (0.428849,0.558953,0.70969),
    (0.428849,0.558954,0.709689),
    (0.428849,0.558955,0.709689),
]

fig = plt.figure()
ax = fig.add_subplot(111, projection='3d')

ax.set_xlim(0, 1)
ax.set_ylim(0, 1)
ax.set_zlim(0, 1)

ax.set_xlabel("x")
ax.set_ylabel("y")
ax.set_zlabel("z")

trail_x = []
trail_y = []
trail_z = []

arrow = None

def update(frame):
    global arrow

    idx = frame % len(points)
    x, y, z = points[idx]

    trail_x.append(x)
    trail_y.append(y)
    trail_z.append(z)

    ax.plot(trail_x, trail_y, trail_z)

    if arrow:
        arrow.remove()

    arrow = ax.quiver(0,0,0, x, y, z)


ani = FuncAnimation(
    fig, update,
    frames=len(points),
    interval=200,
    repeat=True
)

# ====== GIF 자동 저장 ======
ani.save(
    "app_dominant_eigenvalue_approximation/3d_vector_animation.gif",
    writer=PillowWriter(fps=5)
)

plt.show()
