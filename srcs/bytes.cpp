
#include "ft_gkrellm.hpp"

std::string bytes_format(long bytes)
{
	static const std::string s[] = {
		"bytes", "Kb", "Mb", "Gb", "Tb", "Eb"
	};

	long double b = bytes;

	int i = 0;

	for (i = 0; b >= 1024 && i < 6; i++)
		b /= 1024;

	std::stringstream ss;
	ss << std::setprecision((i == 0 ? 0 : 2)) << std::fixed << b << " " << s[i];

	return ss.str();

}