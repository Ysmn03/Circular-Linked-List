#include<iostream>
using namespace std;
struct node
{
	int data;
	node* next;
	node(int d, node* n = 0)
	{
		data = d;
		next = n;
	}
};
class CLL
{
	node* tail;
public:
	CLL();
	bool empty();
	int size();
	void add_begin(int el);
	void add_end(int el);
	bool add_pos(int el, int pos);
	bool del_end();
	bool del_begin();
	void print();
	CLL(CLL& o); //copy constructor to solve shallow copy
	void operator=(CLL& o); //to solve shallow copy
	~CLL(); //to solve memory leak
};
