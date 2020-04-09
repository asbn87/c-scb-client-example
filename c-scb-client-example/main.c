#include <stdio.h>
#include "client.h"

int main() {

	// Connecting to the open api at the Swedish Central Agency for statistics
	unsigned short* host = L"api.scb.se";

	// Table with names of newborns with at least 10 namings since 1998
	unsigned short* path = L"/OV0104/v1/doris/sv/ssd/START/BE/BE0001/BE0001D/BE0001T04Ar";

	unsigned short* cmd = L"GET";

	winhttp_init();
	winhttp_connect(host);
	winhttp_open_request(cmd, path);
	winhttp_send_request();
	winhttp_end_request();
	winhttp_read_data();

	winhttp_print_data();

	report_error();
	winhttp_close();

	getchar();

	return 0;
}