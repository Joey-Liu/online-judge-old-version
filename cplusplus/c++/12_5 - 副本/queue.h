#ifndef QUEUE_H_
#define QUEUE_H_
class Customer
{
private:
	long arrive;
	int processtime;
public:
	Customer() { arrive=processtime=0;}
	void set(long when);
	long when() const {return arrive;}
	int ptime() const {return processtime;}
};


typedef Customer Item;


class Queue
{
private:
	struct Node {Item item;struct Node* next;};
	enum {Q_SIZE=10};
	Node* front;
	Node* rear;
	int items;					//队中元素数量
	const int qsize;			//最大上限，构造函数中使用初始化列表
	Queue(const Queue & q):qsize(0)  {}
	Queue & operator=(const Queue & q) {return *this;}		//以上两个函数在此类中应避免使用
public:
	Queue(int qs=Q_SIZE);
	~Queue();
	bool isempty() const;
	bool isfull() const;
	int queuecount() const;
	bool enqueue(const Item & item);
	bool dequeue(Item & item);
};
#endif
