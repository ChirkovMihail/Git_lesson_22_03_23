#pragma once
#include "Head.h"

vector <int> Mark_char(2 * const_length_code);

void Clear_Mark_char()
{
	for (int i = 0; i < Mark_char.size(); ++i)
		Mark_char[i] = 0;
}

string change_str(string& s)
{
	if (s.size() > Mark_char.size())
		return s;

	for (int i = 0; i < s.size(); ++i) {
		if (s[i] == '\n' || s[i] == ' ' || s[i] == '\t' || s[i] == '\r')
			Mark_char[i] = 1;
		else if (s[i] == '#')
			while (i < s.size() && s[i] != '\n')
			{
				Mark_char[i] = 1;
				i++;
			}
		else if (s[i] == '/') {
			if (s[i + 1] == '/')
				while (i < s.size() && s[i] != '\n')
				{
					Mark_char[i] = 1;
					i++;
				}
			if (s[i + 1] == '*')
				while (i < s.size() && s[i] != '*' && s[i + 1] != '/')
				{
					Mark_char[i] = 1;
					Mark_char[i + 1] = 1;
					i++;
				}
		}		
	}

	string result_str = "";
	for (int i = 0; i < s.size(); ++i) 
		if (Mark_char[i] == 0) 
			result_str += s[i];

	return result_str;
}