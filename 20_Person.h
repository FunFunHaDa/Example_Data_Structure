#ifndef __PERSON_H_
#define __PERSON_H_

#define STR_LEN 50

typedef struct _preson
{
	int ssn;
	char name[STR_LEN];
	char addr[STR_LEN];
}Person;

int GetSSN(Person * p);
void ShowPerInfo(Person * p);
Person * MakePersonData(int ssn, char * name, char * addr);

#endif // !__PERSON_H_
