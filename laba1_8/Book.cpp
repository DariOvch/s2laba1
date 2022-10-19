#define _CRT_SECURE_NO_WARNINGS

#include "Book.h"
#include "stdlib.h"
#include "io.h"

Book::Book()
{
	printf("Book created\n");
	set_type(book);

	set_price(0);
	set_name((char*)"unknown");
	set_author((char*)"unknown");
	set_genre((char*)"unknown");
	set_year(1);
	set_size(0);
}

Book::~Book()
{
	printf("Book deleted\n");
}

void Book::set_name(char s[200])
{
	strcpy(name, s);
};

void Book::set_author(char s[200]) {
	strcpy(author, s);
};

void Book::set_genre(char s[200]) {
	strcpy(genre, s);
};

void Book::set_year(int y) {
	year = y;
};

void Book::set_size(int i) {
	size = i;
};


char* Book::get_name() {
	return name;
}

char* Book::get_genre() {
	return genre;
}

char* Book::get_author() 
{
	return author;
};

int Book::get_year() 
{
	return year;
};

int Book::get_size() 
{
	return size;
};

void Book::print()
{
	printf("Book\n");
	printf("\'%s\' by %s, price: %d\n", get_name(), get_author(), get_price());
	printf("year published %d, %d pages, genre: %s\n", get_year(), get_size(), get_genre());
	printf("\n");
}


int Book::edit()
{
	print();

	
	int num = 0;
	while (true)
	{
		printf("edit menu\n-1 break\n1 name\n2 author\n3 price\n4 year\n5 size\n6 genre\nenter command\n");

		scan("%d", &num);
		switch (num)
		{

		case -1:
			return 0;

		case 1:
		{
			char s[200];
			printf("new value\n");
			try {
				try_get(s);
			}
			catch (char* msg)
			{
				throw msg;
			}
			set_name(s);
			break;
		}
		case 2:
		{
			char s[200]; printf("new value\n");
			try { try_get(s); }
			catch (char* msg) { throw msg; };
			set_author(s);
			break;
		}
		case 6:
		{
			char s[200]; printf("new value\n");
			try { try_get(s); } 
			catch(char* msg) {throw msg; };
			set_genre(s);
			break;
		}
		case 3:
		{
			int in = -1; printf("new value\n");
			while (in < 0) scan("%d", &in);
			set_price(in);
			break;
		}
		case 4:
		{
			int in = -1; printf("new value\n");
			while (in < 0) scan("%d", &in);
			set_year(in);
			break;
		}
		case 5:
		{
			int in = -1; printf("new value\n");
			while (in < 0) scan("%d", &in);
			set_size(in);
			break;
		}
		default:
			printf("unknown\n");
			break;

		}

	}

}

