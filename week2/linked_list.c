#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"

Cell *head = NULL;

void insert_cell(Cell *p, int d) {
    Cell *new_cell = (Cell*)malloc(sizeof(Cell));

    new_cell -> data = d;
    new_cell -> next = p->next;
    p->next = new_cell;
}

void insert_cell_top(int d) {
  Cell *new_cell = (Cell*)malloc(sizeof(Cell));
  new_cell->data = d;
  new_cell->next = head;
  head = new_cell;
}

void delete_cell(Cell *p) {
    Cell *free_cell = p->next;
    p-> next = free_cell-> next;
    free(free_cell);
}

void delete_cell_top(void) {
    Cell *head_cell = head;
    free(head);
    head = head_cell->next;
}

void display(void) {
    Cell *display_point = head;
    while(display_point != NULL)
    {
        printf("%d",display_point->data);
        printf(" ");
        display_point = display_point->next;
    }
    printf("\n");
}