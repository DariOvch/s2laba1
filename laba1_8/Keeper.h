#include "stdio.h"
#include "Book.h"
#include "Manual.h"
#include "Kants.h"

class Keeper
{
	BookstoreItem** arr;
	int size;

public:
	Keeper();
	~Keeper();


	void add();
	int edit();
	void delet();

	void seeall();
	void seeinrange();
};