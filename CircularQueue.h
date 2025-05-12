#include <iostream>
#include <stdlib.h>
#define MAX_SIZE 8
typedef int Element;
Element data[MAX_SIZE];
int front, rear;

void error(int n) {
	if (n == 1) printf("Underflow Error!");
	if (n == 2) printf("Overflow Error!");
	exit(1);
}
void init_queue() {		// ť �ʱ�ȭ �Լ�
	front = rear = 0;
} 
int is_empty() {		// ť ������� �˻�
	return front == rear;
}
int is_full() {			// ť ��ȭ���� �˻�
	return front == (rear + 1) % MAX_SIZE;
}
void enqueue(Element e) {	// ����ť ���� ����
	if (is_full()) {			// ��ȭ���� �˻�
		error(2); 
	}	
	rear = (rear + 1) % MAX_SIZE;	// ����ť�� �ѹ��� ���°� ���
	data[rear] = e;
}
Element dequeue() {			// ����ť ���� ����
	if (is_empty()) {		// ���� ���� �˻�
		error(1); 	
	}
	front = (front + 1) % MAX_SIZE;
	return data[front];
}
Element peek() {			// ����ť Ž��? ����
	if (is_empty()) {		// ���� ���� �˻�
		error(1);
	}
	return data[(front+1) % MAX_SIZE];
}
// ������ ������Ŭ

// ���� ���� ����, Ž��
void add_front(Element e) {	// �տ��� �߰��ϴ°Ŵ� ť�� ����
	if (is_full()) {
		error(2);
	}
	data[front] = e;
	front = (front - 1 + MAX_SIZE) % MAX_SIZE;
}
Element delete_front() {	// �տ��� �����°Ŵ� dequeue�� ����
	return dequeue();
}
Element get_front() {		// �տ��� ���°Ŵ� peek�� ����
	return peek();
}
// �Ĵ� ���� ���� Ž��
void add_rear(Element e) {	// �� �Ĵ� ������ ť ���� �����̶� ����
	enqueue(e);
}
Element delete_rear() {		// �Ĵ� ������ �����Ƿ� �߰�
	if (is_empty()) {		// ���� ���� �˻�
		error(1);
	}
	int prev = rear;	// �������� ��ġ�� �ӽ÷� ����
	rear = (rear - 1 + MAX_SIZE) % MAX_SIZE;
	return data[prev];
}
Element get_rear() {			// ����ť Ž��? ����
	if (is_empty()) {		// ���� ���� �˻�
		error(1);
	}
	return data[rear];
}