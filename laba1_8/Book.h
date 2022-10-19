#pragma once
#include "Bookstore.h"
#include "string.h"

class Book : public BookstoreItem
{
	char name[200];
	char author[200];
	int year;
	char genre[200];
	int size;

public:
	Book();
	~Book();

	void set_name(char s[200]);
	void set_author(char s[200]);
	void set_genre(char s[200]);
	void set_year(int y);
	void set_size(int i);

	char* get_name();
	char* get_genre();
	char* get_author();
	int get_year();
	int get_size();

	void print() override;
	int edit() override;


};