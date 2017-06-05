#include <minix/driver.h>
#include <stdlib.h>

static void sef_local_startup(void);
static int sef_cb_init(int type, sef_init_info_t *info);
static void sef_cb_signal_handler(int signo);

int main(int argc, char* argv[])
{
	message mess;
	int ipc_status;

	sef_local_startup();

	while(TRUE)
	{
		driver_receive(ANY, &mess, &ipc_status);
	}

	return EXIT_SUCCESS;
}

static void sef_local_startup()
{
	sef_setcb_init_fresh(sef_cb_init);
	sef_setcb_signal_handler(sef_cb_signal_handler);

	sef_startup();
}

static int sef_cb_init(int type, sef_init_info_t *UNUSED(info))
{
	switch(type)
	{
		case SEF_INIT_FRESH:
			printf("Ola, mundo.\n");
			break;
	}

	return(OK);
}

static void sef_cb_signal_handler(int signo)
{
	if (signo == SIGTERM)
	{
		printf("Adeus, mundo.\n");
		exit(0);
	}
	return;
}
