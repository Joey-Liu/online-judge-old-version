#include <iostream>
#include <stdio.h>
#include <string>
#include <string.h>
#include <algorithm>
#include <map>

using namespace std;

map<string, string> ip_server;
string ip, server, cmd;
int N, M;

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);

	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		cin >> server >> ip;
		ip_server[ip] = server;
	}//for

	for (int i = 0; i < M; i++)
	{
		cin >> cmd >> ip;
		ip.erase(ip.size() - 1, 1);
		cout << cmd << " " << ip << "; #" << ip_server[ip] << endl;
	}//for int i
	return 0;
}