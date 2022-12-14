#pragma once
#include "Manual.h"
#include "Bookstore.h"
#include "string.h"


Manual::Manual(){
	printf("Manual created\n");
	
	set_type(manual);

	set_price(0);
	set_name((char*)"unknown");
	set_author((char*)"unknown");
	set_school((char*)"unknown");
	set_year(1);
	set_grade(-1);
	set_size(0);
}

Manual::Manual(FILE* f)
{
	printf("Book created\n");
	set_type(book);
	char str[200];
	int val = 0;
	try { try_getf(f, str); } catch (char* m) { throw m; }  trim(str); set_name(str);
	if (fscanf(f, "%d\n", &val) != 1) throw (char*)"data corrupted"; set_grade(val);
	try { try_getf(f, str); } catch (char* m) { throw m; }  trim(str); set_author(str);
	if (fscanf(f, "%d\n", &val) != 1) throw (char*)"data corrupted"; trim(str); set_price(val);
	if (fscanf(f, "%d\n", &val) != 1) throw (char*)"data corrupted"; trim(str); set_year(val);
	if (fscanf(f, "%d\n", &val) != 1) throw (char*)"data corrupted"; trim(str); set_size(val);
	try { try_getf(f, str); } catch (char* m) { throw m; }  set_school(str);

}
Manual::~Manual(){ 
	printf("Manual deleted\n");
}

void Manual::set_name(char s[200]) { strcpy(name, s); }
void Manual::set_author(char s[200]){ strcpy(author, s); }
void Manual::set_school(char s[200]){ strcpy(school, s); }
void Manual::set_year(int y) { year = y; }
void Manual::set_grade(int g) { grade = g; }
void Manual::set_size(int i) { size = i; }

char* Manual::get_name() { return name; }
char* Manual::get_author() { return author; }
char* Manual::get_school() { return school; }
int Manual::get_year() { return year; }
int Manual::get_grade() { return grade; }
int Manual::get_size() { return size; }

void Manual::print(){ 
	printf("Book\n");
	printf("\'%s\' for %d grade by %s, price: %d\n", get_name(), get_grade(), get_author(), get_price());
	printf("year published %d, %d pages, school: %s\n", get_year(), get_size(), get_school());
	printf("\n");

}
void Manual::file_print(FILE* f)
{
	fprintf(f, "%d\n", get_type());
	fprintf(f, "%s\n", get_name());
	fprintf(f, "%d\n", get_grade());
	fprintf(f, "%s\n", get_author());
	fprintf(f, "%d\n", get_price());
	fprintf(f, "%d\n", get_year());
	fprintf(f, "%d\n", get_size());
	fprintf(f, "%s\n", get_school());
}

int Manual::edit() {
	print();

	int num = 0;
	while (true)
	{
		printf("edit menu\n-1 break\n1 name\n2 author\n3 price\n4 year\n5 size\n6 school\n7 grade\nenter command\n");

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
		case 6:
		{
			char s[200]; printf("new value\n");
			try { try_get(s); }
			catch (char* msg) { throw msg; };
			set_school(s);
			break;
		}
		case 7:
		{
			int in = -1; printf("new value\n");
			while (in < 0) scan("%d", &in);
			set_grade(in);
			break;
		}
		default:
			printf("unknown\n");
			break;

		}

	}


	return 0;
}
