#include <iostream>
using namespace std;
class complex{
	private:
		float re, im;
	public:
		void set(float x, float y);	
		void display();
		complex operator+(complex c2);
		complex operator*(complex c2);
};
int main()
{
	complex c, c1, c2;
	float x,y;
	int choice;
	cout << "Enter the real and imaginary parts of the first complex number: ";
	cin >> x >> y;
	c1.set(x, y);
	cout << "Enter the real and imaginary parts of the second complex number: ";
	cin >> x >> y;
	c2.set(x, y);
	cout << "Menu\n1. Add two complex numbers\n2. Multiply two complex numbers\n\n";
	cin >> choice;
	switch(choice)
	{
		case 1:
		{
			c = c1 + c2;
			cout << "The sum is: ";		c.display();
			break;
		}
		case 2:
		{
			c = c1 * c2;
			cout << "The product is: ";		c.display();
			break;
		}
		default:
			cout << "Invalid Option!!" << endl;
			break;
	}	
	return 0;
}
void complex::set(float x, float y)
{
	re = x;
	im = y;
}
void complex::display()
{
	cout << re << " + i" << im << endl;
}
complex complex::operator+(complex c2)
{
	complex c;
	c.re = re + c2.re;
	c.im = im + c2.im;
	return c;
}
complex complex::operator*(complex c2)
{
	complex c;
	c.re = (re * c2.re) - (im * c2.im);
	c.im = (im * c2.re) + (c2.im * re);
	return c;
}
