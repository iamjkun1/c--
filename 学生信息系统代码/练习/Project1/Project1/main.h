#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include <string.h>


struct student {
	char num[10];   ///ѧ��
	char name[5];   ///����
	char sex[4];   ///�Ա�
	int cla;     ///���
	float Chinese, Math, English;   ///���ģ� ��ѧ��Ӣ�

};

struct Node {
	//int data;
	struct student data;
	struct Node* next;
};


//��������
struct Node* createList() {

	struct Node* listHeadNode = (struct Node*)malloc(sizeof(struct Node));
	listHeadNode->next = NULL;
	return listHeadNode;
}

//������㣻
struct Node* createNode(struct student data) {
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
	newNode->data = data;
	newNode->next = NULL;
	return newNode;

}

//���룻
void insertNodeByHead(struct Node* listHeadNode, struct student data) {
	struct Node* newNode = createNode(data);
	newNode->next = listHeadNode->next;
	listHeadNode->next = newNode;
}


//ɾ����
void deleteNodeByAppoinName(struct Node* listHeadNode, const char* name) {

	struct Node* posFrontNode = listHeadNode;
	struct Node* posNode = listHeadNode->next;
	if (posNode == NULL) {
		printf("����Ϊ�գ��޷�ɾ����\n");
		return;
	}
	else {

		while (strcmp(posNode->data.name, name)) {
			posFrontNode = posNode;
			posNode = posFrontNode->next;
			if (posNode == NULL) {
				printf("����Ϊ�գ��޷�ɾ����\n");
				return;
			}

		}
		posFrontNode->next = posNode->next;
		free(posNode);

	}

}


//���ң�
struct Node* searchNodeByAppoinNum(struct Node* listHeadNode, const char* num) {
	struct Node* pMove = listHeadNode->next;
	if (pMove == NULL) {
		return pMove;
	}
	else {
		while (pMove) {
			if (!strcmp(pMove->data.num, num)) {
				return pMove;
			}
			pMove = pMove->next;
		}
		printf("�޷��ҵ�����Ϣ!\n");
		return NULL;
	}
}



void printNode(struct Node* curNode) {
	printf("ѧ��\t����\t�Ա�\t�༶\t����\t��ѧ\tӢ��\n");
	printf("%s\t%s\t%s\t%d\t%.2f\t%.2f\t%.2f\n", curNode->data.num, curNode->data.name, curNode->data.sex,
		curNode->data.cla, curNode->data.Chinese, curNode->data.Math, curNode->data.English);

}



////��ӡ����,������
void printList(struct Node* listHeadNode) {

	struct Node* pMove = listHeadNode->next;
	printf("ѧ��\t����\t�Ա�\t�༶\t����\t��ѧ\tӢ��\n");

	while (pMove) {
		printf("%s\t%s\t%s\t%d\t%.2f\t%.2f\t%.2f\n", pMove->data.num, pMove->data.name, pMove->data.sex, pMove->data.cla,
			pMove->data.Chinese, pMove->data.Math, pMove->data.English);


		pMove = pMove->next;
	}
	printf("\n");
}

//�ļ����룻
void readInfoFromFile(const char* fileName, struct Node* listHeadNode) {
	FILE* fp = fopen(fileName, "r");

	if (fp == NULL) {
		fp = fopen(fileName, "w");
	}

	struct student tempdata;
	while (fscanf(fp, "%s %s %s %d %f %f %f\n", tempdata.num, tempdata.name, tempdata.sex, &tempdata.cla, &tempdata.Chinese, &tempdata.Math, &tempdata.English) != EOF) {
		insertNodeByHead(listHeadNode, tempdata);
		memset(&tempdata, 0, sizeof(tempdata));
	}

	fclose(fp);

}

//�ļ����棻
void saveInfoFromFile(const char* fileName, struct Node* listHeadNode) {
	FILE* fp = fopen(fileName, "w");
	struct Node* pMove = listHeadNode->next;

	while (pMove) {
		fprintf(fp, "%s\t%s\t%s\t%d\t%.2f\t%.2f\t%.2f\n", pMove->data.num, pMove->data.name, pMove->data.sex, pMove->data.cla,
			pMove->data.Chinese, pMove->data.Math, pMove->data.English);
		pMove = pMove->next;
	}

	fclose(fp);
}
