#include <iostream>
#include <string>
#include <stack>

#ifdef _WIN32
#include <windows.h>
#endif

using namespace std;

string DeleteBrackets(string s)
{
	stack<int> ps;
	const char* txt;
	for (int i = 0; i < s.size(); i++) {
		txt = s.c_str();
		if (txt[i] == '(')ps.push(i);
		if (txt[i] == ')' && ps.size()) {
			int pos1 = ps.top();
			s.erase(pos1, i - pos1 + 1);
			i = -1;
		}
	}
	return s;
}

int main()
{
#ifdef _WIN32
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
#endif

	string s;
	getline(cin, s);
	string No_brackers = DeleteBrackets(s);
	cout << "\n" << No_brackers;

#ifdef _WIN32
	cout << "\n\n"; system("pause");
#endif

	return 0;
}

