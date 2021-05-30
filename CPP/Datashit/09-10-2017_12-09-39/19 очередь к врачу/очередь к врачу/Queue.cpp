#include "stdafx.h"
#include "Queue.h"
void Queue::push(string h)
{
	queue[last_queue] = h;
	cout << queue[last_queue++] << " came to the reception" << endl;
	return;
}
string Queue::show()
{
	if (!empty())
	return queue[first_queue++];
	else { cout << "Nobody"; return 0; }
}
void Queue::pop()
{
	if (!empty())
		cout << queue[first_queue++] << " went to the doctor's office" << endl;
	else
		cout << "Doctor haven't patient - he has a rest. ";
}
bool Queue::empty()
{
	if (last_queue == first_queue) return true;
	return false;
}
string Queue::watch()
{
	return queue[first_queue];
}