#ifndef __SLOT2_H__
#define __SLOT2_H__

#include "11_Person.h"

typedef int Key;
typedef Person * Value;

typedef struct _slot
{
	Key key;
	Value val;
}Slot;


#endif // !__SLOT2_H__
