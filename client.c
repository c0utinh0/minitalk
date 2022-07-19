#include <sys/types.h>
#include <signal.h>

int	main(void)
{
	kill(21113, SIGINT);
	return(0);
}
