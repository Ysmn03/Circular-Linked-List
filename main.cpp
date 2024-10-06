#include"CLL_Class.h"
#include<iostream>
using namespace std;
/*void main()
{
	CLL l;
	cout << l.size() << endl;
	l.add_end(1);
	l.add_end(6);
	l.add_end(2);
	l.add_end(10);
	l.print();
	l.add_pos(66,3);
	l.del_end();
	l.print();
	cout << l.size()<<endl;
}*/
void main()
{
	CLL l1, l2;
	l1.add_end(1);
	l1.add_end(2);
	l2.add_end(5);
	l2.add_end(6);
	l2.add_end(7);
	l1.print();
	l2.print();
	l1 = l2;
	l2.add_end(100);
	l1.print();
	l2.print();
}