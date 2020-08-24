#include "../include/strutils.h"
#include <algorithm>
#include <iostream>
#include <string>
#include <sstream>

std::string to_upper(std::string str)
{
	std::transform(str.begin(), str.end(), str.begin(), ::toupper);
	return str;
}

std::string to_lower(std::string str)
{
	std::transform(str.begin(), str.end(), str.begin(), ::tolower);
	return str;
}

std::string reverse(std::string str)
{
	std::reverse(str.begin(), str.end());
	return str;
}

std::string trim_left(std::string str, std::string znakovi)
{
	std::string out(str);
	out.erase(0, out.find_first_not_of(znakovi));
	return out;
}

std::string trim_right(std::string str, std::string znakovi)
{
	std::string out(str);
	out.erase(out.find_last_not_of(znakovi) + 1);
	return out;
}

std::string trim(std::string str, std::string znakovi)
{
	std::string out(str);
	return trim_left(trim_right(out, znakovi), znakovi);
}

std::string remove(std::string str, char c)
{
	std::string out(str);
	out.erase(remove(out.begin(),out.end(),c),out.end());
	return out;
}

std::vector<std::string> tokenize(std::string const & str, char delimiter)
{
	std::stringstream ss(str);
	std::vector<std::string> out;
	std::string tmp;
	while (std::getline(ss, tmp, delimiter))
	{
		 out.push_back(tmp);
	}
	return out;
}
