# minballPy
Port of C++ algorithm for finding smallest enclosing sphere of spheres. Library documentation avaliable [here](http://doc.cgal.org/latest/Bounding_volumes/classCGAL_1_1Min__sphere__of__spheres__d.html#af9d984199150f79be185b3cb526399b9)
For further information about the problem I recommend reading [thesis by Kaspar Fisher](https://www.inf.ethz.ch/personal/emo/DoctThesisFiles/fischer05.pdf).

![alt text](https://github.com/JendaPlhak/minballPy/blob/master/img/example.gif "Example circles")


## Usage:

```python
import random
import minball
spheres = []
for _ in range(10):
    center = [random.random() * 10, random.random() * 10]
    radius = random.random() * 5
    spheres.append(minball.Sphere2D(center, radius))

min_sphere = minball.get_min_sphere2D(spheres)
print(min_sphere.radius, min_sphere.center)
```

## Available dimensions
Dimensions 1D-4D are provided out of the box. If other dimensions are needed, simply
head to [include/minball_py.hpp](https://github.com/JendaPlhak/minballPy/blob/master/include/minball_py.hpp),
change the range and recompile.

## Dependencies
[CGAL](https://github.com/JendaPlhak/minballPy/blob/master/img/example.gif)

`gcc` or `clang` (Clang is default)

## Setup && Build

`make setup && make`
