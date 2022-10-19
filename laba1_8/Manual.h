#pragma once
#include "Bookstore.h"
#include "string.h"

class Manual : public BookstoreItem
{
	char name[200];
	char author[200];
	int year;
	int grade;
	char school[200];
	int size;

public:
	Manual();
	Manual(FILE* f);
	~Manual();

	void set_name(char s[200]);
	void set_author(char s[200]);
	void set_school(char s[200]);
	void set_year(int y);
	void set_grade(int g);
	void set_size(int i);

	char* get_name();
	char* get_author();
	char* get_school();
	int get_year();
	int get_grade();
	int get_size();

	void print() override;
	void file_print(FILE* f) override;
	int edit() override;

};