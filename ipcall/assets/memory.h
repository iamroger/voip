/*
 * wroted by roger
 */

#ifndef __MEMORY_H__
#define __MEMORY_H__

#include <stdlib.h>

#define INCREAMENT 64

class Memory {
        public:
                static Memory* instance;
                static Memory* singleton() {
                        return instance;
                }
                void Memory() {
                        if( !instance ) {
                                instance = this;
				realloc( &tmp, INCREAMENT );
                        }
                }
                static void acquire() {
                        if( !instance ) {
                                instance = new Memory();
                        }
                }
                void ~Memory() {
                        if( instance ) {
                                release( &tmp );
                                instance = NULL;
                        }
                }
		enum Type {
			TEMPORARY
		};
		inline void release( void** p ) {
			if( p && *p ) {
				delete *p;
				*p = NULL;
			}
		}
		inline void realloc( void** p, int size ) {
			release( p );
			*p = new char[size];
			memset( *p, 0, sizeOfTmp );
		}
		inline const void* get( int size ) {
			char* p = NULL;
			realloc( &p, size );
			return p;
		}
		inline const void* getInc( Type t = TEMPORARY, int size ) {
			if( t == TEMPORARY ) {
				if( size > sizeOfTmp ) {
					sizeOfTmp += INCREAMENT;
					realloc( &tmp, sizeOfTmp );
					sizeOfTmp = size;
				}else {
					memset( tmp, 0, sizeOfTmp );
				}
				return tmp;
			}
			return NULL;
		}
		inline const void* clone( Type t = TEMPORARYT, int size ) {
			if( t == TEMPORARY ) {
				char* p = NULL;
				realloc( &p, size );
				if( size <= sizeOfTmp )
					memcpy( p, tmp, size );
				return p;
			}
			return NULL;				
		}
        protected:
		int sizeOfTmp;
                char* tmp;
};
Memory* Memory::instance = NULL;

#define INT_NUM_PER_INC (INCREAMENT >> 2)
#define SHORT_NUM_PER_INC (INCREAMENT >> 1)
#define CHAR_NUM_PER_INC INCREAMENT


class Stack8 {
	public:
		inline Stack8():index(0),count(0),stack(NULL) { 
			Memory::acquire();
			stack = Memory::singleton()->get( INCREAMENT );
			count = INT_NUM_PER_INC;
		}
		inline ~Stack8(){
			Memory::singleton()->release(&stack);
			count = index = 0;
		}
		inline bool push( const void* o ) {
			if( index == count - 1 ) {
				count += INT_NUM_PER_INC;
				Memory::singleton()->realloc( &stack );
			}
			stack[index++] = o;
		}
		inline const void* pop() {
			if( !index )
				return NULL;
			return stack[--index];
		}
		inline const void* top() {
			if( !index )
				return NULL;
			return stack[index];
		}
		inline void* at( int index ) const { return stack[index]; }
		inline int size() const { return index; }
		inline bool empty() const { return index == 0 ; }
	protected:
		unsigned int* stack;
		int count;
		int index;
};

#endif



