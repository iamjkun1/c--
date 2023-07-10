#define _CRT_SECURE_NO_WARNINGS
#include "main.h"

////主菜单；

struct Node* list = NULL;
void systemMenu() {

	printf("************************************************************************************************************\n");

	printf("\t\t0.退出系统\n");
	printf("\t\t1.输入（插入）信息\n");
	printf("\t\t2.输出信息\n");
	printf("\t\t3.删除信息\n");
	printf("\t\t4.修改信息\n");
	printf("\t\t5.查找信息\n");
	printf("************************************************************************************************************\n");
	printf("请输入0-5：");

}

void keyDown() {
	int userKey;
	scanf("%d", &userKey);
	struct student tempdata;

	switch (userKey) {

	case 0:
		printf("谢谢使用！\n");
		system("pause");
		exit(0);
		break;
	case 1:
		printf("***************[插入信息]***************\n");
		printf("学号 姓名 性别 班级 语文 数学 英语：\n");
		scanf("%s%s%s%d%f%f%f", tempdata.num, tempdata.name, tempdata.sex,
			&tempdata.cla, &tempdata.Chinese, &tempdata.Math, &tempdata.English);


		insertNodeByHead(list, tempdata);

		saveInfoFromFile("student.txt", list);

		break;
	case 2:
		printf("***************[浏览信息]***************\n");
		printList(list);

		break;
	case 3:
		printf("***************[删除信息]***************\n");
		printf("请input删除学生的姓名：\n");


		scanf("%s", tempdata.name);
		deleteNodeByAppoinName(list, tempdata.name);

		saveInfoFromFile("student.txt", list);
		break;
	case 4:
		printf("***************[修改信息]***************\n");
		printf("输入要修改学生的学号：");
		scanf("%s", tempdata.num);

		if (searchNodeByAppoinNum(list, tempdata.num) == NULL) {
			printf("No\n");
		}
		else {

			struct Node* cutNode = searchNodeByAppoinNum(list, tempdata.num);

			printf("input新的学生的学号，姓名，性别，班级，语文，数学，英语\n");

			scanf("%s%s%s%d%f%f%f", cutNode->data.num, cutNode->data.name, cutNode->data.sex, &cutNode->data.cla,
				&cutNode->data.Chinese, &cutNode->data.Math, &cutNode->data.English);

		}
		saveInfoFromFile("student.txt", list);

		break;

	case 5:
		printf("***************[查找信息]***************\n");
		printf("请输入要查找学生的学号：\n");
		scanf("%s", tempdata.num);

		if (list->next == NULL)printf("当前通讯录信息为空!\n");
		else if (searchNodeByAppoinNum(list, tempdata.num) == NULL) {
			printf("No!\n");
		}
		else {
			printNode(searchNodeByAppoinNum(list, tempdata.num));
		}
		break;
	default:
		printf("选择错误，重新输入\n");
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

