#include "avm.h"
 
int main(int argc, char** argv){
    if(argc == 1){
        printf(MAGENTA"give an input file, exiting\n"RESET);
        exit(1);
    }
    table_init(&string_array);
    table_init(&number_array);
    table_init(&userfunc_array);
    table_init(&libfunc_array);
    table_init(&supported_libfunctions);
    read_binary_file(argv[1]);
    avm_initialize();

    top = AVM_STACKSIZE - 1 - total_globals;
    while(executionFinished != 1){
       
        execute_cycle();
 
    }
    return 1;
}