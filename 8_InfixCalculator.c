#include<string.h>
#include<stdlib.h>
#include "8_InfixToPostfix.h"
#include "8_PostCalculator.h"

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
