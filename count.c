static volatile int * led = (volatile int *) 1024;
static volatile int * uart_tx = (volatile int *) 1028;
static volatile int * uart_rx = (volatile int *) 1032;

extern void usleep(void);

int mem[1];

static int fib(int n) {
	if (n == 0) return 0;
	if (n == 1) return 1;

	return fib(n - 1) + fib(n - 2);
}

void main() {
	int counter = 0;

	int characters[7];
	int i;

	*led = 2;
	for (;;) {
		*uart_tx = *uart_rx & ~0x20;
		*led = ++counter;
	}

	// *led = 2;
	// for (;;) {
	// 	i = 0;
	// 	for (;;) {
	// 		*uart_tx = 'I';
	// 		*uart_tx = 'N';
	// 		int read = *uart_rx;

	// 		if (i < 8) {
	// 			characters[i++] = read;
	// 		}

	// 		*led = i;

	// 		if (read == '\r') break;
	// 	}

	// 	*uart_tx = '\n';
	// 	usleep();
	// 	for (int j = 0; j < i; ++j) {
	// 		*uart_tx = characters[j];
	// 		usleep();
	// 	}
	// }
}
