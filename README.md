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
  // take any opposite corners
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

// declaration clean too
Rectangle rect;
```

### pointers 
To understand pointers in general, we have to talk about memory. Think of computer's memory as a shelf of storage boxes. 

- Normal variable: a box holding actual data
- Pointer variable: a box holding a note with the location of another box

`&` : Where is this box located? <br>
`*` : open that box (more on this `*` symbol below)

```c
int score = 42;    // box 'score' holds 42
int *ptr = &score; // box 'ptr' holds the location of 'score'

*ptr = 100; // open the box 'ptr' points to and change it to 100
// score is now 100
```

`*` has different meaning depending on where it appears. in `int *ptr = &score;` `*` tells to compiler "hey this is a normal box having a regular data, rather it contains location of another box that has an integer data inside. We place address of ( `&`) score box inside this pointer box. 
