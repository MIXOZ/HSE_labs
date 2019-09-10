#include <stdio.h>
#include "doComputation.h"
#include "logDebug.h"
#include "max.h"


int main() {
	int a = doComputation(5, 7.0);
	int b = 5;
	printf ("%d",max(a, b));
	logDebug('!');
	return 0;
}
