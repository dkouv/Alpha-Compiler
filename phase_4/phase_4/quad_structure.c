#include "library.h"

void quad_struct_init(Quad *quad_struct){
  // initialize size and capacitys
  quad_struct->size = 0;
  quad_struct->capacity = QUAD_INITIAL_CAPACITY;

  // allocate memory for quad_struct->data
  quad_struct->data = malloc(sizeof(struct quad) * quad_struct->capacity);
}

void quad_struct_append(Quad *quad_struct, quad value) {
  // make sure there's room to expand into
  quad_struct_double_capacity_if_full(quad_struct);

  // append the value and increment quad_struct->size
  quad_struct->data[quad_struct->size++] = value;
}

quad quad_struct_remove(Quad *quad_struct, int index){
  quad p = quad_struct_get(quad_struct, index - 1);

  if(p == NULL)
    return p;
  
  quad_struct->size--;

  return p;

}
quad quad_struct_get(Quad *quad_struct, int index) {
  if (index >= quad_struct->size || index < 0) {
    //printf("Index %d out of bounds for vector of size %d\n", index, quad_struct->size);
    return NULL;
  }
  return quad_struct->data[index];
}

void quad_struct_set(Quad *quad_struct, int index, quad value) {
  // zero fill the quad_struct up to the desired index
  while (index >= quad_struct->size) {
    
    quad_struct_append(quad_struct, 0);
  }

  // set the value at the desired index
  //printf("VAZW QUAD:%d :%s\n", index, opcode_types[value->op]);

  quad_struct->data[index] = value;


}

void quad_struct_double_capacity_if_full(Quad *quad_struct) {
  if (quad_struct->size >= quad_struct->capacity) {
    // double quad_struct->capacity and resize the allocated memory accordingly
    quad_struct->capacity *= 2;
    quad_struct->data = realloc(quad_struct->data, sizeof(struct quad) * quad_struct->capacity);
  }
}

void quad_struct_free(Quad *quad_struct) {
  free(quad_struct->data);
}



void print_quad_list(Quad *quad_struct){
 

}


quad get_last_value(Quad *quad_struct){
 
  
 
    return quad_struct_remove(quad_struct, quad_struct->size);

  
return NULL;


}
void print_arr_size(Quad *arr){
  printf("SIZE IS %d\n", arr->size);
}





void backpatch_break_quad_while(){   
      while(1){
        if(backpatching_break_start_while.size - 1 < 0 || backpatching_break_end_while.size-1<0)
            break;
      
        quad q1 = quad_struct_get(&backpatching_break_start_while, backpatching_break_start_while.size -1);
        quad q = quad_struct_get(&backpatching_break_end_while, backpatching_break_end_while.size - 1);
        //
        if(q->extra_data != q1->extra_data){
          break;
        }else{
          q = get_last_value(&backpatching_break_end_while);
        }
   

        
        break7--;
        break8--;
        q->label = q1->label ;

      }
}


void backpatch_break_quad_for(){   
      while(1){
        if(backpatching_break_start_for.size - 1 < 0 || backpatching_break_end_for.size-1<0)
            break;
      
        quad q1 = quad_struct_get(&backpatching_break_start_for, backpatching_break_start_for.size -1);
        quad q = quad_struct_get(&backpatching_break_end_for, backpatching_break_end_for.size - 1);
        //
        if(q->extra_data != q1->extra_data){
          break;
        }else{
          q = get_last_value(&backpatching_break_end_for);
        }
   

        
        
        q->label = q1->label ;

      }
}













void backpatch_for_elist_quad(){
   
    
        while(1){
       if(backpatching_table_for_elist.size -1<0 || backpatching_index_for_elist.size-1 < 0)
        break;
    quad q1 = get_last_value(&backpatching_index_for_elist);
    quad q = get_last_value(&backpatching_table_for_elist);

   

    index11--;
    index12--;
    q->label = q1->label;
  }
}



void remove_last_entry_for_break_while(){
      printf(RED"while counter:%d\n"RESET, while_counter);

  if(backpatching_break_start_while.size - 1 > 0){
    quad p = quad_struct_get(&backpatching_break_start_while, backpatching_break_start_while.size - 1);
    if(p->extra_data == while_counter){
      get_last_value(&backpatching_break_start_while);
      printf(RED"MATCH!\n"RESET); 
    }
  }
}

void remove_last_entry_for_break_for(){
      printf(RED"while counter:%d\n"RESET, for_counter);

  if(backpatching_break_start_for.size - 1 > 0){
    quad p = quad_struct_get(&backpatching_break_start_for, backpatching_break_start_for.size - 1);
    if(p->extra_data == for_counter){
      get_last_value(&backpatching_break_start_for);
      printf(RED"MATCH!\n"RESET); 
    }
  }
}



/* EDW KSEKINAEI I CONTINUE */
void remove_last_entry_for_continue_while(){
      printf(RED"while counter:%d\n"RESET, while_counter);

  if(backpatching_continue_start_while.size - 1 > 0){
    quad p = quad_struct_get(&backpatching_continue_start_while, backpatching_continue_start_while.size - 1);
    if(p->extra_data == while_counter){
      get_last_value(&backpatching_continue_start_while);
      printf(RED"MATCH!\n"RESET); 
    }
  }
}

void remove_last_entry_for_continue_for(){
      printf(RED"for counter:%d\n"RESET, for_counter);

  if(backpatching_continue_start_for.size - 1 > 0){
    quad p = quad_struct_get(&backpatching_continue_start_for, backpatching_continue_start_for.size - 1);
    if(p->extra_data_for == for_counter){
      get_last_value(&backpatching_continue_start_for);
      printf(RED"MATCH!\n"RESET); 
    }
  }
}


void backpatch_continue_quad_while(){   
      while(1){
        if(backpatching_continue_start_while.size - 1 < 0 || backpatching_continue_end_while.size-1<0)
            break;
      
        quad q1 = quad_struct_get(&backpatching_continue_start_while, backpatching_continue_start_while.size -1);
        quad q = quad_struct_get(&backpatching_continue_end_while, backpatching_continue_end_while.size - 1);
        printf("Q->%d Q1->%d\n", q->extra_data, q1->extra_data);
        if(q->extra_data != q1->extra_data){
          break;
        }else{
          q = get_last_value(&backpatching_continue_end_while);
        }
   
        printf("MATCH EXOUME!\n");
        
        q->label = q1->label ;

      }
}


void backpatch_continue_quad_for(){   
      while(1){
        if(backpatching_continue_start_for.size - 1 < 0 || backpatching_continue_end_for.size-1<0)
            break;
      
        quad q1 = quad_struct_get(&backpatching_continue_start_for, backpatching_continue_start_for.size -1);
        quad q = quad_struct_get(&backpatching_continue_end_for, backpatching_continue_end_for.size - 1);
        //
        if(q->extra_data_for != q1->extra_data_for){
          break;
        }else{
          q = get_last_value(&backpatching_continue_end_for);
        }
   

        
        
        q->label = q1->label ;

      }
}
























void backpatch_while_quad(Quad *quad_struct){

       int i;
       /* ftiaxnoume tin arxi kai to kleisimo tou jump */
       i = index5;
        while(1){
          if(backpatching_index_while_start.size - 1 < 0 || backpatching_table_while_end.size-1<0)
            break;
          quad q1 = get_last_value(&backpatching_index_while_start);
          quad q = get_last_value(&backpatching_table_while_end);
          


          index5--;
          index6--;
          q->label = q1->label ;

        }

      i = index3;
      while(1){
        if(backpatching_table_while.size-1 <0 || backpatching_index_while.size-1 < 0)
        break;
        quad q1 = get_last_value(&backpatching_index_while);
        quad q = get_last_value(&backpatching_table_while);
        
       
      
        index3--;
        index4--;
        q->label = q1->label ;

      }
  
  if(stop_writing_if_quad == 0)

 for(i = 0; i <= quad_counter - 1 ; i++){
        quad q = quad_struct_get(quad_struct, i);          
        if(q->written == 0)
          write_quad_general(q);
       
        q->written = true;
  }

  return;
}

void backpatch_for_quad(Quad *quad_struct){
  int i;
  printf("\nINDEX :%d ARRAY :%d\n",backpatching_index_for.size  , backpatching_table_for.size);
 
 


  while(1){
       if(backpatching_table_for_end.size -1<0 || backpatching_index_for_start.size-1 < 0)
        break;
    quad q1 = get_last_value(&backpatching_index_for_start);
    quad q = get_last_value(&backpatching_table_for_end);

   

    index9--;
    index10--;
    q->label = q1->label;
  }

  i = index7;


    printf(RED"INDEX :%d ARRAY :%d\n"RESET,backpatching_index_for.size  , backpatching_table_for.size);

  while(1){
  
      if(backpatching_index_for.size -1<0 || backpatching_table_for.size-1 < 0)
        break;
    quad q1 = get_last_value(&backpatching_index_for);
    quad q = get_last_value(&backpatching_table_for);

    
    printf(RED" KOITAW TA VALUE :%d :%d \n"RESET, q->label, q1->label);
    printf(RED "ptr :%p\n"RESET, q);
    index7--;
    index8--;
    q->label = q1->label;
  }
  printf(RED"INDEX :%d ARRAY :%d\n"RESET,backpatching_index_for.size  , backpatching_table_for.size);
  if(stop_writing_if_quad == 0)
    for(i = 0; i <= quad_counter - 1 ; i++){
            quad q = quad_struct_get(quad_struct, i);         
             if(q->written == 0)
              write_quad_general(q);
            if(q->op == jump)
                printf("checking :ptr %u\n", q->label);

            //q->written = true;
  }
  return;
}


expr backpatch_if_quad(Quad *quad_struct, int label, int write){
      int i;
      i = index1;
      
        while(1){
        if(backpatching_index_if.size -1 <0 || backpatching_table_if.size-1 < 0)
        break;
        quad q1 = get_last_value(&backpatching_index_if);
        quad q = get_last_value(&backpatching_table_if);
       
         q->label = q1->label ;
      
   
    }

      while(1){
        if(backpatching_table_else.size -1 <0 || backpatching_index_else.size -1 < 0)
        break;
        quad q1 = get_last_value(&backpatching_index_else);
        quad q = get_last_value(&backpatching_table_else);
    
        q->label = q1->label;

    
    }        



 return NULL;
}


