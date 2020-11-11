#ifndef INCLUDE_GUARD_OPEN_ADDRESSING_H
#define INCLUDE_GUARD_OPEN_ADDRESSING_H

typedef enum state {
  EMPTY,
  DELETED,
  OCCUPIED
} State;

typedef struct dict_data {
  int name;
  State state;
} DictData;

typedef struct dict_open_addr {
  DictData *H;
  int B;
} DictOpenAddr;

DictOpenAddr *create_dict(int len);
int h(DictOpenAddr *dict, int d, int count);
void insert_hash(DictOpenAddr *dict, int d);
int search_hash(DictOpenAddr *dict, int d);
void delete_hash(DictOpenAddr *dict, int d);
void display(DictOpenAddr *dict);
void delete_dict(DictOpenAddr *dict);
void insert_hash_contiguous(DictOpenAddr *dict, int size, float alpha, int rand_max, int seed);
double cal_average_time(DictOpenAddr *dict, int researchtime, int rand_max, int seed);
#endif  // INCLUDE_GUARD_OPEN_ADDRESSING_H