#include <iostream>
#include "queue.h"

using std::cout;

int main()
{
	queue q1;
	data* persons[] = {
		new data("Franzi"),
		new data("Susi"),
		new data("Heinzi"),
		new data("Fritzi")
	};
	int n_persons = sizeof(persons) / sizeof(*persons);

	q1.enqueue(persons[0]);
	q1.enqueue(persons[1]);
	q1.enqueue(persons[2]);
	q1.enqueue(persons[3]);

	cout << "q1: " << q1 << std::endl;

	data* d = q1.dequeue();
	cout << "q1.dequeue -> " << *d << std::endl;	
	
	cout << "q1: " << q1 << std::endl;
	
	cout << "---------- copy constructor ----------" << std::endl;
	queue q2 = q1;
	cout << "q1: " << q1 << std::endl;
	cout << "q2: " << q2 << std::endl;
	

	for(int i = 0; i < n_persons; i++)
	{
		delete(persons[i]);
	}
	
	return 0;
}
