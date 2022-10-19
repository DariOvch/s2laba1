#pragma once
#include "Bookstore.h"
#include "string.h"

class Kants : public BookstoreItem
{
	char tip[200];
	char color[200];
	char purpose[200];

public:
	Kants();
	~Kants();

	void set_color(char s[200]);
	void set_tip(char s[200]);
	void set_purpose(char s[200]);

	char* get_color();
	char* get_tip();
	char* get_purpose();

	void print() override;
	int edit() override;

};