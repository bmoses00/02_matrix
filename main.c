#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ml6.h"
#include "display.h"
#include "draw.h"
#include "matrix.h"

int main() {
  // testing matrix math
  struct matrix *edges;
  struct matrix *edges_2;

  edges = new_matrix(4, 4);
  edges_2 = new_matrix(4, 4);

  printf("\nTesting add_edge. Adding (2, 5, 4) and (7, 1, 2) to m2:\n");
  add_edge(edges_2, 2, 5, 4, 7, 1, 2);
  print_matrix(edges_2);

  printf("\nTesting ident on m1:\n");
  ident(edges);
  print_matrix(edges);

  printf("\nTesting matrix_mult m1 * m2:\n");
  matrix_mult(edges, edges_2);
  print_matrix(edges_2);

  printf("\nModifying m1 to be:\n");
  double** m = edges->m;
  m[0][0] = 2; m[0][1] = 7; m[0][2] = 3; m[0][3] = 1;
  m[1][0] = 5; m[1][1] = 4; m[1][2] = 2; m[1][3] = 4;
  m[2][0] = 3; m[2][1] = 5; m[2][2] = 5; m[2][3] = 7;
  m[3][0] = 1; m[3][1] = 0; m[3][2] = 1; m[3][3] = 6;
  print_matrix(edges);

  printf("\nTesting matrix_mult m1 * m2:\n");
  matrix_mult(edges, edges_2);
  print_matrix(edges_2);

  // creating drawing
  color c;
  screen s;

  clear_screen(s);

  struct matrix *drawing = new_matrix(4, 50);

  c.red = 0;
  c.green = 0;
  c.blue = 0;

  // H
  add_edge_2d(drawing, 100, 300, 120, 300);
  add_edge_2d(drawing, 120, 300, 120, 340);
  add_edge_2d(drawing, 120, 340, 140, 340);
  add_edge_2d(drawing, 140, 340, 140, 300);
  add_edge_2d(drawing, 140, 300, 160, 300);
  add_edge_2d(drawing, 160, 300, 160, 400);
  add_edge_2d(drawing, 160, 400, 140, 400);
  add_edge_2d(drawing, 140, 400, 140, 360);
  add_edge_2d(drawing, 140, 360, 120, 360);
  add_edge_2d(drawing, 120, 360, 120, 400);
  add_edge_2d(drawing, 120, 400, 100, 400);
  add_edge_2d(drawing, 100, 400, 100, 300);

  // e
  add_edge_2d(drawing, 180, 300, 240, 300);
  add_edge_2d(drawing, 240, 300, 240, 315);
  add_edge_2d(drawing, 240, 315, 195, 315);
  add_edge_2d(drawing, 195, 315, 195, 325);
  add_edge_2d(drawing, 195, 325, 240, 325);
  add_edge_2d(drawing, 240, 325, 240, 355);
  add_edge_2d(drawing, 240, 355, 180, 355);
  add_edge_2d(drawing, 180, 355, 180, 300);

  add_edge_2d(drawing, 195, 345, 230, 345);
  add_edge_2d(drawing, 230, 345, 230, 335);
  add_edge_2d(drawing, 230, 335, 195, 335);
  add_edge_2d(drawing, 195, 335, 195, 345);

  // l
  add_edge_2d(drawing, 260, 300, 280, 300);
  add_edge_2d(drawing, 280, 300, 280, 380);
  add_edge_2d(drawing, 280, 380, 260, 380);
  add_edge_2d(drawing, 260, 380, 260, 300);

  // l
  add_edge_2d(drawing, 300, 300, 320, 300);
  add_edge_2d(drawing, 320, 300, 320, 380);
  add_edge_2d(drawing, 320, 380, 300, 380);
  add_edge_2d(drawing, 300, 380, 300, 300);

  // o
  add_edge_2d(drawing, 340, 300, 400, 300);
  add_edge_2d(drawing, 400, 300, 400, 360);
  add_edge_2d(drawing, 400, 360, 340, 360);
  add_edge_2d(drawing, 340, 360, 340, 300);

  add_edge_2d(drawing, 360, 320, 380, 320);
  add_edge_2d(drawing, 380, 320, 380, 340);
  add_edge_2d(drawing, 380, 340, 360, 340);
  add_edge_2d(drawing, 360, 340, 360, 320);

  // W
  add_edge_2d(drawing, 80, 160, 100, 160);
  add_edge_2d(drawing, 100, 160, 120, 190);
  add_edge_2d(drawing, 120, 190, 140, 160);
  add_edge_2d(drawing, 140, 160, 160, 160);
  add_edge_2d(drawing, 160, 160, 180, 240);
  add_edge_2d(drawing, 180, 240, 160, 240);
  add_edge_2d(drawing, 160, 240, 145, 190);
  add_edge_2d(drawing, 145, 190, 120, 230);
  add_edge_2d(drawing, 120, 230, 95, 190);
  add_edge_2d(drawing, 95, 190, 80, 240);
  add_edge_2d(drawing, 80, 240, 60, 240);
  add_edge_2d(drawing, 60, 240, 80, 160);

  // o
  add_edge_2d(drawing, 200, 160, 260, 160);
  add_edge_2d(drawing, 260, 160, 260, 220);
  add_edge_2d(drawing, 260, 220, 200, 220);
  add_edge_2d(drawing, 200, 220, 200, 160);

  add_edge_2d(drawing, 220, 180, 240, 180);
  add_edge_2d(drawing, 240, 180, 240, 200);
  add_edge_2d(drawing, 240, 200, 220, 200);
  add_edge_2d(drawing, 220, 200, 220, 180);

  // r
  add_edge_2d(drawing, 280, 160, 300, 160);
  add_edge_2d(drawing, 300, 160, 300, 200);
  add_edge_2d(drawing, 300, 200, 340, 200);
  add_edge_2d(drawing, 340, 200, 340, 220);
  add_edge_2d(drawing, 340, 220, 280, 220);
  add_edge_2d(drawing, 280, 220, 280, 160);

  // l
  add_edge_2d(drawing, 360, 160, 380, 160);
  add_edge_2d(drawing, 380, 160, 380, 240);
  add_edge_2d(drawing, 380, 240, 360, 240);
  add_edge_2d(drawing, 360, 240, 360, 160);

  // d
  add_edge_2d(drawing, 400, 160, 460, 160);
  add_edge_2d(drawing, 440, 260, 440, 220);
  add_edge_2d(drawing, 460, 160, 460, 260);
  add_edge_2d(drawing, 460, 260, 440, 260);
  add_edge_2d(drawing, 440, 260, 440, 220);
  add_edge_2d(drawing, 440, 220, 400, 220);
  add_edge_2d(drawing, 400, 220, 400, 160);

  add_edge_2d(drawing, 420, 180, 440, 180);
  add_edge_2d(drawing, 440, 180, 440, 200);
  add_edge_2d(drawing, 440, 200, 420, 200);
  add_edge_2d(drawing, 420, 200, 420, 180);

  draw_lines(drawing, s, c);
  save_ppm_ascii(s, "image.ppm");
  display(s);
}
