
#include "parser.h"


SSM* CharTextureParser::construct(){
    _B() > _T("char") > _S("props"); 
    _S("props") = _S("lvalue") > _T('=') > _S("rvalue");
    _S("lvalue") = "id";
    _S("lvalue") = "x";
    _S("lvalue") = "y";
    _S("lvalue") = "width";
    _S("lvalue") = "height";
    _S("rvalue") = _S("/[0-9]{1}/");
}

void CharTextureParser::input( const Stream& in ){
    char c = 0;
    while( c = in.get() ) {
        exec(c);
    }
}