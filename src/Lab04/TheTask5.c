int main()
{
	float y;
	float x = -3.0;
	if (x <= -1.0) {
		y = -x - 1;
	}
	else if (x >= -1 && x <= 0) {
		y = x + 1;
	}
	else if (x >= 0 && x <= 1) {
		y = -x + 1;
	}
	else if (x > 1) {
		y = x + 1;
	}
	return 0;
}