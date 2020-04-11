#include "avm.h"
void table_init(Dynamic_Table *vector)
{
  // initialize size and capacity
  vector->size = 0;
  vector->capacity = TABLE_INITIAL_CAPACITY;

  // allocate memory for vector->data
  vector->data = calloc(sizeof(union table_type) * vector->capacity, sizeof(union table_type) * vector->capacity);
}

void
table_append(Dynamic_Table *vector, table_type value)
{
  // make sure there's room to expand into
  table_double_capacity_if_full(vector);

  // append the value and increment vector->size
  vector->data[vector->size++] = value;
}

table_type
table_get(Dynamic_Table *vector, int index)
{
  if (index >= vector->size || index < 0) {
    printf("Index %d out of bounds for vector of size %d\n", index, vector->size);
    exit(1);
  }
  return vector->data[index];
}

void
table_set(Dynamic_Table *vector, int index, table_type value)
{
  // zero fill the vector up to the desired index
  while (index >= vector->size) {
    table_append(vector, value);
  }

  // set the value at the desired index
  vector->data[index] = value;
}

void
table_double_capacity_if_full(Dynamic_Table *vector)
{
  if (vector->size >= vector->capacity) {
    // double vector->capacity and resize the allocated memory accordingly
    vector->capacity *= 2;
    vector->data = realloc(vector->data, sizeof(union table_type) * vector->capacity);
  }
}

void
table_free(Dynamic_Table *vector)
{
  free(vector->data);
}



void print_array(Dynamic_Table* vector, int type){
    int i;
    for(i = 0; i < vector->size; i++){
        if(type == 0){
            function f = table_get(vector, i).function;
            printf(MAGENTA"#%d name :%s, total:%d, line:%d\n"RESET, i, f->name, f->local_size,  f->line);
        }else if (type == 1){
            
            double d = table_get(vector, i).d;
            printf(MAGENTA"#%d %f\n"RESET, i, d);
        }else if (type == 2){
            printf(MAGENTA"#%d %s\n"RESET, i, table_get(vector, i).string);
        }
    }


}