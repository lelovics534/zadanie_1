#include<stdio.h>
#include<string.h>

unsigned int pocet_tokenov(char *str)
{
}

int main(void)
{
	char text[]="";
	unsigned int vysledok = pocet_tokenov(text);
	
	printf("pocet tokenov: %d\n ",vysledok);
	return(0);
}

