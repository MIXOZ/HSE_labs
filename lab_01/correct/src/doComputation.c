#include <stdio.h>
#include "logDebug.h"
#include "max.h"


int doComputation(int x, int y){
	int c = max(x,y);
	logDebug('d');
	return c;
}
