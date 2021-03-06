
#include "_malloc.h"

int initialized = 0;

void set_used(void* ptr){
	*(int *)ptr = 1;
}

void set_unused(void* ptr){
	*(int *)ptr = 0;
}

void set_block_size(void * ptr, size_t size){
	*(int *) (ptr + sizeof(int)) = size;
}

void set_next_block(void *ptr, size_t ex_size, size_t size){
	void* next = NEXT_BLOCK(ptr);
	set_unused(next);
	set_block_size(next, ex_size - size);
}

void* allocate_block(void * ptr, size_t size){
	size_t ex_size = BLOCK_SIZE(ptr);
	set_used(ptr);
	set_block_size(ptr, size);
	set_next_block(ptr, ex_size, size);

	return ptr + sizeof(header);
}

void* pre_block(void *ptr){
	void* start = HEAP_START;
	if(ptr == start)
		return NULL;

	return ptr - BLOCK_SIZE(ptr);
}

void mem_initialize(){
	void* ptr = HEAP_START;
	void* end = HEAP_END;
	set_unused(ptr);
	set_block_size(ptr,(end - ptr) + 1);
	initialized = 1;
}

void* _malloc(size_t size){
	if(!initialized)
		mem_initialize();

	void* cur = HEAP_START;
	void* end = HEAP_END;
	size += sizeof(header);

	do {
		if(IS_USED(cur) || BLOCK_SIZE(cur) < size)
			continue;

		return allocate_block(cur, size);

	} while(NEXT_BLOCK(cur) >= end);

	/* TODO:단편화 확인 및 재배열 코드 추가 */
	/* 또는 가상메모리 사용할지 고민 중 */

	return NULL;
}

void _free(void * ptr){
	set_unused(ptr);
	void *next_ptr = NEXT_BLOCK(ptr);
	if( next_ptr!= NULL && !IS_USED(next_ptr)){
		set_block_size(ptr, BLOCK_SIZE(ptr) + BLOCK_SIZE(next_ptr));
	}

	void* pre_ptr = pre_block(ptr);
	if(pre_ptr != NULL && !IS_USED(pre_ptr)){
		set_block_size(pre_ptr, BLOCK_SIZE(ptr) + BLOCK_SIZE(pre_ptr));
	}

}
