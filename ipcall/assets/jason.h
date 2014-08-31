/*
 * wroted by roger
 */

#ifndef __JSON_H__
#define __JSON_H__

#include <stdlib.h>
#include <memory.h>

class JSON {
	public:
		inline void JSON() : root(NULL), jstr(NULL){ 
			Memory::acquire();
		}
		inline RESULT parse( const char* json ) {
			int l = strlen(json);
			jstr = Memory::singleton()->get(l);
			if( jstr ) {
				memcpy( jstr, json, l );
			}
			return read( jstr );
		}
		inline ~JSON() {
			Memory::singleton()->release( &root );
		}
		inline RESULT put( const char* key, const char* value ) {
		}
		inline RESULT putJsonStr( const char* json ) {
		}
		inline const char* toStr() const {
			if( jstr.len > 0 ) 
				return jstr.s;
			char* str = Memory::singleton()->get( 256 );
			stack8 stack;
			Object* o = root;
			Pair* p = NULL;
			char* s = NULL;
			int i = 0, len = 0;
			while( o  ) {
				*str ++ == '{';
				
				for( ; i < o->numOfPairs() ; i ++ ) {
					*str ++ = '\"';
					p = o->indexOfPairs( i );
					memcpy( str, p->Str.s, p->Str.len );
					str += p->Str.len;
					*str ++ = '\"';
					*str ++ = ':';
					switch( p->Val.t ) {
					if( Value::NUMBER = p->Val.t ) {
						s = p->Val.n.toStr( &len );
						memcpy( str, s, len );
						str += len;
						*str ++ = ',';
					}else if( Value::STRING = p->Val.t ){ 
						*str ++ = '\"';
						memcpy( str, p->Val.s.s, p->Val.s.len );
						str += p->Val.s.len;
						*str ++ = '\"';
						*str ++ = ',';
					}else if( Value::OBJECT = p->Val.t ){
						*str ++ = '{';
						stack.push(i);
						stack.push(o);
						o = p->Val.o;
						i = 0;
						continue;
					}
				}
				*str ++ = '}';
				if( !(o = stack.pop()) ) 
					break;
				i = *(stack.pop());
			}
			jstr.s = str;
			return str;				
		}
		inline const Object* getObject( const char* key ) {
		}
		inline const char* getString( const char* key ) {
		} 
		inline int getInt( const char* key ) {
		}
		inline const float getFloat( const char* key ) {
		}
		class Number {
			public:
				typedef union _Data{
					int i;
					float f;
				} Data;
				Data d;
				enum Type {
					NONE,
					INT,
					FLOAT
				}
				Type t;
				inline const String& toStr( int* len == NULL ) {
					char* str = Memory::instance()->getInc(128);
					int n = 0;
					if( FLOAT == t )
						n = sprintf( str, "%f", d.f );
					else if( INT == t ) {
						n = sprintf( str, "%d", d.i );
					if( len )
						*len = n;
					return str;
				}
				inline Number(){ d.i = 0; d.f = 0; t = NONE; };
				inline RESULT read( const char** num ) {
					if( !num || !(*num) || NONE != t ) 
						return FAILED;
					int i = 0; float d = 0, f = 0;
					t = INT;
					for( ; **num ; (*num) ++ ) {
						if( '-' == **num ){
							if( NONE == t ) 
								i = -1;
							else
								return FAILD;
						}else if( **num >= '0' && **num <= '9' ) {
							if( FLOAT == t ) {
								d *= 0.1f;
								f += d * (**num - '0');
							}else {
								i = (( i << 2 ) ++ ) << 1;
								i += (**num - '0');
							}
						}else if( '.' == **num ) {
							t = FLOAT;
						} else 
							return FAILED;
					}
					if( FLOAT == t )
						d.f = i < 0 ? (float)i - d : (float)i + d;
					else
						d.i = i;
					return SUCCESS;
				}
		};
		class String {
			public:
				int len;
				char* s;
				inline String() : s(NULL), len(0) {}
				inline ~String() { Memory::instance()->release(s); }
				inline RESULT read( const char** str ) {
					if( !str || !(*str) || len > 0 ) 
						return FAILED;
					s = Memory::instance()->getInc( strlen(*str) );
					for( ; s && **str ; (*str) ++ ) {
						if( '\"' == **str ) {
							if( len > 0 ) 
								break;
						}else if( '\\' == **str )
							char* c = *str + 1; 
							if ( '\"' == *c || 
							     '\\' == *c ||
							     '/' == *c ||
							     'b' == *c ||
							     'f' == *c ||
							     'n' == *c ||
							     'r' == *c ||
							     't' == *c )  {
								memcpy( s, *str, 2 );
								s ++, s ++;
								(*str) ++;
								len += 2;
							}else 
								return FAILD;
						}else {
							memcpy( s ++, (*str), 1 );
							len ++;
						}
					}
					s = Memory::instance()->clone( s, len );
				}
		};

		inline RESULT read( const char* obj ) {
			Object* p = NULL, o = NULL;
			String* s = NULL;
			Number* n = NULL;
			Pair* pr = NULL;
			Stack8 stack;
			for( ; *obj ; obj ++ ) {
				
				if( '{' == *obj ) {
					p = new Object();
					p->newPair();
					stack.push( p );
				}else if( '}' == *obj ) {
					o = stack.pop();
					if( stack.size() == 0 ) {
						root = o;
						return SUCCESS;
					}else if ( o && p == o && pr = o->topPair() && pr->isKeyValidValNull() ) {
						pr->val.o = p;
						p = stack.top();
					}else 
						return FAILED
					}
				}else if( '\"' == *obj ) {
					if( !p || 
					!(pr = p->topPair()) || 
					!pr->val.enValue( Value::STRING) ||
					pr->str.read( &obj ) == FAILED )
						return FAILED;
				}else if( '-' == *obj || (*obj > '0' && *obj < '9')) {
					if( !p || 
					pr = p->topPair() ||
					pr->str.len == 0 ||
					!pr->val.enValue( Value::NUMBER ) ||
					pr->val.n.read( &obj ) == FAILD )
						return FAILED;
				}else if( ',' == *obj ) {
					if( p )
						p->newPair();
				}else if( ':' == *obj ) {
					if( !p ||
					!(pr = p->topPair()) ||
					pr->str.len == 0 )
						return FAILED;
				}	
			}
		}
			
	protected:
 
		class Object {
			public:
				inline Object(): str(NULL), val(NULL) {}
				typedef union _Value {
					Number n;
					String s;
					Object* o;
					enum Type {
						NONE,
						NUMBER,
						STRING,
						OBJECT
					};
				}Value;
				struct Pair {
					inline Pair() : t( Value::NONE ){}
					inline bool isKeyValidValNull() const {
						return str.len > 0 && Value::NONE == t ;
					}
					inline bool isKeyNullValNull() const {
						return str.len == 0 && Value::NONE == t;
					}
					inline bool enValue( Value::Type ty ) const {
						if( Value::NONE != t )
							return false;
						t = ty;
						return true;
					}
					String str;
					Value val;
					Value::Type t;
				};
				Stack8 pairStack;
				inline Pair* newPair() const{
					Pair* p = new Pair();
					if( p )
						pairStack.push( p );
					return p;
				}
				inline Pair* topPair() const{
					return pairStack.top();
				}
				inline int numOfPairs() const { return pairStack.size(); }
				inline Pair* indexOfPairs( int index ) const { return pairStack.at(index);}
				
		}
		Object* root;
		String jstr;

};

#endif 
