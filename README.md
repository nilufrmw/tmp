I'm no expert, by so far with my understanding here is my explanation.
Also I will avoid embedded related stuff.

Say we're writing some program to solve some geometry problem in C.

### struct

You can think `struct` as something used for grouping related data together. 

let's represent a point in 2D in code. A point consists of 2 co-ordinates 
`x` and `y`. (integer co-ordinates for now)

```c
struct Point {
  int x, y;
};
```

Now imagine a rectangle. A rectangle can be uniquely defined with 2 points (2 opposite corners to be specific). So let's represent a rectangle in code.

```c
struct Rectangle {
  // take any opposite corners
  struct Point top_left;
  struct Point bottom_right;
};
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
- Pointer variable: a box holding location of another box

`&` : Where is this box located? <br>
`*` : open that box (more on this `*` symbol below)

```c
int score = 42;    // box 'score' holds 42
int *ptr = &score; // box 'ptr' holds the location of 'score'

*ptr = 100; // open the box 'ptr' points to and change it to 100
// score is now 100
```

`*` has different meaning depending on where it appears. in `int *ptr = &score;` `*` tells to compiler "hey this is not a normal box having a regular data, rather it contains location of another box that has an integer data inside". We place address of ( `&`) score box inside this pointer box.

in `*ptr = 100;` `*` tells hey go to the (called dereferencing) box that's pointed by this `ptr` box and replacement in this case with value 100.

now what are some use cases of pointers? 
- with arrays
- with functions
- dynamic memory allocation
- complex data structures like linked list, trees, ...
- ... more

I can talk about pointers with functions. (feel free to explore other things)

In C, functions only receive copies by default. Back to our geometry problem.

Why pass a pointer to modify: If you write a function to shift our rectangle across the screen, passing `rect` directly means the function only moves the duplicate/copied value. The original stays where it was (original data is not changed).

```c
// takes a pointer so it modifies the original rectangle
void move_right(Rectangle *r, int offset) {
  r->top_left.x += offset;
  r->bottom_right.x += offset;
}

int main(void) {
  Rectangle rect = {
    .top_left = { .x = 0, .y = 10 },
    .bottom_right = { .x = 20, .y = 0 }
  };
    
  // pass the memory address using '&'
  move_right(&rect, 5);

  // rectangle now shifted to right by 5 units

  return 0;
}
```

Passing by reference is a efficient in terms of memory usage compared passing by value too.
