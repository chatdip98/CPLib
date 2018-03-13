#include <iostream>
using namespace std;

// Implementing queue using linked list

struct node{
	int data;
	node *next;
};

class queue
{
	private:
		node *front, *tail;	
	public:
		queue();
		void enq(int item);
		void deq();
		void print();
		~queue();
};

int main()
{
	queue q1;
	int i, n, item, choice;
	cout << "Enter the number of items you want to start your queue with: ";
	cin >> n;
	for(i=0; i<n; i++)
	{
		cout << "Enter item [" << i+1 << "]: ";
		cin >> item;
		q1.enq(item);
	}
	while(choice != 4)
	{
		cout << "Menu\n1. Enqueue item\n2. Dequeue item\n3. Print the current queue\n4. Exit\n";
		cin >> choice;
		switch(choice)
		{
			case 1:
			{
				cout << "Enter the item to be enqueued: ";
				cin >> item;
				q1.enq(item);
				break;
			}
			case 2:
			{
				q1.deq();
				break;
			}
			case 3:
			{
				q1.print();
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

queue::queue()
{
	front = tail = NULL;	
}

void queue::enq(int item)
{
	node *temp;
	temp = new node;
	temp->data = item;
	if(tail == NULL)
	{
		front = tail = temp;
		return;
	}
	tail->next = temp;
	tail = temp;	
	tail->next = NULL;
}

void queue::deq()
{
	node *temp;
	cout << "The dequeued item is: " << front->data << endl;
	temp = front;
	front = front->next;
	temp->next = NULL;
	delete temp;
}

void queue::print()
{
	node *temp;
	cout << "\nThe current queue is:" << endl;
	temp = front;
	while(temp!=NULL)
	{
		cout << temp->data << endl;
		temp = temp->next;
	}
}

queue::~queue()
{
	node *temp, *del;
	temp = front;
	while(temp!=NULL)
	{
		del = temp;
		temp = temp->next;
		delete del;
	}
}
