#include <stdio.h>
#include "fwdstdout.h"

int main() {
	fwdstdout("./somefile");
	fprintf(stdout, "Something\n");
}
