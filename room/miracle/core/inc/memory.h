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
				const int size[Partition::NUM][4] = {
					/* name					count of instance			tag index			tag */
					{ Partition::LOCAL,		1024*3,						0,					0 },
					{ Partition::GLOBAL,	1024*3,						12*1024,			8*1024 },
					{ Partition::ARRAY,		1024*3,						12*1024,			8*1024 },
				};
				for( i = 0 ; i < Partition::NUM ; i ++ ) {
					realloc( instance->parts[i].addr, size[i][1] );
					realloc( instance->parts[i].tagsidx,  size[i][2] );
					realloc( instance->parts[i].tags,  size[i][3] );
					if( instance->parts[i].addr && instance->parts[i].tags && instance->parts[i].tagsidx ){
						instance->parts[i].numOfBlocks = size[i][1];
						instance->parts[i].numOfTagIdx = size[i][1];
						instance->parts[i].numOfTags = size[i][1];
					}
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

		int numOfPartitions;
/*
3	4	5	6	7	8	9	10	11	12	13	14	15	16	17

1	1	1	3	3	4	4	4	6	6	6	8	9	9	9
y	n	y	y	n	y	n	y	y	y	n	n	n	y	n

			6		4
			n		y

1:1(4), 3:1(6), 4:1(9), 6:2(11), 8:1(13), 9:2(15)

5 new
from 11, 5 <> 6, so offset is not changed  [11] = y, 6:2(11) -> 6:1(13)
1) binary search tag, get block addr is 11 & get tag addr is 3
2) if n + xxx < tag[3].width then { split( block[11] )->a, b, insert( tag,  b) } else block[11].sign = y
3) tag[11].num --, if( tag[11].num > 0 ) tag[11].start +=?; 


1:1(4), 3:1(6), 4:1(9), 6:1(11), 8:1(13), 9:2(15)

6(3) delete

1) if block[7].sign == n 
then 1 = block[7].sign; block[6].offset = block[6].offset + block[7].offset + xxx
1:1(4), 3:1(6), 4:1(9), 6:1(6), 6:1(11), 8:1(13), 9:2(15)

1:1(1), 3:1(2), 4:1(3), 6:2(4), 8:1(5), 9:1(6)
*/
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
			struct Tag;
			struct BlockHead {
				enum Sign {
					HOLD = 0xFFFFFFFF,
					UNHOLD = 0xAAAAAAAA
				};
				union Head{
					Sign sig;
					Tag* tag;
				};
				Head head;
				BlockHead* offset;
				/* this
				   ...mem hold by object
				 */
			};
			struct TagIndex;
			struct Tag {
				BlockHead* bh;
				TagIndex* ti;
			};
			struct TagIndex {
				int width;
				int count;
				Tag* tag;
			};
			int numOfBlocks;
			BlockHead* addr;
			int numOfTags;
			Tag* tags;
			int numOfTagIdx;
			TagIndex* tagsidx;
			inline Partition() 
				: addr(NULL),tags(NULL),tagsidx(NULL),numOfBlocks(0),numOfTags(0),numOfTagIdx(0)
			{}
			inline ~Partition() {
				free( addr );
				free( tags ); 
			};
			inline void insertTag( const Tag& t ) {
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
