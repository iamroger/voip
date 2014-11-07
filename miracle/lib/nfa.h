#ifndef CXX_MIRACLE_NFA_H
#define CXX_MIRACLE_NFA_H

namespace Miracle
{


typedef struct _state {
    int c;
    struct _state* child;
    struct _state* silbing;
} State; 

class NFA {
    public:
        void build( const char* regex ) {
            State* tail;
            int len = strlen(regex);
            int* nfa = new int(len*3);
            int c = 0, n = 0, brace_atom_num = 0;
            for( int i = 0 ; i < len ; i ++ ) {
                c = *(regex+i);
                if( c < ' ' || c > '~' ) {
                    continue;
                }else if ( c == '|' ) {
                    mStack.pop( brace_min_num - 1 );

                    tail = mStack.top();
                    tail.silbing = 
                }else if ( c == '*' ) {
                }else if ( c == '(' ) {
                    brace_atom_num = 1;
                }else if ( c == ')' ) {
                    brace_atom_num = 0;
                }else {
                    State* state = new (nfa+n*3) State();
                    n++;

                    tail = mStack.top();
                    tail.child = state;
                    state.c = c;
                    mStack.push( state );

                    if( brace_atom_num ){
                        brace_atom_num ++;
                    }else{
                        
                    }
                }
            }
        }
    protected:
        int mStartPush;
        Stack mStack;
}
#endif
