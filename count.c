#include<limits.h>

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

char chars[4] = { 0 };

void main() {
	int counter = 1;

	// *led = 1;

	// for (;;) {
	// 	*led = counter;

	// 	*uart_rx;

	// 	counter <<= 1;
	// }
	// for (int j = ~0xf; j != -1; j >>= 1) {
	// 	*led = j;
	// 	*uart_tx = *uart_rx;
	// }

	// *led = 2;

	// *led = 2 >> 1;

	for (;;) {
		*led = counter;
		chars[counter++ % 4] = *uart_rx;

		for (int i = 0; i < 4; ++i) {
			if (chars[i % 4] == 'P') {
				*uart_tx = 'P';
			}
		}
	}

	// *led = 2;
	// for (;;) {
	// 	*uart_tx = *uart_rx & ~0x20;
	// 	*led = ++counter;
	// }

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
