#include "Kants.h"


Kants::Kants(){ 
	printf("Manual created\n");

	set_type(kants);


	set_price(0);
	set_color((char*)"unknown");
	set_tip((char*)"unknown");
	set_purpose((char*)"unknown");

}
Kants::~Kants(){ 

}

void Kants::set_color(char s[200]){ 
	strcpy(color, s);
}
void Kants::set_tip(char s[200]){ 
	strcpy(tip, s);
}
void Kants::set_purpose(char s[200]){ 
	strcpy(purpose, s);
}

char* Kants::get_color() { return color; }
char* Kants::get_tip() { return tip; }
char* Kants::get_purpose() { return purpose; }

void Kants::print() { 
	printf("Stationery\n");
	printf("\'%s\' in %s color for %s, price: %d\n", get_tip(), get_color(), get_purpose(), get_price());
	printf("\n");
}


int Kants::edit() { 
	
	print();

	int num = 0;
	while (true)
	{
		printf("edit menu\n-1 break\n1 name\n2 color\n3 price\n4 purpose\nenter command\n");

		scan("%d", &num);
		switch (num)
		{

		case -1:
			return 0;

		case 1:
		{
			char s[200]; printf("new value\n");
			try { try_get(s); }
			catch (char* msg) { throw msg; };
			set_tip(s);
			break;
		}
		case 2:
		{
			char s[200]; printf("new value\n");
			try { try_get(s); }
			catch (char* msg) { throw msg; };
			set_color(s);
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
			char s[200]; printf("new value\n");
			try { try_get(s); }
			catch (char* msg) { throw msg; };
			set_purpose(s);
			break;
		}


		default:
			printf("unknown\n");
			break;

		}

	}


	return 0;

}

