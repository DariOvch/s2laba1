
#include "stdio.h"
#include <iostream>

#include "Keeper.h"
#include "io.h"

#define EXIT -1
#define CLEAR 0
#define SEEALL 1
#define ADD 2
#define DEL 3
#define EDIT 4
#define SAVE 5
#define READ 6
#define SEEINRANGE 7



int main()
{
	Keeper cnt;

	printf("main menu\n");
	printf("exit %d\n", EXIT);
	printf("clear %d\n", CLEAR);
	printf("see all %d\n", SEEALL);
	printf("see in range %d\n", SEEINRANGE);
	printf("add %d\n", ADD);
	printf("delete %d\n", DEL);
	printf("edit %d\n", EDIT);
	printf("SAVE %d\n", SAVE);
	printf("READ %d\n", READ);


	int t = 0;
	while (true)
	{
		printf("\nmain menu\n");
		scan("%d", &t);
		switch (t)
		{

		case EXIT:
			return 0;

		case CLEAR:
		{
			system("cls");
			printf("menu\n");
			printf("exit %d\n", EXIT);
			printf("clear %d\n", CLEAR);
			printf("see all %d\n", SEEALL);
			printf("see in range %d\n", SEEINRANGE);
			printf("add %d\n", ADD);
			printf("edit %d\n", EDIT);
			printf("delete %d\n", DEL);
			printf("SAVE %d\n", SAVE);
			printf("READ %d\n", READ);
		}
			break;

		case SEEALL:
			cnt.seeall();
			break;

		case SEEINRANGE:
			cnt.seeinrange();
			break;

		case ADD:
			cnt.add();
			break;

		case EDIT:
			cnt.edit();
			break;

		case DEL:
			cnt.delet();
			break;

		default:
			printf("unknown\n");
			break;

		}
	}


	return 0;
}