#include <iostream>

using namespace std;

bool isNumeric(char* string);
void is_numbers(char** str);
bool is_eorE(char** str);

int main()
{
	char* str = "123.45e+6";
	bool result = isNumeric(str);
	cout << "result:"<<result << endl;
	return 0;
}
bool isNumeric(char* string)
{
	bool result = false;
	if (string == NULL)
		return result;
	if (*string == '+' || *string == '-')
		string++;
	if (*string == '\0')//仅有符号位
		return result;
	is_numbers(&string);

	result = true;//纯整数的情况

	if (*string != '\0') {
		if (*string == '.')//先点后e
		{
			string++;
			is_numbers(&string);
			if (*string == 'e' || *string == 'E')
			{
				result = is_eorE(&string);
			}
			else if (*string == '\0')//仅此一种，如3.1415
				result = true;
			else
				result = false;
		}
		else if (*string == 'e' || *string == 'E')
		{
			result = is_eorE(&string);
		}
		else
			result = false;
	}
	//        else 				
	//            result=true;
	return result;
}
void is_numbers(char** str)
{
	while (**str != '\0' && **str >= '0' && **str <= '9')
		++(*str);
}
bool is_eorE(char** str)
{
	if (**str != 'e' && **str != 'E')
		return false;
	(*str)++;
	if (**str == '+' || **str == '-')
		(*str)++;
	if (**str == '\0')
		return false;
	is_numbers(str);
	if (**str == '\0')
		return true;
	return false;
}