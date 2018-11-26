#ifndef __PERSON_H__
#define __PERSON_H__

#define STR_LEN 50

typedef struct _person
{
	int ssn;
	char name[STR_LEN];
	char addr[STR_LEN];
}Person;

int GetSSN(Person * p);
void ShwoPerInfo(Person * p);
Person * MakePersonData(int ssn, char * name, char * addr);

#endif // !__PERSON_H__