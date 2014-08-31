/*
 * wroted by roger
 */
/*
 * wroted by roger
 */

#ifndef __VALUE_H__
#define __VALUE_H__

#include "memory.h"

class Value {
	public:
		enum Type {
			NONE,
			INT,
			FLOAT,
			STR,
			REF
		};
		static Value ZERO;

		int length;

		inline Value(): length(0),type(NONE) { Memory::acquire(); data.s = NULL; };

		inline ~Value() {
			if( STR == type ) {
				Memory::singleton()->release( this->data.s );
			}else if ( REF == type ) {
				Memory::singleton()->release( this->data.ref );
			}
		}
		inline bool isNull() const{ return NONE == type; };

		inline const Value& operator = ( const Value& r ) {
			this->length = r.length;
			this->type   = r.type;
			if( STR == r.type ) {
				Memory::singleton()->realloc( this->data.s, r.length );
				memcpy( this->data.s, r.data.s, r.length );
			}else if ( INT == r.type ) {
				this->data.i = r.data.i;
			}else if ( FLOAT == r.type ) {
				this->data.f = r.data.f;
			}else if ( REF == r.type ) {
				this->data.ref = r.data.ref;
			}
		};
		inline Value& clone() {
			Value* p = new Value();
			if( !p )
				return ZERO;
			*p = *this;
			return *p;
		};

		inline Value( const char* str ) {
			*this = parseInt( str ).clone();
		};
		inline const char* toString() {
			char* str = (char*)Memory::singleton()->getInc();
			int n = 0;
			if( FLOAT == type )
				n = sprintf( str, "%f", data.f );
			else if( INT == type )
				n = sprintf( str, "%d", data.i );
			return str;
		};
		inline static Value& parseInt( const char* str ) {
			if( !str ) 
				return ZERO;
			Value* p = (Value*)Memory::singleton()->getInc();
			if( !p )
				return ZERO;
			Value& r = *p;

			r.type = INT;

			float d = 1.0f;
			int i = 0;

			for( ; *str ; str ++, r.length ++ ) {
				if( '-' == *str && INT == r.type ){
					i = -1;
				}else if( *str >= '0' && *str <= '9' ) {
					if( FLOAT == r.type ) {
						d *= 0.1f;
						r.data.f += d * (*str - '0');
					}else if( INT == r.type ) {
						i = i << 2;
						i = (i ++ ) << 1;
						i += *str - '0';
					}
				}else if( '.' == *str && INT == r.type ) {
					r.type = FLOAT;
				}else {
					return ZERO;
				}
			}
			if( FLOAT == r.type )
				r.data.f = i < 0 ? (float)i - d : (float)i + d;
			else
				r.data.i = i;
			return r;
		}
		inline static bool isBlankKey( const char c ) {
			return '\"' == c || '\\' == c || '/' == c || 'b' == c || 'f' == c || 'n' == c || 'r' == c || 't' == c ;
		}
		inline static Value& parseStr( const char* buf ) {
			if( !buf ) 
				return ZERO;
			Value* p = (Value*)Memory::singleton()->getInc( strlen(buf) );
			if( !p )
				return ZERO;
			Value& r = *p;

			r.type = STR;
			bool start = false;
			char* c = r.data.s;

			for( ; *buf ; buf ++ ) {
				if( '\"' == *buf ) {
					if( r.length > 0 ) 
						return r;
					else
						start = true;
				}else if( '\\' == *buf ) {
					buf ++;
					if ( isBlankKey( *buf ) )  {
						memcpy( c, buf - 1, 2 );
						c += 2;
						r.length += 2;
					}else {
						return ZERO;
					}
				}else if ( start ){
					memcpy( c ++, buf, 1 );
					r.length ++;
				}
			}
			return r;
		};
		typedef union _Data{
			int i;
			float f;
			char* s;
			void* ref;
		} Data;
		Data data;
		Type type;
};

Value Value::ZERO = Value();

#endif
