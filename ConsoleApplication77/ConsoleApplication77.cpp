#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <Windows.h>
#include <conio.h>
#include <iomanip>
using namespace std;
class String
{
private:
	char* str;
public:
	String();
	String(const char* _str);
	String& operator =(const String& obj);
	String(const String& obj);
	String operator +(const String& obj);
	void Print();
	~String();
};
int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	String str("Hi, please enter your strings below");
	String str2("String1 , String 2");
	str.Print();
	String finish = str + str2;
	finish.Print();
	cout << '\n';
	char parameter[80];
	cout << "Enter String: ";
	cin.getline(parameter, 80);
	str = parameter;
	cout << "Enter string 2: ";
	cin.getline(parameter, 80);
	str2 = parameter;
	cout << '\n';
	finish = str + str2;
	finish.Print();
}
String::String()
{
	str = nullptr;
}
String::String(const char* _str)
{
	int length = strlen(_str);
	str = new char[length + 1];
	strcpy(str, _str);
}
String& String::operator=(const String& obj)
{
	if (str != nullptr)
	{
		delete[]str;
	}
	int length = strlen(obj.str);
	str = new char[length + 1];
	strcpy(str, obj.str);
	return *this;
}
String::String(const String& obj)
{
	int length = strlen(obj.str);
	str = new char[length + 1];
	strcpy(str, obj.str);
}
String String::operator+(const String& obj)
{
	String newStr;
	int length = strlen(str);
	int nextL = strlen(obj.str);
	newStr.str = new char[length + nextL + 1];
	int i = 0;
	for (; i < length; i++)
	{
		newStr.str[i] = str[i];
	}
	for (size_t j = 0; j < nextL; j++, i++)
	{
		newStr.str[i] = obj.str[j];
	}
	newStr.str[length + nextL] = '\0';
	return newStr;
}
void String::Print()
{
	{
		cout << str << endl;
	}
}
String::~String()
{
	delete[]str;
}