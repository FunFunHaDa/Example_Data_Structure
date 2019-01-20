#include<stdio.h>

typedef struct _empInfo
{
	int empNum;
	int age;
}EmpInfo;

int GetHashValue(int empNum)
{
	return empNum % 100;
}

int main(void)
{
	EmpInfo empInfoArr[100];
	EmpInfo emp1 = { 20120000, 11 };
	EmpInfo emp2 = { 20121111, 33 };
	EmpInfo emp3 = { 20122222, 44 };

	EmpInfo r1, r2, r3;
	empInfoArr[GetHashValue(emp1.empNum)] = emp1;
	empInfoArr[GetHashValue(emp2.empNum)] = emp2;
	empInfoArr[GetHashValue(emp3.empNum)] = emp3;

	r1 = empInfoArr[GetHashValue(20120000)];
	r2 = empInfoArr[GetHashValue(20121111)];
	r3 = empInfoArr[GetHashValue(20122222)];

	printf("사번 %d, 나이 %d \n", r1.empNum, r1.age);
	printf("사번 %d, 나이 %d \n", r2.empNum, r2.age);
	printf("사번 %d, 나이 %d \n", r3.empNum, r3.age);

	return 0;


}