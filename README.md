# minballPy
Port of C++ algorithm for finding smallest enclosing sphere of spheres. Library documentation avaliable [here](http://doc.cgal.org/latest/Bounding_volumes/classCGAL_1_1Min__sphere__of__spheres__d.html#af9d984199150f79be185b3cb526399b9)


## Usage:

```python
import minball
spheres = []
for _ in range(10):
    center = [random.random() * 10, random.random() * 10]
    radius = random.random() * 5
    spheres.append(minball.Sphere2D(center, radius))

min_sphere = minball.get_min_sphere2D(spheres)
print(min_sphere.radius, min_sphere.center)
```

## Setup && Build

`make setup`
`make`