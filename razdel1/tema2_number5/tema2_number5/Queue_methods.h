#include <iostream>
#include <clocale>
using namespace std;

const int queue_size = 4;
int first = 0, last = 0, queue_count = 0;

int isEmpty() {
	if (queue_count == 0)
		return 1;
	else if (queue_count == queue_size)
		return 2;
	else return 0;
}

void push(int* queue, int  value) {
	// проверка на заполненность очереди выполнена в main
	queue[last] = value;
	last++;
	if (last == queue_size) 
		last = 0;
	queue_count++;
	
}

int pop(int* queue) {
	// проверка на пустоту  очереди выполнена в main
	int value = queue[first];
	first++;
	if (first == queue_size) 
		first = 0;
	queue_count--;
	return value;
}

void show(int* queue) {
	if (isEmpty() != 1) {
		cout << endl;
		int current = first;
		do {
			cout << queue[current] << " ";
			current++;
			if (current == queue_size) current = 0;
		} while (current != last);
		
	}

}

