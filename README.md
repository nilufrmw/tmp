I'm no expert, by so far with my understanding here is my explanation.
Also I will avoid embedded related stuff.

Say we're writing some program to solve some geometry problem in C.
`struct` you can think of something used for grouping related data together. 

let's represent a point in 2D in code. A point consists of 2 co-ordinates 
`x` and `y`.

```c
struct Point {
  int x, y;
}
```
