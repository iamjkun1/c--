#define _CRT_SECURE_NO_WARNINGS
#include "main.h"

////���˵���

struct Node* list = NULL;
void systemMenu() {

	printf("************************************************************************************************************\n");

	printf("\t\t0.�˳�ϵͳ\n");
	printf("\t\t1.���루���룩��Ϣ\n");
	printf("\t\t2.�����Ϣ\n");
	printf("\t\t3.ɾ����Ϣ\n");
	printf("\t\t4.�޸���Ϣ\n");
	printf("\t\t5.������Ϣ\n");
	printf("************************************************************************************************************\n");
	printf("������0-5��");

}

void keyDown() {
	int userKey;
	scanf("%d", &userKey);
	struct student tempdata;

	switch (userKey) {

	case 0:
		printf("ллʹ�ã�\n");
		system("pause");
		exit(0);
		break;
	case 1:
		printf("***************[������Ϣ]***************\n");
		printf("ѧ�� ���� �Ա� �༶ ���� ��ѧ Ӣ�\n");
		scanf("%s%s%s%d%f%f%f", tempdata.num, tempdata.name, tempdata.sex,
			&tempdata.cla, &tempdata.Chinese, &tempdata.Math, &tempdata.English);


		insertNodeByHead(list, tempdata);

		saveInfoFromFile("student.txt", list);

		break;
	case 2:
		printf("***************[�����Ϣ]***************\n");
		printList(list);

		break;
	case 3:
		printf("***************[ɾ����Ϣ]***************\n");
		printf("��inputɾ��ѧ����������\n");


		scanf("%s", tempdata.name);
		deleteNodeByAppoinName(list, tempdata.name);

		saveInfoFromFile("student.txt", list);
		break;
	case 4:
		printf("***************[�޸���Ϣ]***************\n");
		printf("����Ҫ�޸�ѧ����ѧ�ţ�");
		scanf("%s", tempdata.num);

		if (searchNodeByAppoinNum(list, tempdata.num) == NULL) {
			printf("No\n");
		}
		else {

			struct Node* cutNode = searchNodeByAppoinNum(list, tempdata.num);

			printf("input�µ�ѧ����ѧ�ţ��������Ա𣬰༶�����ģ���ѧ��Ӣ��\n");

			scanf("%s%s%s%d%f%f%f", cutNode->data.num, cutNode->data.name, cutNode->data.sex, &cutNode->data.cla,
				&cutNode->data.Chinese, &cutNode->data.Math, &cutNode->data.English);

		}
		saveInfoFromFile("student.txt", list);

		break;

	case 5:
		printf("***************[������Ϣ]***************\n");
		printf("������Ҫ����ѧ����ѧ�ţ�\n");
		scanf("%s", tempdata.num);

		if (list->next == NULL)printf("��ǰͨѶ¼��ϢΪ��!\n");
		else if (searchNodeByAppoinNum(list, tempdata.num) == NULL) {
			printf("No!\n");
		}
		else {
			printNode(searchNodeByAppoinNum(list, tempdata.num));
		}
		break;
	default:
		printf("ѡ�������������\n");
		system("pause");
		break;
	}
}


int main() {

	list = createList();
	readInfoFromFile("student.txt", list);


	while (1) {
		systemMenu();
		keyDown();
		system("pause");
		system("cls");
	}
	return 0;
}

