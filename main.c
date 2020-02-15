#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ml6.h"
#include "display.h"
#include "draw.h"
#include "matrix.h"

int main() {

  color c;
  screen s;

  clear_screen(s);

  struct matrix *edges;
  struct matrix *edges_2;
  struct matrix *drawing;


  edges = new_matrix(4, 4);
  edges_2 = new_matrix(4, 4);

  add_edge(edges, 2, 5, 4, 7, 1, 2);
  add_edge(edges, 6, 9, 2, 5, 2, 3);

  add_edge(edges_2, 2, 6, 4, 2, 3, 4);
  add_edge(edges_2, 8, 1, 0, 4, 2, 4);

  print_matrix(edges);
  printf("------------------------------\n");
  printf("------------------------------\n");
  print_matrix(edges_2);
  printf("------------------------------\n");
  printf("------------------------------\n");
  matrix_mult(edges, edges_2);
  print_matrix(edges_2);

  free_matrix( edges );
  free_matrix( edges_2 );


  drawing = new_matrix(4, 50);

  add_edge(drawing, );

  c.red = 255;
  c.green = 255;
  c.blue = 255;
  draw_lines(edges_2, s, c);

  display(s);

}
