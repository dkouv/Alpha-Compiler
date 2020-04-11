#include "avm.h"
void vmarg_print(vmarg arg){
    switch(arg->type){
        case label_a:{
            
            printf("label %d ", arg->val);
            break;
        }
        case global_a:{
            printf("scope %d:", arg->val);
 
            printf("name %s ", arg->name);
            
            break;
        }
        case formal_a:{
            printf("scope %d:", arg->val);

            printf("name %s ", arg->name);

            break;
        }
        case local_a:{

            printf("scope %d:", arg->val);

          
            printf("name %s ", arg->name);
            break;
        }
        case int_a:{
       
            printf("value: %f ", table_get(&number_array, arg->val).d);
            break;
        }
        case double_a:{
       
            printf("value: %f ", table_get(&number_array, arg->val).d);

            break;
        }
        case string_a:{

            printf("\"%s\" ", table_get(&string_array, arg->val).string);

            break;
        }
        case bool_a:{
            
            printf("bool: %d ", arg->val);
            break;
        }
        case nil_a:{
            printf("nill ");
            break;
        }
        case userfunc_a:{
            
            printf("userfunc %s ", table_get(&userfunc_array, arg->val).function->name);
            break;
        }
        case libfunc_a:{
            
            printf("libfunc: %s ", table_get(&libfunc_array, arg->val).string);

            break;
        }
        case retval_a:{
            printf("retval ");
            break;
        }
        case 13:{
 

            printf("unused ");
            break;
        }
    }
}


void avm_print(avm_memcell arg){

	switch (arg->type) {

        case number_m:{
            printf("%f\n", arg->data.numVal);
            break;
        }
        case string_m:{
            printf("%s\n", arg->data.strVal);
            break;
        }
        case bool_m:{
            printf("%d\n", arg->data.boolVal);
            break;
        }
        case table_m:{
            printf("TABLE\n");
            break;
        }
        case userfunc_m:{
            printf("%s\n", table_get(&userfunc_array, arg->data.funcVal).function->name);
            break;
        }
        case libfunc_m:{
            printf("%s\n", arg->data.libfuncVal);
            break;
        }
        case nil_m:{
            printf("nil\n");
            break;
        }
        case undef_m:{
            printf("undefined\n");
            break;
        }

        default :
            printf("lulz\n");
            break;
    }
}