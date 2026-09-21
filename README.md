I'm no expert, by so far with my understanding here is my explanation.
Also I will avoid embedded related stuff.

Say we're writing some program to solve some geometry problem in C.

### struct

You can think `struct` as something used for grouping related data together. 

let's represent a point in 2D in code. A point consists of 2 co-ordinates 
`x` and `y`.

```c
struct Point {
  int x, y;
}
```

Now imagine a rectangle. A rectangle can be uniquely defined with 2 points (2 corners to be specific). So let's represent a rectangle in code.

```c
struct Rectangle {
  // you can take any opposite corners
  struct Point top_left;
  struct Point bottom_right;
}
```

### typedef
We can see how ugly that `Rectangle` struct is. When typedef is used with struct you can avoid that ugly part.

```c
typedef struct {
  int x, y;
} Point;

typedef struct {
  Point top_left;
  Point bottom_right;
} Rectangle;

// declaring a Rectangle also clean
Rectangle rect;
```
