#include "CLL_Class.h"

CLL::CLL()
{
	tail = NULL;
}
bool CLL::empty()
{
	return tail == 0;
}
int CLL::size()
{
	if (tail == 0)
		return -1;
	node* t = tail->next;
	int c = 1;
	for (; t != tail; t = t->next, ++c);
	return c;
}
void CLL::add_begin(int el)
{
	if (tail == 0)
		tail = new node(el);
	else
	{
		node* t = tail->next;
		t = tail->next = new node(el, t);
	}
}
void CLL::add_end(int el)
{
	if (tail == 0)
		tail->next = tail = new node(el);
	else
	{
		tail = tail->next = new node(el, tail->next);
	}
}
bool CLL::add_pos(int el, int pos)
{
	if (pos<1 || pos>size())
		return false;
	else
	{
		if (pos == size())
			add_end(el);
		else
		{
			node* t = tail->next;
			for (int i = 0; i < pos - 1; ++i, t = t->next);
			t->next = new node(el, t->next);
		}
		return true;
	}
}
bool CLL::del_begin()
{
	if (tail == 0)
		return false;
	else
	{
		if (size() == 1)
		{
			delete tail;
			tail = 0;
		}
		else
		{
			node* t = tail->next;
			tail->next = t->next;
			delete t;
		}
		return true;
	}
}
bool CLL::del_end()
{
	if (size() == 0)
		return false;
	else
	{
		if (size() == 1)
		{
			delete tail;
			tail = 0;
		}
		else
		{
			node* t1 = tail->next, * t2 = tail->next;
			for (; t2->next != tail; t2 = t2->next);
			delete tail;
			tail = t2;
			t2->next = t1;
		}
		return true;
	}
}
void CLL::print()
{
	if (tail != 0)
	{
		node* t = tail->next;
		for (; t != tail; t = t->next)
			cout << t->data << " ";
		cout << t->data << endl;
	}
	/*if (tail != 0)
	{
		node* t = tail->next;
		do
		{
			cout << t->data<<" ";
			t = t->next;
		} while (t != tail->next);
		cout << endl;
	}*/
}
CLL::~CLL()
{
	while (!empty())
		del_begin();
	cout << "deleted\n";
}
void CLL::operator=(CLL& o)
{
	while (!empty())
		del_end();
	if (!o.empty())
	{
		node* t1 = o.tail->next;
		tail->next = tail = new node(t1->data, 0);
		while (t1->next != o.tail->next)
		{
			t1 = t1->next;
			tail = tail->next = new node(t1->data, tail->next);
		}
	}
	else
		tail = 0;
}
CLL::CLL(CLL& o)
{
	if (!o.empty())
	{
		node* t = o.tail->next;
		tail->next = tail = new node(t->data);
		while (t->next != o.tail->next)
		{
			t = t->next;
			tail = tail->next = new node(t->data, tail->next);
		}
	}
	else
		tail = 0;
}