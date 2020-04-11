#include "library.h"
int total = 0 ;
int current_quad = 0;
unsigned int instruction_counter = 0;
struct function_phase4{
    int args;
    int address;
};
int func_counter = 0;
int return_counter = 0;
int function_address;

generator_func_t generators[] = {
	generate_ASSIGN,
	generate_ADD,
	generate_SUB,
	generate_NULL,
	generate_MUL,
	generate_DIV,
	generate_MOD,
	generate_UMIN,
	generate_AND,
	generate_OR,
	generate_NOT,	
	generate_IF_EQ,
	generate_IF_NOTEQ,
	generate_IF_LESSEQ,
	generate_IF_GREATEREQ,
    generate_IF_LESS,
    generate_IF_GREATER,
	generate_CALL,
	generate_PARAM,
	generate_RETURN,
	generate_GETRETVAL,
	generate_FUNCSTART,
	generate_FUNCEND,
	generate_NEWTABLE,
	generate_TABLEGETELEM,
	generate_TABLESETELEM,
	generate_JUMP,
	generate_NOP



};

int nextinstructionlabel(){
    return instruction_counter;
}




void patch_return_incomplete_jump(){
    int i;
    for(i = 0; i < return_incomplete_jumps_array.size; i++){
        table_type p;
        p.jumps = table_get(&return_incomplete_jumps_array, i).jumps;
  
        if(p.jumps->iaddress == func_counter){
            table_get(&instruction_array, p.jumps->instrNo).instr->result->val = nextinstructionlabel() -1;
            return_counter--;
            //if(get_last_if_eq() != -1){
                //instruction instr = table_get(&instruction_array, get_last_if_eq()).instr;//->result->val += 1;
                //instruction instr = table_get(&instruction_array, i).instr;
                //instr->patched = 1;
                //table_get(&incomplete_jumps_target_array, get_last_if_eq()).jumps->patched == 1;
            //}
        }
    }
}

void add_return_incomplete_jump(unsigned int instrNo){
        table_type p;
        incomplete_jump jump = calloc(sizeof(struct incomplete_jump), sizeof(struct incomplete_jump*));
        jump->iaddress = func_counter;
        jump->instrNo = instrNo;
        p.jumps = jump;
       
        table_set(&return_incomplete_jumps_array, return_incomplete_jumps_array.size, p);
}



void add_incomplete_jump(unsigned int instrNo, unsigned int iaddress){

        table_type p;
        incomplete_jump jump = calloc(sizeof(struct incomplete_jump), sizeof(struct incomplete_jump*));
        jump->instrNo = instrNo;
        jump->iaddress = iaddress;
        p.jumps = jump;
        
        table_set(&incomplete_jumps_target_array, incomplete_jumps_target_array.size, p);

}

void emit(instruction i) {
       
    

        table_type p;
        p.instr = i;

        table_set(&instruction_array, instruction_counter, p);

      	instruction_counter++;	
        
}

void reset_operand(struct vmarg* v) {

}



void generate_relational(int op, quad q){
    instruction t = calloc(sizeof(struct instruction), sizeof(struct instruction));
    t->arg1 = calloc(sizeof(struct vmarg), sizeof(struct vmarg));
    t->arg2 = calloc(sizeof(struct vmarg), sizeof(struct vmarg));
 	t->result = calloc(sizeof(struct vmarg), sizeof(struct vmarg));
 
    t->opcode = op;
    t->srcLine = q->line;

    make_operand(q->arg1, t->arg1);
    make_operand(q->arg2, t->arg2);
    
    t->result->type = label_a;
    if(function_address -1 >= 0 && quad_struct_get(&quad_table, function_address - 1 )->op == 19){

            add_return_incomplete_jump(nextinstructionlabel());
            printf("THELEI PATCH :%d\n", nextinstructionlabel());
        
    }else if(q->label < current_quad){
        t->result->val = quad_struct_get(&quad_table, q->label)->taddress;
    }else{
        add_incomplete_jump(nextinstructionlabel(), q->label - 1);
    }


    q->taddress = nextinstructionlabel();
    emit(t);
}
void generate_NULL(quad q){

}
void generate_AND (quad q){
	generate(and_v, q);
}

void generate_ADD(quad q){
    generate(add_v, q);
}
void generate_SUB(quad q){
    generate(sub_v, q);   
}
void generate_MUL(quad q){

    generate(mul_v, q);
}
void generate_UMIN(quad q){
    generate(uminus_v, q);
}
void generate_DIV(quad q){
     generate(div_v, q);
}
void generate_MOD(quad q){
     generate(mod_v, q);
}
void generate_NEWTABLE(quad q){
     generate(newtable_v, q);
}
void generate_TABLEGETELEM(quad q){
    generate(tablegetelem_v, q);   
}
void generate_TABLESETELEM(quad q){
    generate(tablesetelem_v, q);
}
void generate_ASSIGN(quad q){
    generate(assign_v, q);
}
void generate_NOP(quad q){
    instruction t = create_new_instruction();
    t->opcode = nop_v;
    /* emit to instruction nop */
    emit(t);
}
void generate_JUMP(quad q){
    generate_relational(jump_v, q);
}
void generate_IF_EQ(quad q){
    generate_relational(jeq_v, q);
}
void generate_IF_NOTEQ(quad q){
    generate_relational(jne_v, q);
}
void generate_IF_GREATER(quad q){
    generate_relational(jgt_v, q);    
}
void generate_IF_GREATEREQ(quad q){
    generate_relational(jge_v, q);
}
void generate_IF_LESS(quad q){
    generate_relational(jlt_v, q);
}
void generate_IF_LESSEQ(quad q) {
    generate_relational(jle_v, q);
}
void generate_NOT(quad q) {
    generate(not_v, q);

 
}
/* kanei allocate ena neo instruction me ola ta pedia tou */
instruction create_new_instruction(){
    instruction t = calloc(sizeof(struct instruction), sizeof(struct instruction));
    t->arg1 = calloc(sizeof(struct vmarg), sizeof(struct vmarg));
    t->arg2 = calloc(sizeof(struct vmarg), sizeof(struct vmarg));
 	t->result = calloc(sizeof(struct vmarg), sizeof(struct vmarg));
    return t;
}

void generate_OR(quad q) {
    generate(or_v, q);
}

void generate_PARAM(quad q) {

    instruction t = create_new_instruction();

    q->taddress = nextinstructionlabel();
    t->opcode = pusharg_v;
    t->srcLine = q->line;
    if(q->arg1->sym && q->arg1->sym->scope_offset == -1 && q->arg1->type != programfunc_e) {
                    table_type p;
                    p.function = calloc(sizeof(struct Function), sizeof(struct Function));
                    p.function->name = strdup (q->arg1->sym->value.varVal->name); 
                    printf("VRIKA !%s\n", p.function->name);
                    if(table_find_element(&userfunc_array, p, 2) != -1){
                       
                        q->arg1->type = programfunc_e;
                        
                    }
       }
    make_operand(q->arg1, t->arg1);
    emit(t);
}

void generate_CALL(quad q) {

    instruction t = create_new_instruction();

    q->taddress = nextinstructionlabel();
   
    t->opcode = call_v;
    t->srcLine = q->line;
    //q->arg1->type = libraryfunc_e;
    
    //printf(RED"TIPOS :%d\n"RESET, q->arg1->type);
     if(q->arg1->sym && q->arg1->sym->scope_offset == -1 && q->arg1->type != programfunc_e) {
                    table_type p;
                    p.function = calloc(sizeof(struct Function), sizeof(struct Function));
                    p.function->name = strdup (q->arg1->sym->value.varVal->name); 
                    printf("VRIKA !%s\n", p.function->name);
                    if(table_find_element(&userfunc_array, p, 2) != -1){
                       
                        q->arg1->type = programfunc_e;
                        
                    }
       }


                    
       
    make_operand(q->arg1, t->arg1);
   // printf(RED"TIPOS :%d\n"RESET, t->arg1->type);
   

    emit(t);
}

void generate_GETRETVAL(quad q) {

    instruction t = create_new_instruction();

    q->taddress = nextinstructionlabel();

    q->arg2 = q->arg1;
    q->arg1 = q->result;

    t->opcode = assign_v;
    t->srcLine = q->line;

    make_operand(q->arg1, t->arg2);
  
    make_retvaloperand(t->arg2);
    make_operand(q->result, t->arg1);
    emit(t);
}
void fix_incomplete_jumps(){
    int i, j ;
    //printf(BLUE"PATCHRW\n"RESET);

    for (i = 0; i < patch_jump_functions.size; i++){
        //printf("BAINW\n");
     	rikas r = table_get(&incomplete_jumps_functions, i).rikas_1;
        for (j = 0; j < patch_jump_functions.size; j++){
   	 		cuck c = table_get(&patch_jump_functions, patch_jump_functions.size -j - 1).cuck_1;
   			if(strcmp(c->f_name, r->f_name) == 0 && c->f_id == r->f_id){
		 		r->instr->result->val = c->pos;
		 		break;
   			}
    	}
	}
}
void add_function_patch(quad q){
	cuck c;
	c->pos = nextinstructionlabel();
	c->f_name = strdup(q->arg1->sym->value.funcVal->name);
    printf("CF NAME %s\n", c->f_name);
    c->f_id = func_counter;//q->arg1->sym->value.funcVal->line;
    table_type p;
    p.cuck_1 = c;
    
    table_set(&patch_jump_functions, patch_jump_functions.size, p);

}
 void add_function_incomplete_jump(quad q, instruction j){
    rikas r;
    r = calloc(sizeof(struct rikas), sizeof(struct rikas));
    r->instr = j;
    r->f_id = func_counter;//q->arg1->sym->value.funcVal->total_arguments;
    r->f_name = strdup(q->arg1->sym->value.funcVal->name);
    table_type p;
    p.rikas_1 = r;
    table_set(&incomplete_jumps_functions, incomplete_jumps_functions.size, p);
 }

 void generate_FUNCSTART(quad q) {
    func_counter++;
    instruction t = create_new_instruction();
    instruction j = create_new_instruction();
    j->opcode = jump_v;
    j->srcLine = q->line;
    add_function_incomplete_jump(q, j);

    emit(j);

    t->opcode = funcenter_v;
    t->srcLine = q->line;

    q->arg1->type = programfunc_e;
    make_operand(q->arg1, t->result);
    emit(t);

 }

void generate_RETURN(quad q){
    instruction t = create_new_instruction();

    q->taddress = nextinstructionlabel();

    // printf("PTR 1:%p\n", q->arg1->sym);
    // printf("PTR 2:%p\n", q->arg2->sym);
    // printf("PTR 3:%p\n", q->result->sym);
    // printf("PTR 1:%s\n", q->arg1->strConst);
    // printf("PTR 2:%p\n", q->arg2->strConst);
    // printf("PTR 3:%p\n", q->result->strConst);
    q->result = q->arg1;
    q->arg2 = q->arg1;
  	
    t->opcode = assign_v;
    t->srcLine = q->line;
    make_operand(q->result, t->arg2);
    make_operand(q->arg2, t->arg1);
    make_retvaloperand(t->arg1);
    emit(t);
    
    
    return_counter++;
   
}

void generate_FUNCEND(quad q){
    instruction t = create_new_instruction();

    // entry f = q->arg1->sym;
    // f->taddress = nextinstructionlabel();
    // q->taddress = nextinstructionlabel();

  

    t->srcLine = q->line;
    t->opcode = funcexit_v;
    q->arg1->type = programfunc_e;
    make_operand(q->arg1, t->result);
    
    emit(t);
    add_function_patch(q);

    patch_return_incomplete_jump();

    
    func_counter--;
}




// static void avm_initstack(void) {
//  unsigned i;
//     for (i = 0; i<AVM_STACKSIZE; ++i) {
//         AVM_WIPEOUT(stack[i]);
//         stack[i].type = undef_m;
//     }
// }


void avm_tabledestroy(struct avm_table* t) {
//    avm_tablebucketdestroy(t->strIndexed);
//    avm_tablebucketsdestroy(t->numIndexed);
//    free(t);
}

unsigned consts_newstring(char* s){
    table_type p;
    p.string = strdup(s);
    int elem = table_find_element(&string_array, p , 0);
    if(elem == -1){
        /* element not found, insert */
        table_set(&string_array, string_array.size, p);
        return string_array.size -1;
    }
    return elem;

}
// unsigned consts_newnumber_int(int n){
//     number_type l = calloc(sizeof(struct number_type), sizeof(struct number_type));
//     l->d = n;
//     l->type = 0;
//     table_type p;

   
//     p.num_type = l;

//     int elem = table_find_element(&num_array, p , 1);
//     if(elem == -1){
//         /* element not found, insert */
//         table_set(&num_array, num_array.size, p);
//         return num_array.size -1;
//     }
//     return elem;
// }




unsigned consts_newnumber(double n){
    number_type l = calloc(sizeof(struct number_type), sizeof(struct number_type));
    l->d = n;
    l->type = 1;
    table_type p;
 
    p.num_type = l;
 
    int elem = table_find_element(&num_array, p , 1);
    if(elem == -1){
        /* element not found, insert */
        table_set(&num_array, num_array.size, p);
        return num_array.size -1;
    }
    return elem;
}
unsigned libfuncs_newused(char* s){
    
    table_type p;
    p.string = s;
    int elem = table_find_element(&libfunc_array, p , 3);
    if(elem == -1){
        /* element not found, insert */

        table_set(&libfunc_array, libfunc_array.size, p);
        return libfunc_array.size -1;
    }
    return elem;
}
unsigned userfuncs_newfunc(entry sym){
    table_type p;

    p.function = sym->value.funcVal;

    int elem = table_find_element(&userfunc_array, p , 2);
    if(elem == -1){
        /* element not found, insert */
        sym->value.funcVal->line = nextinstructionlabel();
        p.function = sym->value.funcVal;
        table_set(&userfunc_array, userfunc_array.size, p);
        return userfunc_array.size -1;
    }
    return elem;
}


void make_operand (expr e, vmarg arg) {
	arg->v_sym = e->sym;
     if(e->sym && e->sym->scope_offset == -1) {
        e->type = programfunc_e;             
       }
           
    switch(e->type) {
        case var_e: {
            arg->val = e->sym->scope_offset;
            switch (e->sym->scope_space) {
                case programVal:arg->type = global_a; break;
                case functionLocal: arg->type = local_a; break;
                case formalArg: arg->type = formal_a; break;
                default: assert(0);
            }
            break;
        }
        case tableitem_e: {
            arg->val = e->sym->scope_offset;

            switch (e->sym->scope_space) {
                case programVal: arg->type = global_a; break;
                case functionLocal: arg->type = local_a; break;
                case formalArg: arg->type = formal_a; break;
                default: assert(0);
            }
            break;
        }

        case arithexpr_e: {
            arg->val = e->sym->scope_offset;

            switch (e->sym->scope_space) {
                case programVal: arg->type = global_a; break;
                case functionLocal: arg->type = local_a; break;
                case formalArg: arg->type = formal_a; break;
                default: assert(0);
            }
            break;
        }

        case boolexpr_e: {
            arg->val = e->sym->scope_offset;

            switch (e->sym->scope_space) {
                case programVal: arg->type = global_a; break;
                case functionLocal: arg->type = local_a; break;
                case formalArg: arg->type = formal_a; break;
                default: printf(RED"ASSERT 0\n"RESET);
            }
            break;
        }

        case newtable_e: {
            arg->val = e->sym->scope_offset;

            switch (e->sym->scope_space) {
                case programVal: arg->type = global_a; break;
                case functionLocal: arg->type = local_a; break;
                case formalArg: arg->type = formal_a; break;
                default: assert(0);
            }
            break;
        }

        case constbool_e: {
            arg->val = e->boolConst;
            arg->type = bool_a;
            break;
        }

        case conststring_e: {
            arg->val = consts_newstring(e->strConst);
            arg->type = string_a;
            break;
        }


        case constint_e: {
       
            arg->val = consts_newnumber(e->const_int);
            arg->type = int_a;
   
            break;
        }
        case constdouble_e: {
            arg->val = consts_newnumber(e->const_double);
            arg->type = double_a; break;
        }

        case nil_e: arg->type = nil_a; break;

        case programfunc_e: {
            arg->type = userfunc_a;

            arg->val = e->sym->taddress;
            /* or alternatively
             * the index of the function on the array with the user
             * functions 
             */
            arg->val = userfuncs_newfunc(e->sym); 
            break;
        }

        case libraryfunc_e: {
            //printf(RED"%s\n"RESET, e->sym->value.funcVal->name);
          
            arg->type = libfunc_a;
            arg->val = libfuncs_newused(e->sym->value.funcVal->name);
            break;
        }

        default: assert(0);

    }

}

void generate(int op, quad q){
    instruction t = calloc(sizeof(struct instruction), sizeof(struct instruction));
    t->arg1 = calloc(sizeof(struct vmarg), sizeof(struct vmarg));
    t->arg2 = calloc(sizeof(struct vmarg), sizeof(struct vmarg));
 	t->result = calloc(sizeof(struct vmarg), sizeof(struct vmarg));

    t->opcode = op;
    t->srcLine = q->line;
 	make_operand(q->arg1, t->arg1);
	make_operand(q->arg2, t->arg2);
 	make_operand(q->result, t->result);
    //printf(YELLOW" TIPOS :%d :%d\n"RESET, q->arg1->type, q->arg2->type);

    if(q->op == or || q->op == and || q->op == not){

        //t->result->type = bool_a;

    
    }
	q->taddress = nextinstructionlabel();
	emit(t);
 
}

void generate_output() {
    unsigned i;
    //printf("TABLE SIZE :%d\n", quad_table.size);
    char* last_function;
    for (i = 0; i < quad_table.size ;i++){

    	quad q = quad_struct_get(&quad_table, i);
        function_address = i;
    	//printf(RED"#%d \n"RESET, q->label);
        //printf(RED"opcode :%s\n"RESET, opcode_types[q->op]);
    	//print_quad_info(q);
        if(q->op == if_eq_op){
            q->op = if_eq;
            q->label = q->label+1;

        }else if (q->op != if_eq && q->op != jump && q->op != tablesetelem1 && q->op != tablesetelemindex1){
            //printf(RED"opcode :%s\n"RESET, opcode_types[q->op]);

            q->label = q->label+1;

        }else if(q->op == tablesetelem1 ) {
                     
            q->op = tablesetelem;
 
        }else if ( q->op == tablesetelemindex1){
           
           
            q->op = tablesetelem;
        }
    	(*generators[q->op]) (q);
    	//printf(RED"---------------------------\n"RESET);
    	//printf("Opcode :%s\n", opcode_types[q->op]);
	}
    
    generate_NOP(NULL);
    patch_incomplete_jumps();
    fix_incomplete_jumps();

}

/*Helper functions to produce common arguments for
 *generated instructions, like 1, 0, "true", "false"
 *and function return values.
 */

void make_numberoperant(vmarg arg, double val) {
    arg->val = consts_newnumber(val);
    arg->type = number_a;
}

void make_booloperand(vmarg arg, int val) {
    arg->val = val;
    arg->type = bool_a;
}

void make_retvaloperand(vmarg arg) {
    arg->type = retval_a;
}

void write_vmarg_output(vmarg arg, FILE* f){
    
      switch(arg->type){
        case label_a:{
            fprintf(f, "00(label), %d", arg->val);
            break;
        }
        case global_a:{
            fprintf(f, "01(global), %d:%s", arg->v_sym->scope_offset, arg->v_sym->value.varVal->name);
            break;
        }
        case formal_a:{
            fprintf(f, "02(formal), %d:%s", arg->v_sym->scope_offset, arg->v_sym->value.varVal->name);
            break;
        }
        case local_a:{
            fprintf(f, "03(local), %d:%s", arg->v_sym->scope_offset, arg->v_sym->value.varVal->name);
            break;
        }
        case int_a:{
            //printf(RED"Na kanoume ksexwrismo apo integer se float, isws extra enum + case?\n"RESET);
            fprintf(f, "\t");
            fprintf(f, "04(num), %d:%f", arg->val, table_get(&num_array, arg->val).num_type->d);
            break;
        }
        case double_a:{
            //printf(RED"Na kanoume ksexwrismo apo integer se float, isws extra enum + case?\n"RESET);
            fprintf(f, "04(num), %d:%f", arg->val, table_get(&num_array, arg->val).num_type->d);
            break;
        }
        case string_a:{
            fprintf(f, "05(string), %d:\"%s\"", arg->val, table_get(&string_array, arg->val).string);

            break;
        }
        case bool_a:{
            fprintf(f, "06(boolean), %s",  arg->val? "true" : "false");
            break;
        }
        case nil_a:{
            fprintf(f, "07(nil)");
            break;
        }
        case userfunc_a:{
            fprintf(f, "08(userfunc), %d:%s", arg->val, table_get(&userfunc_array, arg->val).function->name);//arg->v_sym->value.funcVal->name);
            break;
        }
        case libfunc_a:{
            fprintf(f, "09(libfunc), %d:%s", arg->val, table_get(&libfunc_array, arg->val).string);
            break;
        }
        case retval_a:{
            fprintf(f, "10(retval)");
            break;
        }
      }


}

void create_instruction_output(){

    int i;
    FILE* f = fopen("instructions.txt", "w");
    create_binary_file(f);
    //printf(RED"instruction_array size :%d\n"RESET, instruction_array.size);
    for(i = 0; i < instruction_array.size; i++){
    	instruction instr = table_get(&instruction_array, i).instr;
        /* tipwnw to instruction counter */
        fprintf(f, "%d\t\t", i);
        fprintf(f, "%s\t\t", vmopcode_types[instr->opcode]);
        //printf(BLUE"TIPOS :%s\n"RESET, vmopcode_types[instr->opcode]);
    	switch(instr->opcode){
    		case assign_v:{
			 	fprintf(f, "\t\t");
		        write_vmarg_output(instr->arg1, f);
		        fprintf(f, "\t\t");
		        write_vmarg_output(instr->arg2, f);
                fprintf(f, "\tLine: %d", instr->srcLine);
		        break;
    		}
    		case add_v:{
                fprintf(f, "\t\t\t");

				write_vmarg_output(instr->result, f);
		        fprintf(f, "\t\t");
		        write_vmarg_output(instr->arg1, f);
		        fprintf(f, "\t\t");
		        write_vmarg_output(instr->arg2, f);
                fprintf(f, "\tLine: %d", instr->srcLine);
		    	break;
    		}
    		case sub_v:{
				write_vmarg_output(instr->result, f);
		        fprintf(f, "\t\t");
		        write_vmarg_output(instr->arg1, f);
		        fprintf(f, "\t\t");
		        write_vmarg_output(instr->arg2, f);
                fprintf(f, "\tLine: %d", instr->srcLine);
		    	break;
    		}
    		case mul_v:{
    			fprintf(f, "\t\t\t");
				write_vmarg_output(instr->result, f);
		        fprintf(f, "\t\t");
		        write_vmarg_output(instr->arg1, f);
		        fprintf(f, "\t\t");
		        write_vmarg_output(instr->arg2, f);
                fprintf(f, "\tLine: %d", instr->srcLine);
		    	break;
    		}
    		case div_v:{

				write_vmarg_output(instr->result, f);
		        fprintf(f, "\t\t");
		        write_vmarg_output(instr->arg1, f);
		        fprintf(f, "\t\t");
		        write_vmarg_output(instr->arg2, f);
                fprintf(f, "\tLine: %d", instr->srcLine);
		    	break;
    		}
    		case mod_v:{
				write_vmarg_output(instr->result, f);
		        fprintf(f, "\t\t");
		        write_vmarg_output(instr->arg1, f);
		        fprintf(f, "\t\t");
		        write_vmarg_output(instr->arg2, f);
                fprintf(f, "\tLine: %d", instr->srcLine);
		    	break;
    		}
    		case uminus_v:{
    			printf(RED" BAINW UMINUS\n"RESET);
				write_vmarg_output(instr->result, f);
		        fprintf(f, "\t\t");
		        write_vmarg_output(instr->arg1, f);
		        fprintf(f, "\t\t");
		        write_vmarg_output(instr->arg2, f);
                fprintf(f, "\tLine: %d", instr->srcLine);
    			break;
    		}
    		case and_v:{
                fprintf(f, "\t\t\t");
                write_vmarg_output(instr->result, f);
                fprintf(f, "\t\t");
		        write_vmarg_output(instr->arg1, f);
		        fprintf(f, "\t\t\t");
		        write_vmarg_output(instr->arg2, f);
                fprintf(f, "\tLine: %d", instr->srcLine);
    			break;
    		}
    		case or_v:{
        
                fprintf(f, "\t\t\t");
                write_vmarg_output(instr->result, f);
                fprintf(f, "\t\t");
		        write_vmarg_output(instr->arg1, f);
		        fprintf(f, "\t\t\t");
		        write_vmarg_output(instr->arg2, f);
                fprintf(f, "\tLine: %d", instr->srcLine);

    			break;
    		}
    		case not_v:{
                fprintf(f, "\t\t\t");
                write_vmarg_output(instr->result, f);
                fprintf(f, "\t\t");
		        write_vmarg_output(instr->arg1, f);
                fprintf(f, "\tLine: %d", instr->srcLine);
    			break;
    		}
    		case jeq_v:{
                
				fprintf(f, "\t\t");
		        write_vmarg_output(instr->arg1, f);
		        fprintf(f, "\t\t");
		        write_vmarg_output(instr->arg2, f);
                fprintf(f, "\t\t");
                write_vmarg_output(instr->result, f);
		        fprintf(f, "\tLine: %d", instr->srcLine);
    			break;
    		}
    		case jne_v:{
                fprintf(f, "\t");
		        write_vmarg_output(instr->arg1, f);
		        fprintf(f, "\t\t");
		        write_vmarg_output(instr->arg2, f);
                fprintf(f, "\t\t");
                write_vmarg_output(instr->result, f);
			    fprintf(f, "\tLine: %d", instr->srcLine);
    			break;
    		}
    		case jle_v:{
                fprintf(f, "\t");
		        write_vmarg_output(instr->arg1, f);
		        fprintf(f, "\t\t");
		        write_vmarg_output(instr->arg2, f);
                fprintf(f, "\t\t");
                write_vmarg_output(instr->result, f);
                fprintf(f, "\tLine: %d", instr->srcLine);
    			break;
    		}
    		case jge_v:{
		        write_vmarg_output(instr->arg1, f);
		        fprintf(f, "\t\t");
		        write_vmarg_output(instr->arg2, f);
                fprintf(f, "\t\t");
                write_vmarg_output(instr->result, f);
                fprintf(f, "\tLine: %d", instr->srcLine);
    			break;
    		}
    		case jlt_v:{
                fprintf(f, "\t\t");
		        write_vmarg_output(instr->arg1, f);
		        fprintf(f, "\t\t");
		        write_vmarg_output(instr->arg2, f);
                fprintf(f, "\t\t");
                write_vmarg_output(instr->result, f);
                fprintf(f, "\tLine: %d", instr->srcLine);
    			break;
    		}
    		case jgt_v:{
                fprintf(f, "\t");
		        write_vmarg_output(instr->arg1, f);
		        fprintf(f, "\t\t");
		        write_vmarg_output(instr->arg2, f);
                fprintf(f, "\t\t");
                write_vmarg_output(instr->result, f);
                fprintf(f, "\tLine: %d", instr->srcLine);
    			break;
    		}
    		case call_v:{
                fprintf(f, "\t");
		        write_vmarg_output(instr->arg1, f);
                fprintf(f, "\tLine: %d", instr->srcLine);
    			break;
    		}
    		case pusharg_v:{
                fprintf(f, "\t");
		        write_vmarg_output(instr->arg1, f);
                fprintf(f, "\tLine: %d", instr->srcLine);
    			break;
    		}
    		case funcenter_v:{
                fprintf(f, "\t\t");
                write_vmarg_output(instr->result, f);
                fprintf(f, "\tLine: %d", instr->srcLine);
    			break;
    		}
    		case funcexit_v:{
                fprintf(f, "\t\t");
                write_vmarg_output(instr->result, f);
                fprintf(f, "\tLine: %d", instr->srcLine);
    			break;
    		}
    		case newtable_v:{

                fprintf(f, "\t\t\t");
                write_vmarg_output(instr->arg1, f);
                fprintf(f, "\tLine: %d", instr->srcLine);                
    			break;
    		}
    		case tablegetelem_v:{
    			fprintf(f, "\t\t\t");

                write_vmarg_output(instr->result, f);
                fprintf(f, "\t\t");
                write_vmarg_output(instr->arg1, f);
                fprintf(f, "\t\t");
                write_vmarg_output(instr->arg2, f);
                fprintf(f, "\tLine: %d", instr->srcLine);
                break;
    		}
    		case tablesetelem_v:{
                  fprintf(f, "\t\t\t\t");
                 write_vmarg_output(instr->result, f);
                                     fprintf(f, "\t\t");
                 write_vmarg_output(instr->arg1, f);
                fprintf(f, "\t\t");
               
                write_vmarg_output(instr->arg2, f);
 
          
               

               
                fprintf(f, "\tLine: %d", instr->srcLine);
                break;
    		}
    		case nop_v:{
                fprintf(f, "\tLine: %d", yylineno);
    			break;
    		}
    		case jump_v:{
				fprintf(f, "\t\t");
                write_vmarg_output(instr->result, f);
                fprintf(f, "\tLine: %d", instr->srcLine);
    			break;
    		}
    		case ret_v:{
                write_vmarg_output(instr->result, f);
		        fprintf(f, "\t\t");
                fprintf(f, "Line: %d", instr->srcLine);
    			break;
    		}
    		default:{
    			printf("LOL\n");
			 	write_vmarg_output(instr->result, f);
		        fprintf(f, "\t\t");
		        write_vmarg_output(instr->arg1, f);
		        fprintf(f, "\t\t");
		        write_vmarg_output(instr->arg2, f);
                fprintf(f, "\tLine: %d", instr->srcLine);
		    	break;
			}
    	}


       
        fprintf(f, "\n");
    }

    fclose(f);
}



void patch_incomplete_jumps(){
    int i;
   
    for( i = 0; i < incomplete_jumps_target_array.size; i++){
        current_quad = i;
        incomplete_jump j = table_get(&incomplete_jumps_target_array, i).jumps;
        instruction instr = table_get(&instruction_array, j->instrNo).instr;
        // printf("INSTR :%d\n", j->instrNo);
        // printf("ADDRESS :%d\n",  j->iaddress);
        if(j->iaddress == current_quad ){
            //printf("BAINW EDW\n");
            instr->result->val = nextinstructionlabel(); 
        }else{
            if  (j->iaddress< 0)
                {}//printf(BLUE"DE KANW TIPOTA\n"RESET);
            else{
                 printf("%p ", instr);
                    printf(YELLOW"%d\n"RESET, instr->patched);
             
                   
                    instr->result->val = quad_struct_get(&quad_table, j->iaddress)->taddress + 1;

            }
        }
    }
}



void create_binary_file(FILE* f){
    int amvbinaryfile = 340;
    int i;
    fprintf(f , "amvbinary_file \t%d\n", amvbinaryfile);
    fprintf(f, "globals \t%d\n", global_var_counter);
    fprintf(f ,"STRING_ARRAY\n");
    fprintf(f ,"----------------------------------------------------------\n");

    for(i = 0; i < string_array.size; i++){
        fprintf(f, "%d\t\t\"%s\"\n", i, table_get(&string_array, i).string);
    }
    fprintf(f ,"NUMBER_ARRAY %d\n", num_array.size);
    fprintf(f ,"----------------------------------------------------------\n");
    for(i = 0; i < num_array.size; i++){
        number_type p = table_get(&num_array, i).num_type;
            fprintf(f, "%d\t\t%f\n", i, p->d);
    }
    fprintf(f, "FUNCTION_ARRAY\n");
    fprintf(f, "----------------------------------------------------------\n");
    for(i = 0; i < userfunc_array.size; i++){
        Function* f1 = table_get(&userfunc_array, i).function;
        fprintf(f, "%d\t\t:address %d, local size %d, id \"%s\"\n", i, f1->line, f1->total_arguments, f1->name);
    }
    fprintf(f, "LIBFUNCS_ARRAY\n");
    fprintf(f, "----------------------------------------------------------\n");
    for(i = 0; i < libfunc_array.size; i++){
        char* f1 = table_get(&libfunc_array, i).string;
        fprintf(f, "%d\t\t \"%s\"\n", i, f1);
    }
    fprintf(f ,"----------------------------------------------------------\n");

    fprintf(f, "strings %d\n", string_array.size);
    fprintf(f, "numbers %d\n", num_array.size);
    fprintf(f, "userfunctions %d\n", userfunc_array.size);
    fprintf(f, "libfunctions %d\n", libfunc_array.size);
    fprintf(f, "code :%d\n", yylineno);
    fprintf(f, "localsize :%d\n", local_size);
    fprintf(f, "instructions %d\n", nextinstructionlabel());
    fprintf(f ,"----------------------------------------------------------\n");

}

















void create_binary_output(){
    FILE* f = fopen("binary.txt", "wb+");
    int i;

    create_binary_file_bin(f);
     
    for(i = 0; i < instruction_array.size; i++){
    	instruction instr = table_get(&instruction_array, i).instr;
        /* tipwnw to instruction counter */
        int opcode = vmopcode_binary_types[instr->opcode];
        fwrite(&opcode, sizeof(int), 1, f);//, "%s\t\t", vmopcode_types[instr->opcode]);
        vmarg err = calloc(sizeof(struct vmarg), sizeof(struct vmarg));
        err->type = err_a;
    	switch(instr->opcode){
    		case assign_v:{

		        write_vmarg_output_binary(instr->arg1, f);

		        write_vmarg_output_binary(instr->arg2, f);
                write_vmarg_output_binary(err, f);
                fwrite(&instr->srcLine, sizeof(int), 1, f);
		        break;
    		}
    		case add_v:{
            

				write_vmarg_output_binary(instr->result, f);

		        write_vmarg_output_binary(instr->arg1, f);

		        write_vmarg_output_binary(instr->arg2, f);
 
                fwrite(&instr->srcLine, sizeof(int), 1, f);
		    	break;
    		}
    		case sub_v:{

				write_vmarg_output_binary(instr->result, f);

		        write_vmarg_output_binary(instr->arg1, f);

		        write_vmarg_output_binary(instr->arg2, f);
   
                fwrite(&instr->srcLine, sizeof(int), 1, f);
		    	break;
    		}
    		case mul_v:{

				write_vmarg_output_binary(instr->result, f);

		        write_vmarg_output_binary(instr->arg1, f);

		        write_vmarg_output_binary(instr->arg2, f);

                fwrite(&instr->srcLine, sizeof(int), 1, f);
		    	break;
    		}
    		case div_v:{


				write_vmarg_output_binary(instr->result, f);

		        write_vmarg_output_binary(instr->arg1, f);

		        write_vmarg_output_binary(instr->arg2, f);

                fwrite(&instr->srcLine, sizeof(int), 1, f);
		    	break;
    		}
    		case mod_v:{

				write_vmarg_output_binary(instr->result, f);

		        write_vmarg_output_binary(instr->arg1, f);

		        write_vmarg_output_binary(instr->arg2, f);
 
                fwrite(&instr->srcLine, sizeof(int), 1, f);
		    	break;
    		}
    		case uminus_v:{

				write_vmarg_output_binary(instr->result, f);

		        write_vmarg_output_binary(instr->arg1, f);

		        write_vmarg_output_binary(instr->arg2, f);

                fwrite(&instr->srcLine, sizeof(int), 1, f);
    			break;
    		}
    		case and_v:{

				write_vmarg_output_binary(instr->result, f);

		        write_vmarg_output_binary(instr->arg1, f);

		        write_vmarg_output_binary(instr->arg2, f);

                fwrite(&instr->srcLine, sizeof(int), 1, f);
    			break;
    		}
    		case or_v:{
        

				write_vmarg_output_binary(instr->result, f);

		        write_vmarg_output_binary(instr->arg1, f);

		        write_vmarg_output_binary(instr->arg2, f);

                fwrite(&instr->srcLine, sizeof(int), 1, f);

    			break;
    		}
    		case not_v:{

				write_vmarg_output_binary(instr->result, f);

		        write_vmarg_output_binary(instr->arg1, f);
                write_vmarg_output_binary(err, f);
                fwrite(&instr->srcLine, sizeof(int), 1, f);
    			break;
    		}
    		case jeq_v:{
                

		        write_vmarg_output_binary(instr->arg1, f);

		        write_vmarg_output_binary(instr->arg2, f);

				write_vmarg_output_binary(instr->result, f);

                fwrite(&instr->srcLine, sizeof(int), 1, f);
		   
    			break;
    		}
    		case jne_v:{

		        write_vmarg_output_binary(instr->arg1, f);

		        write_vmarg_output_binary(instr->arg2, f);

				write_vmarg_output_binary(instr->result, f);

                fwrite(&instr->srcLine, sizeof(int), 1, f);
    			break;
    		}
    		case jle_v:{

		        write_vmarg_output_binary(instr->arg1, f);

		        write_vmarg_output_binary(instr->arg2, f);

				write_vmarg_output_binary(instr->result, f);

                fwrite(&instr->srcLine, sizeof(int), 1, f);
    			break;
    		}
    		case jge_v:{

		        write_vmarg_output_binary(instr->arg1, f);

		        write_vmarg_output_binary(instr->arg2, f);

				write_vmarg_output_binary(instr->result, f);

                fwrite(&instr->srcLine, sizeof(int), 1, f);
    			break;
    		}
    		case jlt_v:{

		        write_vmarg_output_binary(instr->arg1, f);

		        write_vmarg_output_binary(instr->arg2, f);

				write_vmarg_output_binary(instr->result, f);

                fwrite(&instr->srcLine, sizeof(int), 1, f);
    			break;
    		}
    		case jgt_v:{

		        write_vmarg_output_binary(instr->arg1, f);

		        write_vmarg_output_binary(instr->arg2, f);

				write_vmarg_output_binary(instr->result, f);

                fwrite(&instr->srcLine, sizeof(int), 1, f);
    			break;
    		}
    		case call_v:{

		        write_vmarg_output_binary(instr->arg1, f);
                write_vmarg_output_binary(err, f);
                write_vmarg_output_binary(err, f);
                fwrite(&instr->srcLine, sizeof(int), 1, f);

    			break;
    		}
    		case pusharg_v:{

		        write_vmarg_output_binary(instr->arg1, f);
                write_vmarg_output_binary(err, f);
                write_vmarg_output_binary(err, f);
                fwrite(&instr->srcLine, sizeof(int), 1, f);

    			break;
    		}
    		case funcenter_v:{


                write_vmarg_output_binary(instr->result, f);
                write_vmarg_output_binary(err, f);
                write_vmarg_output_binary(err, f);
                fwrite(&instr->srcLine, sizeof(int), 1, f);
    			break;
    		}
    		case funcexit_v:{

                write_vmarg_output_binary(instr->result, f);
                write_vmarg_output_binary(err, f);
                write_vmarg_output_binary(err, f);
                fwrite(&instr->srcLine, sizeof(int), 1, f);
    			break;
    		}
    		case newtable_v:{


                write_vmarg_output_binary(instr->arg1, f);
                write_vmarg_output_binary(err, f);
                write_vmarg_output_binary(err, f);
                fwrite(&instr->srcLine, sizeof(int), 1, f);
    			break;
    		}
    		case tablegetelem_v:{
                write_vmarg_output_binary(instr->result, f);


		        write_vmarg_output_binary(instr->arg1, f);

		        write_vmarg_output_binary(instr->arg2, f);


                fwrite(&instr->srcLine, sizeof(int), 1, f);
                break;
    		}
    		case tablesetelem_v:{
                write_vmarg_output_binary(instr->result, f);


		        write_vmarg_output_binary(instr->arg1, f);

		        write_vmarg_output_binary(instr->arg2, f);


                fwrite(&instr->srcLine, sizeof(int), 1, f);
                break;
    		}
    		case nop_v:{
                write_vmarg_output_binary(err, f);
                write_vmarg_output_binary(err, f);
                write_vmarg_output_binary(err, f);
                fwrite(&yylineno, sizeof(int), 1, f);
    			break;
    		}
    		case jump_v:{


                write_vmarg_output_binary(instr->result, f);

                write_vmarg_output_binary(err, f);
                write_vmarg_output_binary(err, f);
                fwrite(&instr->srcLine, sizeof(int), 1, f);

    			break;
    		}
    		case ret_v:{
                write_vmarg_output_binary(instr->result, f);
                write_vmarg_output_binary(err, f);
                write_vmarg_output_binary(err, f);
                fwrite(&instr->srcLine, sizeof(int), 1, f);
    			break;
    		}
    		default:{
                write_vmarg_output_binary(instr->result, f);


		        write_vmarg_output_binary(instr->arg1, f);

		        write_vmarg_output_binary(instr->arg2, f);


                fwrite(&instr->srcLine, sizeof(int), 1, f);
		    	break;
			}
    	}


       
    }

    fclose(f);
}





void create_binary_file_bin(FILE* f){
    int amvbinaryfile = 340;
    int i;

    fwrite(&amvbinaryfile,  sizeof(int), 1, f);
    /* gravw global vars */
    fwrite(&global_var_counter, sizeof(int), 1, f);
    /* edw grafw ton arithmo twn string gia na kanw malloc sto avm */
    int arr_size = string_array.size;
    fwrite(&arr_size, sizeof(int), 1, f);

    /* grafw ta strings */
    for(i = 0; i < string_array.size; i++){
        char* s = table_get(&string_array, i).string;
        /* grafw to megethos tou string gia na borw na to diavasw me fread */
        int size = strlen(s);

 
        fwrite(&size, sizeof(int), 1, f);
        fwrite(s, strlen(s), 1, f);//, "%d\t\t\"%s\"\n", i, table_get(&string_array, i).string);


    }
    arr_size = num_array.size;
    fwrite(&arr_size, sizeof(int), 1, f);

    
    
    for(i = 0; i < num_array.size; i++){
        number_type p = table_get(&num_array, i).num_type;
            int size = sizeof(double);
            fwrite(&size, sizeof(int), 1, f);
            fwrite(&p->d, sizeof(double), 1, f);

    }
    arr_size = userfunc_array.size;
    fwrite(&arr_size, sizeof(int), 1, f);

    for(i = 0; i < userfunc_array.size; i++){
        Function* f1 = table_get(&userfunc_array, i).function;
        struct function_phase4 l = {f1->total_arguments, f1->line};
        int size = strlen(f1->name);

        fwrite(&l, sizeof(struct function_phase4), 1, f);

        fwrite(&size, sizeof(int), 1, f);
        fwrite(f1->name, size, 1, f);
        // fwrite(&f1->line, sizeof(int), 1, f);
        // fwrite(&f1->total_arguments, sizeof(int), 1, f);
        // fwrite(f1->name, strlen(f1->name), 1, f);
//      fprintf(f, "%d\t\t:address %d, local size %d, id \"%s\"\n", i, f1->line, f1->total_arguments, f1->name);
    }
    arr_size = libfunc_array.size;
    fwrite(&arr_size, sizeof(int), 1, f);

    for(i = 0; i < libfunc_array.size; i++){
        char* f1 = table_get(&libfunc_array, i).string;

        int size = strlen(f1);
        fwrite(&size, sizeof(int), 1, f);
        fwrite(f1, strlen(f1), 1, f);// "%d\t\t \"%s\"\n", i, f1);
    }



   

    fwrite(&yylineno, sizeof(yylineno), 1, f);
    fwrite(&local_size, sizeof(int), 1, f);
    int v = nextinstructionlabel();
    fwrite(&v, sizeof(int), 1, f);
 


}






void write_vmarg_output_binary(vmarg arg, FILE* f){
    fwrite(&arg->type, sizeof(int), 1, f);
    int size;
    switch(arg->type){
        case label_a:{
            
            
            //fwrite(s, strlen(s), 1, f);
            fwrite(&arg->val, sizeof(int), 1, f);// sizeof(int)<"00(label), %d", arg->val);
            break;
        }
        case global_a:{
            /* grafw scope_offset */
            fwrite(&arg->v_sym->scope_offset, sizeof(int), 1, f);
            /* grafw name size */
            char* s2 = arg->v_sym->value.varVal->name;
            size = strlen(s2);
            fwrite(&size, sizeof(int), 1, f);
            fwrite(s2, size, 1, f);
            //fprintf(f, "01(global), %d:%s", arg->v_sym->scope_offset, arg->v_sym->value.varVal->name);
            break;
        }
        case formal_a:{
            
            int offset = arg->v_sym->scope_offset;
            char* p2 = arg->v_sym->value.varVal->name;
            size = strlen(p2);
            /* write offset */
            fwrite(&offset, sizeof(int), 1, f);
            /* write name size */
            fwrite(&size, sizeof(int), 1, f);
            /* write name */
            fwrite(p2, strlen(p2), 1, f);// arg->v_sym->scope_offset, arg->v_sym->value.varVal->name);
            break;
        }
        case local_a:{
            int offset = arg->v_sym->scope_offset;
            char* p2 = arg->v_sym->value.varVal->name;
            size = strlen(p2);
            /* write offset */
            fwrite(&offset, sizeof(int), 1, f);
            /* write name size */
            fwrite(&size, sizeof(int), 1, f);
            /* write name */
            fwrite(p2, strlen(p2), 1, f);
            break;
        }
        case int_a:{       
            fwrite(&arg->val, sizeof(int), 1 ,f);
            break;
        }
        case double_a:{
            
            fwrite(&arg->val, sizeof(int), 1, f);
            break;
        }
        case string_a:{
            fwrite(&arg->val, sizeof(int), 1, f);
            break;
        }
        case bool_a:{
            fwrite(&arg->val, sizeof(int), 1, f);
            break;
        }
        case nil_a:{
            break;
        }
        case userfunc_a:{
            fwrite(&arg->val, sizeof(int), 1,  f);
            break;
        }
        case libfunc_a:{

            fwrite(&arg->val, sizeof(int), 1 ,  f);

            break;
        }
        case retval_a:{

            break;
        }
        case 13:{
            int unused = 666;
            fwrite(&unused, sizeof(int), 1, f);
            break;
        }
      }


}





