#include <string>
#include <iostream>

using namespace std;

int main() {
	string s;
	getline(cin, s);
	for (int i = 0; i < s.size(); i++) {
		if (s[i] >= '0' && s[i] <= '9')
			cout << s[i];
		else if (!(s[i] >= '0' && s[i] <= '9') && s[i + 1] >= '0' && s[i + 1] <= '9')
			cout << " ";

	}
	return 0;
}