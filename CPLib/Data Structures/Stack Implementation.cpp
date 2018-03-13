#include <iostream>
using namespace std;

// Implementing stack using linked list

struct node{
	int data;
	node *next;
};

class stack
{
	private:
		node *top;	
	public:
		stack();
		void push(int item);
		void pop();
		void print();
		~stack();
};

int main()
{
	stack s1;
	int i, n, item, choice;
	cout << "Enter the number of items you want to start your stack with: ";
	cin >> n;
	for(i=0; i<n; i++)
	{
		cout << "Enter item [" << i+1 << "]: ";
		cin >> item;
		s1.push(item);
	}
	while(choice != 4)
	{
		cout << "Menu\n1. Push item\n2. Pop item\n3. Print the current stack\n4. Exit\n";
		cin >> choice;
		switch(choice)
		{
			case 1:
			{
				cout << "Enter the item to be pushed: ";
				cin >> item;
				s1.push(item);
				break;
			}
			case 2:
			{
				s1.pop();
				break;
			}
			case 3:
			{
				s1.print();
				break;
			}
			case 4:
			{
				break;
			}
			default:
			{
				cout << "Invalid option!!";
				break;
			}
		}
	}
	getchar();
	fflush(stdin);
	return 0;
}

stack::stack()
{
	top = NULL;	
}

void stack::push(int item)
{
	node *temp;
	temp = new node;
	temp->data = item;
	if(top == NULL)
	{
		temp->next = NULL;
		top = temp;
		return;
	}
	temp->next = top;
	top = temp;	
}

void stack::pop()
{
	node *temp;
	cout << "The popped item is: " << top->data << endl;
	temp = top;
	top = top->next;
	temp->next = NULL;
	delete temp;
}

void stack::print()
{
	node *temp;
	cout << "\nThe current stack is:" << endl;
	temp = top;
	while(temp!=NULL)
	{
		cout << temp->data << endl;
		temp = temp->next;
	}
}

stack::~stack()
{
	node *temp, *del;
	temp = top;
	while(temp!=NULL)
	{
		del = temp;
		temp = temp->next;
		delete del;
	}
}
