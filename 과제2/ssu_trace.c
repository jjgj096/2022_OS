#include "types.h"
#include "user.h"
#include "stat.h"
#include "fcntl.h"

int main(int argc, char *argv[])
{
	int mask;
	mask = atoi(argv[1]);
	trace(mask);
	exec(argv[2], argv+2);

	return 0;
}
