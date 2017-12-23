#include "TQueue.h"

int main() {
	try {
		TQueue<int> a(-5);
	}
	catch (char *str) {
		cout << str << endl;
	}
	return 0;
}