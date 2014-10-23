
#ifndef CXX_MIRACLE_PARSER_H
#define CXX_MIRACLE_PARSER_H

namespace Miracle
{
    class CharTextureParser : public SSM {
    public:
        virtual SSM* construct();
        
        virtual void input( const Stream& s );
    protected:
        HashMap<char,Vector2*> mCharMap;
    }
}

#endif