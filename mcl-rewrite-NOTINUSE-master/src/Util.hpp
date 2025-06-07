#ifndef UTIL_HPP
#define UTIL_HPP

#include <string>

#define i(v) static_cast<int>(v)

namespace caelus
{
	using std::string;

	long double now();

	double min(double a, double b);
	double max(double a, double b);

	string toString(int value);
	int parseInt(string s);

	void print(string s);
}

#endif