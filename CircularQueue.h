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
void init_queue() {		// 큐 초기화 함수
	front = rear = 0;
} 
int is_empty() {		// 큐 공백상태 검사
	return front == rear;
}
int is_full() {			// 큐 포화상태 검사
	return front == (rear + 1) % MAX_SIZE;
}
void enqueue(Element e) {	// 원형큐 삽입 연산
	if (is_full()) {			// 포화상태 검사
		error(2); 
	}	
	rear = (rear + 1) % MAX_SIZE;	// 원형큐의 한바퀴 도는거 계산
	data[rear] = e;
}
Element dequeue() {			// 원형큐 삭제 연산
	if (is_empty()) {		// 공백 상태 검사
		error(1); 	
	}
	front = (front + 1) % MAX_SIZE;
	return data[front];
}
Element peek() {			// 원형큐 탐색? 연산
	if (is_empty()) {		// 공백 상태 검사
		error(1);
	}
	return data[(front+1) % MAX_SIZE];
}
// 덱으로 리사이클

// 전단 삽입 삭제, 탐색
void add_front(Element e) {	// 앞에다 추가하는거는 큐에 없음
	if (is_full()) {
		error(2);
	}
	data[front] = e;
	front = (front - 1 + MAX_SIZE) % MAX_SIZE;
}
Element delete_front() {	// 앞에서 꺼내는거는 dequeue랑 같음
	return dequeue();
}
Element get_front() {		// 앞에서 보는거는 peek랑 같음
	return peek();
}
// 후단 삽입 삭제 탐색
void add_rear(Element e) {	// 덱 후단 삽입은 큐 삽입 연산이랑 같음
	enqueue(e);
}
Element delete_rear() {		// 후단 삭제는 없으므로 추가
	if (is_empty()) {		// 공백 상태 검사
		error(1);
	}
	int prev = rear;	// 데이터의 위치를 임시로 저장
	rear = (rear - 1 + MAX_SIZE) % MAX_SIZE;
	return data[prev];
}
Element get_rear() {			// 원형큐 탐색? 연산
	if (is_empty()) {		// 공백 상태 검사
		error(1);
	}
	return data[rear];
}