#include "avm.h"


void avm_table_bucketsinit(struct avm_table_bucket** p) {
	unsigned i;
	for (i = 0; i < AVM_TABLE_HASHSIZE; ++i) 
		p[i] = (struct avm_table_bucket*) 0;
}

avm_table avm_tablenew(void) { 
	struct avm_table* t = calloc(sizeof(struct avm_table), sizeof(struct avm_table));
	AVM_WIPEOUT(*t);
	t->refCounter = t->total = 0;
	avm_table_bucketsinit(t->numIndexed);
	avm_table_bucketsinit(t->strIndexed);

	return t;
}

void avm_tablebucketsdestroy (struct avm_table_bucket** p) {
	unsigned i;
	avm_table_bucket b;
	avm_table_bucket del;
	for (i = 0; i < AVM_TABLE_HASHSIZE; ++i, ++p) { 
		for(b = *p; b;) {
			del = b;
			b = b->next;
			avm_memcellclear(&del->key);
			avm_memcellclear(&del->value);
			free(del);
		}
		p[i] = (avm_table_bucket) 0; /*struct avm_table_bucket* === avm_table_bucket*/
	}
}

void avm_tabledestroy(struct avm_table* t) {
	avm_tablebucketsdestroy(t->strIndexed);
	avm_tablebucketsdestroy(t->numIndexed);
	free(t);
}

void avm_tableincrefcounter(struct avm_table* t) {
	++t->refCounter;
}

void avm_tabledecrefcounter (struct avm_table* t) {
	assert(t->refCounter > 0);
	if(!--t->refCounter)
		avm_tabledestroy(t);
}
avm_memcell avm_tablegetelem(avm_table t, avm_memcell key) {
	return NULL;
}
void avm_tablesetelem(struct avm_table* t, struct avm_memcell* key,struct avm_memcell* value){
}