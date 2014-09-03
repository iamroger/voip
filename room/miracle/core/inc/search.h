#ifndef __SEARCH_H__
#define __SEARCH_H__

#include "..\..\inc\type.h"

class Search {
	public:
		struct result {
			int flag;
			int pos;
		};
		inline static const result binary( ui32 a[], int len, ui32 key ) {
			int i, j, k;
			i = 0, j = len >> 1, k = len - 1;

			while( key != a[j] && i + 2 < k ) {
				if( key > a[j] ) {
					i = j + 1;
				}else{
					k = j - 1;
				}
				j = ( i + k ) >> 1;
			};
			result res;
			if( key == a[j] ) {
				res.pos = j;
				res.flag = OK;
			}else if( key < a[i] ) {
				res.pos =  --i;
				res.flag = FAILED;
			}else if( key > a[k] ) {
				res.pos = k;
				res.flag = FAILED;
			}
			return res;
		};


};



#endif
