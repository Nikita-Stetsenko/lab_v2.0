int main()
{
	float n = 123.327;
	float n1 = (int)n;
	int n2 = n * 1000;
	n2 = n2 % 1000;
	float comparios;
	if (n1 == 0) {
		comparios = 0;
	}
	else {
		comparios = n2 / n1;
		comparios = comparios * 100;
		comparios = (int)comparios;
		comparios = (float)comparios;
		comparios = comparios / 100;

	}
	return 0;
}