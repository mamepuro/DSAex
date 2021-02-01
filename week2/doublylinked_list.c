#include <stdio.h>
#include <stdlib.h>
#include "doublylinked_list.h"

Cell *CreateCell(int d, bool is_head)
{
    Cell *new_cell = (Cell*)malloc(sizeof(Cell));
    new_cell ->is_head = is_head;
    new_cell->data = d;
    new_cell->next = new_cell;
    new_cell->prev = new_cell;
    return new_cell;
}
void InsertNext(Cell *this_cell, Cell *p)
{
    p -> prev = this_cell;
    p -> next = this_cell ->next;
    this_cell -> next -> prev = p;
    this_cell -> next = p;
}
void InsertPrev(Cell *this_cell, Cell *p)
{
    p -> next = this_cell;
    p -> prev = this_cell ->prev;
    this_cell ->prev ->next = p;
    this_cell -> prev = p;
}
void DeleteCell(Cell *this_cell)
{
    this_cell -> prev ->next = this_cell ->next;
    this_cell -> next ->prev = this_cell ->prev;
    free(this_cell);
}
Cell *SearchCell(Cell *this_cell, int d)
{
    Cell *next_cell = this_cell;
    do
    {
        if(next_cell->data == d && (!(next_cell->is_head)))
        {
            return next_cell;
        }
        next_cell = next_cell ->next;
    } while (next_cell != this_cell);
    printf("%d is not found in this list.\n", d);
    return NULL;
}
void Display(Cell *this_cell)
{
    Cell *next_cell = this_cell->next;
    if(this_cell -> next == this_cell && (!(this_cell -> is_head)))
    {
        printf("CAUTION!:This cell is not in a list.\n");
        return;
    }
    do
    {
        if(!next_cell->is_head)
        {
            printf("%d ", next_cell->data);
        }
        next_cell = next_cell ->next;
    } while (next_cell != this_cell);
    printf("\n");
}