/*
 * wroted by roger
 */
#ifndef __HASH_H__
#define __HASH_H__

#include "memory.h"

#define BOARD 8
#define PIECES 36
#define BOARDPIECES 288


class Hash {
	public:
		inline static void srand( long r ) {
			seed = r;
		}
		inline static long rand(){
			seed = ( seed << 16 ) + ( seed << 8 ) + ( seed << 4 ) + seed + 37;
			return seed;
		}
		inline static void init() {
			int i, j;
			srand(53);
			for( i = 0 ; i < BOARD ; i ++ )
				for( j = 0 ; j < PIECES ; j ++ )
					table[i][j] = rand() % 10000;
		}
		inline static int getHashCode( const char* k, long mask ) {
			if( !valid )
				init();
			int b = strlen(k);
			if( b > BOARD ) 
				return -1;
			int i; long hash;
			for( i = 0, hash = b ; i < b ; i++ )
				hash ^= table[i][k[i]];
			return (int)(hash & mask);
		}
		
	protected:
		static bool valid;
		static long seed;
		static long table[BOARD][PIECES];
};

bool Hash::valid = false;
long Hash::seed = 0;
long Hash::table[BOARD][PIECES] = {0};

class HashMap {
	public:
		static long MAPSIZE;
		inline HashMap() : list(NULL),numOfPairs(0) {
			Memory::acquire();
			list = (Pair*)Memory::singleton()->get(MAPSIZE*sizeof(list[0]));
		}

		inline ~HashMap() {
			Memory::singleton()->release( &list );
		}
			
		inline RESULT add( const char* key, const void* value ) {
			if( numOfPairs == MAPSIZE || !list )
				return FAILED;
			int i = Hash::getHashCode( key, MAPSIZE - 1 );
			printf("%d\n",i);
			while ( list[i].key ) {
				MAPSIZE == i ? i = 0 : i ++ ;
			}
			if( i < MAPSIZE ){
				list[i].key = key;
				list[i].val = value;
				numOfPairs ++;
				return SUCCESS;
			}
			return FAILED;
		}
		inline const void* get( const char* key ) const {
			int i = Hash::getHashCode( key, MAPSIZE - 1 );
			while ( list[i].key != key ){
				MAPSIZE == i ? i = 0 : i ++ ;
			}
			if( i < MAPSIZE )
				return list[i].val;
			return NULL;
		} 
	protected:
		struct Pair {
			Pair():key(NULL),val(NULL){}
			const char* key;
			const void* val;
		};
		int numOfPairs;
		Pair* list;
};
long HashMap::MAPSIZE = 0x00000100;

#endif
