#include "Keeper.h"

Keeper::Keeper(){
	printf("keeper created\n");
	size = 0;
	arr = nullptr;

}

Keeper::~Keeper() {

	printf("keeper deleted\n");
}

void Keeper::add()
{
	int type = -1;
	printf("%d to add book\n", book+1);
	printf("%d to add manual\n", manual + 1);
	printf("%d to add kants\n", kants + 1);
	while (type < 1 || type > 4) scan("%d", &type);

	BookstoreItem* item = new BookstoreItem;
	switch (type-1)
	{
	case book:
		item = new Book;
		break;
	case manual:
		break;
	case kants:
		break;

	}

	BookstoreItem** new_arr = new BookstoreItem* [size + 1];

	for (int i = 0; i < size; i++)
	{
		new_arr[i] = new BookstoreItem;
		new_arr[i] = arr[i];
	}

	new_arr[size] = item;
	delete arr; // ?
	arr = new_arr;

	size++;



}

int Keeper::edit()
{
	int in = 0;
	while (true)
	{
		printf("there are %d items added\n", size);
		printf("-1 back\n1 choose number to edit\n");
		scan("%d", &in);
		switch (in)
		{

		case -1:
			return 0;
		
		case 1:
		{
			int num = -1;
			printf("input number of item to edit\n");
			
			while (num < 1 || num > size) 
				scan("%d", &num);
			arr[num-1]->edit();
		}
		break;

		default:
			printf("unknown\n");
		}
	}
}

void Keeper::delet()
{
	if (size == 0)
		printf("empty\n");
	else
	{
		printf("there are %d items added\n", size);
		printf("input number of item to delete\n");
		int num = -1;
		while (num < 1 || num > size)
			scan("%d", &num);

		size--;
		for (int i = num-1; i < size; i++)
			arr[i] = arr[i + 1];
	}

}

void Keeper::seeall()
{
	if (size == 0)
		printf("empty\n");
	else
	{
		for (int i = 0; i < size; i++)
		{
			printf("item %d:\n", i+1); arr[i]->print();
		}
	}
}

void Keeper::seeinrange()
{
	if (size == 0)
		printf("empty\n");
	else
	{
		int min = 1, max = 0;
		while (min > max)
		{
			printf("min\n");
			scan("%d", &min);
			
			printf("max\n");
			scan("%d", &max);
		}
		for (int i = 0; i < size; i++)
		{
			if (arr[i]->get_price() >= min && arr[i]->get_price()<= max)
			arr[i]->print();
		}
	}
}