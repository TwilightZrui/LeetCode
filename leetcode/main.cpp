#include<vector>
#include<iostream>
#include<stdio.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;

class replaceSpace {
public:
	void replace(char* str, int length)
	{
		//0.judge 
		if (str == NULL || length < 1)
			return;
		int inl = 0,  spaceCount = 0, outl = 0;
		//1.calc length of str input and ou,output
		while (str[inl] != '\0') //Good Good study
		{
			if (str[inl] == ' ')
				spaceCount++;
			inl++;
		}
		outl = inl + spaceCount * 2;
		if (outl > length)	return;

		cout << "inl = " << inl << endl;
		cout << "oul = " << outl << endl;
		cout << "spaceCount = " << spaceCount << endl;
		cout << "now inl in str: " << str[inl] << endl;

		//2.replace
		while (outl != inl) 
		{
			if (str[inl] == ' ')
			{
				str[outl--] = '*';
				str[outl--] = '*';
				str[outl--] = '*';
			}
			else
			{
				str[outl--] = str[inl];
			}
			inl--;
		}

	}
};
int main()
{
	const int length = 4000;
	char Str[length] = "Good Good study";	
	replaceSpace s1;
	s1.replace(Str, length);
	cout << "after replace:" << Str << endl;
	return 0;
}


