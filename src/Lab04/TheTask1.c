#define pi 3.14
int main() {

	float result;
	char COMMAND = 'v';
	float r = 3.0;
	if (COMMAND == 'I') {
		result = 2 * pi * r;
	}
	else if (COMMAND == 's') {
		result = pi * r * r;
	}
	else if (COMMAND == 'v') {
		result = (4 * pi * r * r * r) / 3;
	}
	return 0;
}