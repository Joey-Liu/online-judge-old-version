#include <iostream>
#include <stdio.h>
#include <string>
#include <string.h>

using namespace std;

struct Node
{
	char c;
	Node *next;
	Node(char ch = '\0', Node *p = NULL)
	{
		c = ch;
		next = p;
	}
};

void insert(Node *p, Node* node)
{
	node->next = p->next;
	p->next = node;
}

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);

	string text;
	while (cin >> text)
	{
		Node head;
		Node *cur = &head, *last = &head;

		for (int i = 0; i < text.size(); i++)
		{
			if ('[' == text[i])
				cur = &head;
			else if (']' == text[i])
			{
				cur = last;
			}
			else
			{
				Node *tn = new Node(text[i]);
				insert(cur, tn);
				if (cur == last)
					last = last->next;
				cur = tn;
			}
		}
		Node *p = head.next;
		while (p != NULL)
		{
			cout << p->c;
			p = p->next;
		}
		cout << endl;
	}
	return 0;
}
