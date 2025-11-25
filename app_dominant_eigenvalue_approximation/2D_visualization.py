import matplotlib.pyplot as plt
from matplotlib.animation import FuncAnimation, PillowWriter

# ====== 데이터 ======
points = [
    (0.5,0),
    (0.316228,0.948683),
    (0.362446,0.932005),
    (0.36123,0.932477),
    (0.361262,0.932464),
    (0.361261,0.932465),
    (0.361261,0.932465),
    (0.361261,0.932465),
    (0.361261,0.932465),
    (0.361261,0.932465),
    (0.361261,0.932465),
    (0.361261,0.932465),
]

fig = plt.figure()
ax = fig.add_subplot(111)

ax.set_xlim(0, 1)
ax.set_ylim(0, 1)

ax.set_xlabel("x")
ax.set_ylabel("y")

trail_x = []
trail_y = []

arrow = None

def update(frame):
    global arrow
    
    idx = frame % len(points)
    x, y = points[idx]

    trail_x.append(x)
    trail_y.append(y)

    ax.plot(trail_x, trail_y)

    if arrow:
        arrow.remove()

    arrow = ax.quiver(
        0, 0,
        x, y,
        angles='xy',
        scale_units='xy',
        scale=1
    )


ani = FuncAnimation(
    fig, update,
    frames=len(points),
    interval=200,
    repeat=True
)


# ====== GIF 저장 ======
ani.save(
    "app_dominant_eigenvalue_approximation/2d_vector_animation.gif",
    writer=PillowWriter(fps=5)
)

plt.show()
