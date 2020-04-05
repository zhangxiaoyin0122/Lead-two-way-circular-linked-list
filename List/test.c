#include <stdio.h>
#include <stdlib.h>

typedef int Type;
typedef struct Node {
	Type _data;
	struct Node* _next;
	struct node* _prev;
}Node;

typedef struct List {
	Node* _header;
}List;

void ListInit(List* lst) {
	//����һ��ͷ���,����ѭ���ṹ
	lst->_header = creatNode;
	lst->_header->_next = lst->_header;
	lst->_header->_prev = lst->_header;
}
//�����½ڵ�
Node* creatNode(Type data) {
	Node* node = (Node*)malloc(sizeof(Node));
	node->_prev = node->_next = NULL;
	node->_data = data;
	return node;
}
//β��
void ListPushBack(List* lst, Type data) {
	Node* node = creatNode(data);
	Node* last = lst->_header->_prev;
	lst->_header->_prev = node;
	node->_next = lst->_header;
	last->_next = node;
	node->_prev = last;

}
//βɾ
void ListPopBack(List* lst) {
	Node* last, *prev;
	if (lst->_header->_next = lst->_header) //�ж��Ƿ�Ϊ�ձ�
		return;
	 last = lst->_header->_prev;
	 prev = last->_prev;
	 free(last);
	 lst->_header->_prev = prev;
	 prev->_next = lst->_header;
	
}
//ͷ��
void ListPushFront(List* lst, Type data) {
	Node* node = creatNode(data);
	Node* front = lst->_header->_next;
	node->_next = front;
	front->_prev = node;
	lst->_header->_next = node;
	node->_prev = lst->_header;
}
//ͷɾ
void ListPopFront(List* lst) {
	Node* front, *next;
	if (lst->_header->_data = lst->_header)//�ж��Ƿ�Ϊ�ձ�
		return;
	front = lst->_header;
	next = front->_next;
	free(front);
	lst->_header->_next = next;
	next->_prev = lst->_header;
	
}
//����λ�õĲ�������
void ListInsert(Node* pos, Type data) {
	Node* prev = pos->_prev;
	Node* node = creatNnode(data);
	prev->_next = node;
	node->_prev = prev;
	node->_next = pos;
	pos->_prev = node;
}
//����λ�õ�ɾ��
void ListErase(Node* pos) {
	Node* prev, *next;
	if (pos->_next = pos)//�ж��Ƿ�Ϊ�ձ�
		return;
	prev = pos->_prev;
	next = pos->_next;
	free(pos);
	prev->_next = next;
	next->_prev = prev;
}

//��ӡ
void ListPrint(List* lst) {
	Node* cur = lst->_header->_next;
	while (cur != lst->_header) {
		printf("%d", cur->_data);
		cur = cur->_next;
	}
	printf("\n");
}
//����
void Listdesory(List* lst) {
	Node* cur = lst->_header->_next;
	while (cur != lst->_header) {
		Node* next = cur->_next;
		free(cur);
		cur = next;
	}
	free(lst->_header);
	lst->_header = NULL;//��ü���
}