#include <iostream>
#include <math.h>
using namespace std;
struct fraction{
	int num, den;
};
int gcd(int x, int y);
fraction create(int x, int y);
fraction normalise(fraction f);
fraction operator+(fraction f1, fraction f2);
fraction operator-(fraction f1, fraction f2);
fraction operator*(fraction f1, fraction f2);
void display(fraction f);
int main()
{
	fraction f1, f2;
	int x, y, choice;
	cout << "Which operation do you want to perform:\n1. Fraction Addition\n2. Fraction Substraction\n3. Fraction Multiplication\n";
	cin >> choice;
	cout << "Enter the numerator and denominator the 1st fraction seperated by a space: ";
	cin >> x >> y;
	f1 = create(x, y);
	cout << "Enter the numerator and denominator the 2nd fraction seperated by a space: ";
	cin >> x >> y;
	f2 = create(x, y);
	switch(choice)
	{
		case 1:
		{
			cout << "The sum is : ";	display(f1 + f2);
			break;
		}
		case 2:
		{
			cout << "The difference is : ";	display(f1 - f2);
			break;
		}
		case 3:
		{
			cout << "The product is : ";	display(f1 * f2);
			break;
		}
	}
	return 0;
}
fraction create(int x, int y)
{
	fraction f;
	f.num = abs(x);
	f.den = abs(y);
	if(x/y < 0)
		f.num *= -1;
	return f;
}
int gcd(int x, int y)
{
	int t;
	while(y % x != 0)
	{
		t = x;
		x = y%x;
		y = t;
	}
	return x;
}
fraction normalise(fraction f)
{
	int n ;
	if(f.num > f.den)
		n = gcd(f.den, abs(f.num));
	else
		n = gcd(f.num, abs(f.den));
	f.num /= n;
	f.den /= n;	
	return f;
}
fraction operator+(fraction f1, fraction f2)
{
	fraction f;
	int x, y;
	x = (f1.num * f2.den) + (f2.num * f1.den);
	y = (f1.den * f2.den);
	f = create(x, y);
	return normalise(f);
}
fraction operator-(fraction f1, fraction f2)
{
	fraction f;
	int x, y;
	x = (f1.num * f2.den) - (f2.num * f1.den);
	y = (f1.den * f2.den);
	f = create(x,y);
	return normalise(f);
}
fraction operator*(fraction f1, fraction f2)
{
	fraction f;
	int x, y;
	x = (f1.num * f2.num);
	y = (f1.den * f2.den);
	f = create(x, y);
	return normalise(f);
}
void display(fraction f)
{
	if(f.num == f.den)
		cout << "1";
	else
		cout << f.num << "/" << f.den;
}
