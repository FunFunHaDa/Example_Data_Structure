#ifndef __SLOT_H__
#define __SLOT_H__

#include "14_Person.h"

typedef int Key;
typedef Person * Value;

enum SlotStatus { EMPTY, DELETED, INUSE };

typedef struct _slot
{
	Key key;
	Value val;
	enum SlotStatus status;
}Slot;

#endif // !__SLOT_H__
