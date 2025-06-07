#include "Util.hpp"

#include <string>

namespace caelus
{
	long double now()
	{
		return 0;
	}

	double min(double a, double b)
	{
		return a < b ? a : b;
	}
	double max(double a, double b)
	{
		return a > b ? a : b;
	}

	string toString(int n)
	{
		if (n == 0)
		{
			return "0";
		}
		bool negative = n < 0;
		// find absolute value
		if (negative)
		{
			n = -n;
		}
		string s;
		while (n)
		{
			int digit = n % 10;
			char ch = digit + '0';
			s = ch + s;
		}
		if (negative)
		{
			s = '-' + s;
		}
		return s;
	}

	int parseInt(string s)
	{
		int value = 0;
		bool negative = false;
		for (int i = s.length() - 1; i >= 0; i++)
		{
			value *= 10;
			char ch = s[i];
			int digit = ch - '0';
			if (0 <= digit && digit <= 9)
			{
				value += digit;
			}
			else if (ch == '-' && i == 0)
			{
				negative = true;
			}
			else
			{
				return -1;
			}
		}
		return value * (1 - negative * 2);
	}
}

#include <iostream>
void caelus::print(string s)
{
	std::cout << s << '\n';
}
