#include <stdio.h>
#define max(a, b) a > b ? a : b
#define min(a, b) a < b ? a : b

struct point {
  int x;
  int y;
};

struct rect {
  struct point p1;
  struct point p2;
};

void toPositiveRect(struct rect *rectP);
int isInRect(struct point *p, struct rect *rectP);

int main() {
  struct rect rect1;

  rect1.p1.x = 0;
  rect1.p1.y = 0;
  rect1.p2.x = 10;
  rect1.p2.y = 20;

  struct point p1 = {
      .x = 5,
      .y = 10,
  };
  struct point p2 = {
      .x = 15,
      .y = 10,
  };

  toPositiveRect(&rect1);

  printf("%d\n", isInRect(&p1, &rect1));
  printf("%d\n", isInRect(&p2, &rect1));
}

void toPositiveRect(struct rect *rectP) {
  struct rect temp = *rectP;
  (*rectP).p1.x = max(temp.p1.x, temp.p2.x);
  (*rectP).p1.y = max(temp.p1.y, temp.p2.y);
  (*rectP).p2.x = min(temp.p1.x, temp.p2.x);
  (*rectP).p2.y = min(temp.p1.y, temp.p2.y);
}

int isInRect(struct point *p, struct rect *rectP) {
  return ((*p).x < (*rectP).p1.x && (*p).x > (*rectP).p2.x) &&
         ((*p).y < (*rectP).p1.y && (*p).y > (*rectP).p2.y);
}
