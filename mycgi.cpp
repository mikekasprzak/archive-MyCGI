#include <fcgi_stdio.h>
#include <fcgiapp.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {
	int count = 0;
	
	while (FCGI_Accept() >= 0) {
		printf(
			"Content-type: text/html\r\n"
			"\r\n"
			"<title>FastCGI Hello! (C, fcgi_stdio library)</title>\n"
			"<h1>FastCGI Hello! (C, fcgi_stdio library)</h1>\n"
			"Query: <i>%s</i>\r\n"
			"Request number %d running on host <i>%s</i>\n",
			getenv("QUERY_STRING"), ++count, getenv("SERVER_HOSTNAME")
		);
	};

	return 0;
}
