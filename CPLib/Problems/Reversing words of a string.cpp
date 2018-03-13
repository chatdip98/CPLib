#include <iostream>
#include <string>
using namespace std;

int main()
{
	char string[100], temp[100][50];
	int i, j = 0, k = 0, count = 0;
	
	cout << "Enter a sentence ending it by a fullstop: ";
	gets(string);
	
	for(i=0; string[i] != '.'; i++)
	{
		if(string[i] == ' ')
		{
			temp[j][k] = '\0';
			j++;
			count++;
			k = 0;
		}
		else
		{
			temp[j][k] = string[i];
			k++;
		}
	}
	cout << "Your string after reversing the words is:\n";
	for(j=count; j >= 0; j--)
	{
		cout << temp[j];
		if(j != 0)
		{
			cout << " ";
		}
		else
		{
			cout << ".";
		}
	}
	
	fflush(stdin);
	getchar();
	return 0;
}
