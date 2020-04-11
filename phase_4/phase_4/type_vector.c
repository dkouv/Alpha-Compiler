#include "library.h"
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

int
table_find_element(Dynamic_Table* vector, table_type value, int type){
    int i;
    if(vector->size == 0){
        
        return -1;
    }  
    table_type t;
    for(i = 0; i < vector->size; i++){
        switch(type){
            case 0:
                if(strcmp(value.string, table_get(vector, i).string) == 0){
                    return i;
                }
                break;
        
            case 1:
                /* einai double edw */

                if(value.num_type->d == table_get(vector, i).num_type->d){
                    return i;
                }
                break;
            case 2:

                t.function = table_get(vector, i).function;
                if(strcmp(value.function->name, t.function->name) == 0 && value.function->total_arguments == t.function->total_arguments
                && value.function->line == t.function->line){
                    return i;
                }      
                break;
            case 3:
                if(strcmp(value.libfunc, table_get(vector, i).libfunc) == 0){

                    return i;
                }
                break;
            case 4:
                if(value.num_type->i == table_get(vector, i).num_type->i){
                    return i;
                }
                break;
            default:
              return -1;

        } 

    
    }
    return -1;

}