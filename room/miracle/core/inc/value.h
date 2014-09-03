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
};

Value Value::ZERO = Value();

#endif
