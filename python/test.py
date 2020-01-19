import pola
import numpy as np

rbf = pola.biharmonic3d([1.0])
m = pola.model(rbf, 3, 0)
m.nugget = 0.1;
inter = pola.interpolant(m)
points = np.array([[0.0, 0.0, 0.0], [1.0, 0.0, 0.0], [0.0, 1.0, 0.0]], dtype='float64')
values = np.array([1.0, 2.0, 3.0], dtype='float64')
inter.fit(points, values, 1e-5)
print(inter.evaluate(points))
print(inter.centers())
print(inter.weights())
