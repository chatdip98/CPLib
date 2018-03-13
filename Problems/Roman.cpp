#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

int i = 0;
void roman(int digit, char string[]);

int main()
{
	int n, digit;
	char string[100];
	
	cout << "Enter an integer between 1-100: ";
	cin >> n;
	
	if(n <= 0 || n > 100)
	{
		cout << "\nYou entered a number that does not lie within the specified range." << endl;
		exit (0);
	}
	if(n < 10)
	{
		roman(n, string);
	}
	if(n >= 10  && n < 20)
	{
		digit = n - 10;
		string[i] = 'X';
		i++;
		roman(digit, string);
	}
	if(n >= 20  && n < 30)
	{
		digit = n - 20;
		string[i] = 'X';
		string[i+1] = 'X';
		i = i + 2;
		roman(digit, string);
	}
	if(n >= 30 && n < 40)
	{
		digit = n - 30;
		string[i] = 'X';
		string[i+1] = 'X';
		string[i+2] = 'X';
		i = i + 3;
		roman(digit, string);
	}
	if(n >= 40 && n < 50)
	{
		digit = n - 40;
		string[i] = 'X';
		string[i+1] = 'L';
		i = i + 2;
		roman(digit, string);
	}
	if(n >= 50 && n < 60)
	{
		digit = n - 50;
		string[i] = 'L';
		i++;
		roman(digit, string);
	}
	if(n >= 60 && n < 70)
	{
		digit = n - 60;
		string[i] = 'L';
		string[i+1] = 'X';
		i = i + 2;
		roman(digit, string);
	}
	if(n >= 70 && n < 80)
	{
		digit = n - 70;
		string[i] = 'L';
		string[i+1] = 'X';
		string[i+2] = 'X';
		i = i + 3;
		roman(digit, string);
	}
	if(n >= 80 && n < 90)
	{
		digit = n - 80;
		string[i] = 'L';
		string[i+1] = 'X';
		string[i+2] = 'X';
		i = i + 3;
		roman(digit, string);
	}
	if(n >= 90 && n < 100)
	{
		digit = n - 90;
		string[i] = 'X';
		string[i+1] = 'C';
		i = i + 2;
		roman(digit, string);
	}
	if(n == 100)
	{
		string[0] = 'C';
	}
	
	cout << "\nThe number " << n << " in roman numerals is " << string << "." << endl;
	
	fflush(stdin);
	getchar();
	return 0;
}
void roman(int digit, char string[100])
{
	if(digit == 1)
		string[i] = 'I';
		string[i+1] = '\0';	
	if(digit == 2)
		string[i] = 'I';
		string[i+1] = 'I';
		string[i+2] = '\0';		
	if(digit == 3)
		string[i] = 'I';
		string[i+1] = 'I';
		string[i+2] = 'I';
		string[i+3] = '\0';	
	if(digit == 4)
		string[i] = 'I';
		string[i+1] = 'V';
		string[i+2] = '\0';	
	if(digit == 5)
		string[i] = 'V';
		string[i+1] = '\0';	
	if(digit == 6)
		string[i] = 'V';
		string[i+1] = 'I';
		string[i+2] = '\0';	
	if(digit == 7)
		string[i] = 'V';
		string[i+1] = 'I';
		string[i+2] = 'I';
		string[i+3] = '\0';	
	if(digit == 8)
		string[i] = 'V';
		string[i+1] = 'I';
		string[i+2] = 'I';
		string[i+3] = 'I';
		string[i+4] = '\0';	
	if(digit == 9)
		string[i] = 'I';
		string[i+1] = 'X';
		string[i+2] = '\0';	
	if(digit == 10)
		string[i] = 'X';
		string[i+1] = '\0';	
}
