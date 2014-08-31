/*
 * wroted by roger
 */

#ifndef __MEMORY_H__
#define __MEMORY_H__

#include <stdlib.h>
#include <stdio.h>
#include <string.h>


#define INCREAMENT 64

enum RESULT{
	FAILED = -1,
	SUCCESS
};

class Memory {
        public:
                static Memory* instance;
                static Memory* singleton() {
                        return instance;
                }
                Memory() : tmp(NULL),sizeOfTmp(INCREAMENT) {
                        if( !instance ) {
							instance = this;
							realloc( (void**)&tmp, sizeOfTmp );
                        }
                }
                static void acquire() {
                        if( !instance ) {
                                instance = new Memory();
                        }
                }
                ~Memory() {
                        if( instance ) {
                                release( &tmp );
                                instance = NULL;
                        }
                }
		enum Type {
			TEMPORARY
		};
		inline void release( void* p ) {
			if( p && *(unsigned char**)p ) {
				delete *(unsigned char**)p;
				*(unsigned char**)p = NULL;
			}
		}
		inline void realloc( void* p, int size ) {
			release( p );
			*(unsigned char**)p = new unsigned char[size];
			memset( *(unsigned char**)p, 0, size );
		}
		inline const void* get( int size ) {
			void* p = NULL;
			realloc( &p, size );
			return p;
		}
		inline const void* getInc( Type t = TEMPORARY, int size = INCREAMENT ) {
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
		inline const void* clone( Type t = TEMPORARY, int size = INCREAMENT ) {
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
			stack = (unsigned int*)Memory::singleton()->get( INCREAMENT );
			count = INT_NUM_PER_INC;
		}
		inline ~Stack8(){
			Memory::singleton()->release(&stack);
			count = index = 0;
		}
		inline void push( const void* o ) {
			if( index == count - 1 ) {
				count += INT_NUM_PER_INC;
				Memory::singleton()->realloc( &stack, count*sizeof(stack[0]) );
			}
			stack[index++] = (unsigned int)o;
		}
		inline const void* pop() {
			if( !index )
				return NULL;
			return (void*)stack[--index];
		}
		inline const void* top() {
			if( !index )
				return NULL;
			return (void*)stack[index];
		}
		inline void* at( int index ) const { return (void*)stack[index]; }
		inline int size() const { return index; }
		inline bool empty() const { return index == 0 ; }
	protected:
		unsigned int* stack;
		int count;
		int index;
};

#endif
