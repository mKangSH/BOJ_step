#include <iostream>
#include <algorithm>
using namespace std;

int memory[21][21][21] = { 0 };

int dp(int a, int b, int c)
{
	if (a <= 0 || b <= 0 || c <= 0)
		return 1;

	else if (a > 20 || b > 20 || c > 20)
		return dp(20, 20, 20);

	else if (memory[a][b][c] != 0)
		return memory[a][b][c];

	else if (a < b && b < c)
		return memory[a][b][c] = (dp(a, b, c - 1) + dp(a, b - 1, c - 1) - dp(a, b - 1, c));

	else
		return memory[a][b][c] = (dp(a - 1, b, c) + dp(a - 1, b - 1, c) + dp(a - 1, b, c - 1) - dp(a - 1, b - 1, c - 1));

	return memory[a][b][c];
}

int main()
{
	int a, b, c;

	while (1)
	{
		cin >> a >> b >> c;

		if (a == -1 && b == -1 && c == -1)
			break;

		cout << "w(" << a << ", " << b << ", " << c << ") = " << dp(a, b, c) << endl;
	}

	return 0;
}