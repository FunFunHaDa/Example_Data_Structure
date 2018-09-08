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
	EmpInfo empInforArr[100];

	EmpInfo emp1 = { 20120003, 42 };
	EmpInfo emp2 = { 20130012, 33 };
	EmpInfo emp3 = { 20170049, 27 };

	EmpInfo r1, r2, r3;

	empInforArr[GetHashValue(emp1.empNum)] = emp1;
	empInforArr[GetHashValue(emp2.empNum)] = emp2;
	empInforArr[GetHashValue(emp3.empNum)] = emp3;

	r1 = empInforArr[GetHashValue(20120003)];
	r2 = empInforArr[GetHashValue(20130012)];
	r3 = empInforArr[GetHashValue(20170049)];

	printf("사번 %d, 나이 %d \n", r1.empNum, r1.age);
	printf("사번 %d, 나이 %d \n", r2.empNum, r2.age);
	printf("사번 %d, 나이 %d \n", r3.empNum, r3.age);
}