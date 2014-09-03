/*
 * wroted by roger
 */

#ifndef __MEMORY_H__
#define __MEMORY_H__

#include "..\..\inc\type.h"

class Memory {
	public:

		Memory() {
			if( !instance ) {
				instance = this;
				numOfPartitions = Partition::NUM;
			}
		}
		inline static void acquire() {
			if( !instance ) {
				instance = new Memory();
				int i;
				const int size[Partition::NUM][3] = {
					/* name					size			can */
					{ Partition::LOCAL,		1024,			0 },
					{ Partition::GLOBAL,	1024*3,			1024 },
					{ Partition::ARRAY,		1024*3,			1024 },
				};
				for( i = 0 ; i < Partition::NUM ; i ++ ) {
					realloc( instance->parts[i].addr, size[Partition::LOCAL][1] );
					realloc( instance->parts[i].can,  size[Partition::LOCAL][2] );
					if( instance->parts[i].addr && instance->parts[i].can )
						instance->parts[i].size = size[Partition::LOCAL][1];
				}
			}
		}
		inline static void destroy() {
			if( !instance ) {
				delete instance;
			}
		};
		/* alloc new partition */
		void request( int no, int size ) {
			if( no < Partition::NUM )
				return ;
			realloc( parts[no].addr, size );
			realloc( parts[no].can, size );
			if( parts[no].addr && parts[no].can )
				parts[no].size = size;
		};
		inline void* get( int no, int size ) {
		};
		/* alloc in local partition */
		inline static void* get( int size ) {
		};
		/* alloc in global partition */
		inline static void* alloc( int size ) {			
		};
		/* free in partition, used for object destroy */
		inline static void release( void* p ) {
			ui32* a = (ui32*)p;
			a --, a --;
			*a = UNHOLD;
			
		};
		inline static void report() {
			if( instance ) {
				PRINT( " LOCAL size %d, extend %d", instance->parts[Partition::LOCAL].size );
			}
		};
	protected:
		static Memory* instance;

		enum Tag {
			HOLD = 0xFFFFFFFF,
			UNHOLD = 0xAAAAAAAA
		};

		int numOfPartitions;

		struct Partition {
			enum Type {
				/* used for function, del or new frequently, improve performance */
				LOCAL = 0,
				ARRAY,
				/* used for object, instance , no frequently */
				GLOBAL,
				NUM,
				MAX = 8
			};
			struct BlockDesc {
				Tag* tag;
				BlockDesc* next;
				/* this
				   ...mem hold by object
				 */
			};
			int size;
			BlockDesc* addr;
			BlockDesc* can;
			BlockDesc* free_head;
			BlockDesc* free_tail;
			inline Partition() 
				: size(0),addr(NULL),can(NULL),free_tail(NULL),free_head(NULL) 
			{}
			inline ~Partition() {
				free( addr );
				free( can ); 
				free_head = NULL;
				free_tail = NULL;
			};
		};
		Partition parts[Partition::MAX];

		inline void recyle( Partition::BlockDesc* p ) {
			p->tag->free_tail->next = p;
			p->
		}

		inline static void free( void* p ) {
			if( p && *(ub8**)p ) {
				delete *(ub8**)p;
				*(ub8**)p = NULL;
			}
		};
		inline static void realloc( void* p, int size ) {
			free( p );
			*(ub8**)p = new ub8[size];
			memset( *(ub8**)p, 0, size );
		};
};
Memory* Memory::instance = NULL;

inline void * operator new(size_t size){
	return Memory::alloc( size ); 
};
inline void * operator new[](size_t size){
	return Memory::alloc( size ); 
};
/*
inline void * operator new(size_t size, void *p){
	return Memory::alloc( size ); 
};
inline void *operator new[](size_t size, void *p) {
	return Memory::alloc( size ); 
};
*/
void operator delete(void * p){
    Memory::release( p ); 
};
void operator delete [] (void * p){
    Memory::release( p ); 
};

#endif
