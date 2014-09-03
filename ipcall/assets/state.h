/*
 * wroted by roger
 */

#ifndef __STATE_H__
#define __STATE_H__
#include "memory.h"
/*
 * example 1.cpp: _S("object").start() > _streamT("={") > _S("string") > _streamT("=,") \
 *                                                     > _S("value") > _streamT("=}") > _S("object").end();
 *              _S("object").start() > _streamT("={|=\b*|=}") > _S("object").end(); 
 *              _S("value").start() > _streamT("={") > _S("object") > _streamT("=}") > _S("value").end();
 *              _S("value").start() > _streamT("=\"") > _S("string") > _streamT("=\"") > _S("value").end();
 *                                        // \" will be transferred into next state 
 *              _S("string").start() > _streamT("!\b|!\"") > _S("string") > _streamT("=\"") > _S("string").end();
 *              
 *              struct object {
 *                  struct pair {
 *                      string str;
 *                      value val;
 *                  };
 *                  stack pairs;
 *              };
 *              object root;
 *              _S("object").getContext().add( "curr_object", &root ); 
 *              
 *              if( _S("object").receive(Stream(userdata)) == SUCCESS ) 
 *                  root.print();
 *
 *              _DECL_START("object") ( const Context& ctx, const Message& msg ) {
 *                  ctx("curr_object") = new object();
 *                  ctx("curr_pair") = 0;
 *              }
 *              _DECL_START("value") ( const Context& ctx, const Message& msg ) {
 *                  ctx("curr_pair") = ((object)ctx("curr_object")).newPair();
 *              }
 *              _DECL_END("string") ( const Context& ctx, const Message& msg ) {
 *                  if( ctx("curr_pair") )
 *                      ((pair)ctx("curr_pair"))->str.clone();
 *              }
 *              _DECL("string") ( const Context& ctx, const Message& msg ) {
 *                  if( ctx("curr_pair") )
 *                      ((pair)ctx("curr_pair"))->str.append( msg.toStream() );
 *              }
 *          2:  struct play : public scene {
 *                  card cards[8];
 *              };
 *              struct menu : public scene {
 *                  btn[0] = "zhangsan";
 *                  btn[1] = "lisi";
 *                  ...
 *                  btn[n] = "exit";
 *              };
 *              play play_scene("play");
 *              menu menu_scene("menu");
 *              _S("menu").start() > _msgT("btn.clk") > _S("play").start();
 *              _S("menu").start() > _msgT("exit") > _S("menu").end();
 *              _S("play") > _msgT("hit") > _S("card") > _msgT("touch.up") > _S("play");
 *              
 *              _DECL_START("play")( const Context& ctx, const Message& msg ) {
 *                  request( "play:{usera:"+msg.data("btn.name")+",userb:"+this.name+"}" );
 *              }
 *     3rd lib: _streamT
 *              _S("rule").start() > _T('=') > _S("next");
 *              _S("next") > _T() > _S("pass");      // any code, it append the latest state.
 *              _S("next") > _T('|') > _S("next");
 *              _S("next") > _T('&') > _S("next");   // I want stop trans in advance via to previous result 
 *              _S("next") > _Assert() > _S("pass");
 *              _S("next") > _T('>') > _S("next");
 *              _S("next") > _T('<') > _S("next");
 *              _S("next") > _T('!') > _S("next");
 *              _S("next") > _T('\') > _S("special");
 *              _S("special") > _T('.') > _S("next");
 *              _S("pass") > _T() > _S("rule").end();
 *              
 *              _DECL("next") ( const Context& ctx, const Message& msg ) {
 *                   
 */
class State {
	public:
		enum Type {
			NONE,
			STARTEND,
			USER,
		};
		State( const char* name );

		/* default is that mgr construct static singleton NONE state*/
		State();

		/* return STARTEND, start is same end */
		const State& start();

		const State& end();

		RESULT operator> ( const Transition* t) const;


	protected:
		HashMap transitions;
};

typedef State _S;

class Transition {
	public:
		Transition* operator> ( const State& t ) const;
		
		Transition* operator> ( const State* t ) const;
	protected:
		State targetState;
};

typedef Transition _T;

class StreamTransition : public Transition {
	public:
		void StreamTransition( const char* filters );
		/* a. <9:>0 b. =\thello c. =\:  ...*/
		void setFilterSet( const char* filters );
};
typedef StreamTransition _streamT;

class MessageTransition : public Transition {
	public:
		MessageTransition( const Message& msg );
	protected:
		void enqueue();
};


class StateManager {
	public:
		RESULT createState( const char* name );

		void destoryState( const char* name );

		const static State& getState( const char* name ) const;

		RESULT createTrans( const char* name );

                void destoryTrans( const char* name );

		const static Transition& getTrans( const char* name ) const;
	protected:
		HashMap states;
		HashMap transitions;
};

#endif
