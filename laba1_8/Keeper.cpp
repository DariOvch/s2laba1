#define _CRT_SECURE_NO_WARNINGS
#include "Keeper.h"

Keeper::Keeper(){
	printf("keeper created\n");
	size = 0;
	arr = nullptr;

}

Keeper::~Keeper() {

	printf("keeper deleted\n");
}


void Keeper::save()
{
	char* path = (char*)"file1.txt";
	printf("now file name is %s, would you like to change it? 0 no, 1 yes\n", path);
	int take = -1;
	while (take < 0 || take > 1)
		scan("%d", &take);


	if (take == 1)
	{
		char s[200]; printf("new value\n");
		try 
		{ 
			try_get(s); 
		}
		catch (char* msg) 
		{ 
			throw msg; 
		};
		path = new char[strlen(s)];
		strcpy(path, s);
	}
	FILE* fp = fopen(path, "w");
	fclose(fp);
	fp = fopen(path, "a");
	if (fp == nullptr)
	{
		throw (char*)"exeptoin: could not open file\n";
	}

	fprintf(fp, "%d\n", size);
	for (int i = 0; i < size; i++)
	{
		arr[i]->file_print(fp);
	}


	fclose(fp);

}

void Keeper::read()
{
	char* path = (char*)"file1.txt";
	printf("now file name is %s, would you like to change it? 0 no, 1 yes\n", path);
	int take = -1;
	while (take < 0 || take > 1)
		scan("%d", &take);
	if (take == 1)
	{
		char s[200]; printf("new value\n");
		try
		{
			try_get(s);
		}
		catch (char* msg)
		{
			throw msg;
		};
		path = new char[strlen(s)];
		strcpy(path, s);
	}

	FILE* fp = fopen(path, "r");
	if (fp == nullptr)
	{
		throw (char*)"exeptoin: could not open file\n";
	}

	
	int size2 = 0;
	BookstoreItem* add;

	if (fscanf(fp, "%d\n", &size2)!= 1)
		throw (char*)"exeption: data coppupted\n";

	if(size2 <= 0)
		throw (char*)"exeption: data coppupted\n";

	BookstoreItem** tmp = new BookstoreItem*[size2];
	int type = -1;

	for (int i = 0; i < size2; i++)
	{
		if (fscanf(fp, "%d\n", &type)!=1)
			throw (char*)"exeption: data coppupted\n";

		switch (type)
		{
		case book:
			try {
				add = new Book(fp);
			}
			catch (char* m)
			{
				throw m;
			}
			break;
		case manual:
			try {
			add = new Manual(fp);
			}
			catch (char* m)
			{
				throw m;
			}
			break; 
			
		case kants:
			try {
			add = new Kants(fp);
			}
			catch (char* m)
			{
				throw m;
			}
			break;
		default:
			throw (char*)"exeption: data coppupted\n";
		}

		tmp[i] = add;
	}

	
	


	BookstoreItem** new_arr = new BookstoreItem * [size+size2];

	for (int i = 0; i < size; i++)
	{
		new_arr[i] = arr[i];
	}

	for (int i = 0; i < size2; i++)
	{
		new_arr[i + size] = tmp[i];
	}

	arr = new_arr;
	size += size2;
	fclose(fp);
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
		item = new Manual;
		break;
	case kants:
		item = new Kants;
		break;

	}

	BookstoreItem** new_arr = new BookstoreItem* [size + 1];

	for (int i = 0; i < size; i++)
	{
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