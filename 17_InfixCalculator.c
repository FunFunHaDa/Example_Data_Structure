#include<string.h>
#include<stdlib.h>
#include "17_InfixToPostfix.h"
#include "17_PostCalculator.h"

int EvalInfixExp(char exp[])
{
	int len = strlen(exp);
	int ret;
	char * expcpy = (char*)malloc(len + 1);
	strcpy(expcpy, exp);

	ConvToRPNExp(expcpy);
	ret = EvalPRNExp(expcpy);
	free(expcpy);
	return ret;
}
