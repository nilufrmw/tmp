#include <stdio.h>

typedef struct {
  int x, y;
} Point;

typedef struct {
  Point top_left;
  Point bottom_right;
} Rectangle;

void move_right(Rectangle *r, int offset) {
  r->top_left.x += offset;
  r->bottom_right.x += offset;
}

int main(void) {
  Rectangle rect = {
    .top_left = { .x = 0, .y = 10 },
    .bottom_right = { .x = 20, .y = 0 }
  };
  
  printf("top-left: (%d, %d)\n", rect.top_left.x, rect.top_left.y);
  printf("bottom-right: (%d, %d)\n", rect.bottom_right.x, rect.bottom_right.y);
  printf("\n");  
  // pass the memory address using '&'
  // shift rectangle to right by 5 units
  move_right(&rect, 5);

  printf("rectangle shifted to right by 5 units\n");
  printf("\n");

  printf("top-left: (%d, %d)\n", rect.top_left.x, rect.top_left.y);
  printf("bottom-right: (%d, %d)\n", rect.bottom_right.x, rect.bottom_right.y);

  return 0;
}
