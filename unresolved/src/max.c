#include <stdio.h>
#include "logDebug.h"

int max(int a, int b) {
	logDebug('m');
	if (a>b) return a;
		else return b;
}
