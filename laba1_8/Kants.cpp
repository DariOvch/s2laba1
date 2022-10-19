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
	printf("\'%s\' in %s color, price: %d\n", get_tip(), get_color(), get_price());
	printf("\n");
}
int Kants::edit() { 
	
	return 0;

}

