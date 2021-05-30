#pragma once
#include "string"
#include "iostream"
#include "fstream"
using namespace std;
class Queue
{
	int last_queue;
	int first_queue;
	string queue[100];
public:
	Queue()	{ last_queue = 0;	first_queue = 0; }
	void push(string);
	void pop();
	bool empty();
	string watch();
	string show();
};
