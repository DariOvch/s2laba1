#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include "stdio.h"
#include "io.h"


enum types{book, manual, kants, unknown};

class BookstoreItem
{
	types type;
	int price;

public:

	BookstoreItem();
	~BookstoreItem();

	virtual void print() {};
	virtual int edit() { return 0; };

	void set_type(types t);
	types get_type();

	void set_price(int p);
	int get_price();




};