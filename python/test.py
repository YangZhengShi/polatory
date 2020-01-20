#!/usr/bin/env python
import numpy as np
import polatory

points = np.array([[0.0, 0.0, 0.0], [1.0, 0.0, 0.0], [0.0, 1.0, 0.0]])
values = np.array([1.0, 2.0, 3.0])
idcs = polatory.DistanceFilter(points, 1e-10).filtered_indices
points, values = points[idcs, :], values[idcs]

rbf = polatory.Biharmonic3D([1.0])
rbf.anisotropy = np.diag([1.0, 2.0, 3.0])
m = polatory.Model(rbf, 3, 0)
m.nugget = 0.1
inter = polatory.Interpolant(m)
inter.fit(points, values, 1e-5)

print('values:', inter.evaluate(points))
print('centers:', inter.centers())
print('weights:', inter.weights())
