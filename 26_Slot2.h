#ifndef __SLOT2_H__
#define __SLOT2_H__

#include "26_Person.h"

typedef int Key;
typedef Person * Value;

typedef struct _slot
{
	Key key;
	Value val;
}Slot;

#endif // !__SLOT2_H___
