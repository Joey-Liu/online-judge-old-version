#include<iostream>
#include<cstdlib>
#include"queue.h"

using std::cout;

void Customer::set(long when)
{
	arrive=when;
	processtime=rand()%3+1;
}


Queue::Queue(int qs):qsize(qs)
{
	front=rear=NULL;
	items=0;
}


Queue::~Queue()
{
	Node* p=front;
	while(front)
	{
		front=front->next;
		delete p;
		p=front;
	}
}


bool Queue::isempty() const
{
	if(0==items)
		return true;
	return false;
}


bool Queue::isfull() const
{
	if(qsize==items)
		return true;
	return false;
}


int Queue::queuecount() const
{
	return items;
}


bool Queue::enqueue(const Item & item)
{
	if(isfull())
		return false;
	Node* temp=new Node;
	//cout<<"now what?\n";
	temp->item=item;
	temp->next=NULL;
	//cout<<"I am confused..\n";
	items++;
	if(front==NULL)
	{
		//cout<<"I think there is a problem\n";
		front=temp;
	}
	else
		rear->next=temp;
	//cout<<"Isn't it?\n";
	rear=temp;
	//cout<<"here?\n";
	return true;
}


bool Queue::dequeue(Item & item)
{
	if(isempty())
		return false;
	Node* temp=front;
	item=front->item;
	front=front->next;
	delete temp;
	items--;
	if(isempty())
		rear=NULL;
	return true;
}


