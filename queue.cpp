#include "CircularQueue.h"
#include <iostream>

// 덱의 요소를 출력하는 함수
void print_deque() {
	printf("front=%d, rear=%d --> ", front, rear);   
	int size = (rear - front + MAX_SIZE) % MAX_SIZE; 
	for (int i = front + 1; i <= front + size; i++) {
		printf("%2d ", data[i % MAX_SIZE]);
	}
	printf("\n");
}

int main()
{
	init_queue(); // 큐 초기화
	// 홀수면 전단에 삽입, 짝수면 후단에 삽입
	for (int i = 1; i < 8; i++) {
		if (1 % 2) {
			add_front(i);
		}
		else {
			add_rear(i);
		}
	}
	printf("원형 덱 홀수-짝수 ");
	print_deque();
	printf("\tdelete_front() -->%d\n", delete_front());
	printf("\tdelete_rear () -->%d\n", delete_rear());
	printf("\tdelete_front() -->%d\n", delete_front());
	printf("원형 덱 삭제=홀짝홀 ");
	print_deque();
}
