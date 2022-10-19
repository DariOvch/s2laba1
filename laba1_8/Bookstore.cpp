#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include "Bookstore.h"



BookstoreItem::BookstoreItem()
{
	printf("bookstoreItem created\n");
	set_price(0);
	set_type(unknown);
}

BookstoreItem::~BookstoreItem()
{
	printf("bookstoreItem deleted\n");
}

void BookstoreItem::set_type(types t)
{
	type = t;
}

types BookstoreItem::get_type()
{
	return type;
}

void BookstoreItem::set_price(int p)
{
	price = p;
}

int  BookstoreItem::get_price()
{
	return price;
}

