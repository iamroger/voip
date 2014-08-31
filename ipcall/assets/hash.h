/*
 * wroted by roger
 */
#ifndef __HASH_H__
#define __HASH_H__

#include <stdlib.h>
#include <memory.h>

#define BOARD 8
#define PIECES 36
#define BOARDPIECES 288

class Hash {
	public:
		inline static int srand( long r ) {
			seed = r;
		}
		inline static long rand(){
			seed = seed << 16 + seed << 8 + seed << 4 + seed + 37;
			return seed;
		}
		inline static void init() {
			int i = 0;
			srand(53);
			for( i = 0 ; i < BOARDPIECES ; i ++ )
				table[i] = rand() % 10000;
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
		static int table[BOARD][PIECES];
};

bool Hash::valid = false;
long Hash::seed = 0;
int Hash::table[BOARD][PIECES] = {0};

class HashMap {
	public:
		static long MAPSIZE;
		inline HashMap() : list(NULL),numOfPairs(0) {
			Memory::acquire();
			list = (Pair*)Memory::singleton()->get(MAPSIZE*sizeof(Pair));
		}
			
		inline RESULT add( const char* key, const void* value ) {
			if( nmmOfPairs == MAPSIZE || !list )
				return FAILED;
			int i = Hash::getHashCode( key, MAPSIZE );
			while ( list[i].valid ) {
				MAPSIZE == i ? i = 0 : i ++ ;
			}
			if( i < MAPSIZE ){
				list[i].key = key;
				list[i].val = value;
				list[i].valid = true;
				return SUCCESS;
			}
			return FAILED;
		}
		inline const void* get( const char* key ) {
			int i = Hash::getHashCode( key, MAPSIZE );
			while ( list[i].valid && list[i].key != key ){
				MAPSIZE == i ? i = 0 : i ++ ;
			}
			if( i < MAPSIZE )
				return list[i].val;
			return NULL;
		} 
	protected:
		struct Pair {
			char* key;
			void* val;
		};
		int numOfPairs;
		Pair* list;
}
long HashMap::MAPSIZE = 0x000001FF;

#endif
