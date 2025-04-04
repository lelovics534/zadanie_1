#include<stdio.h>
#include<string.h>

unsigned int pocet_tokenov(char *str)
{
	int i;
	unsigned int pocet;
	
	i=0;
	pocet=0;
	
	while(str[i]!=0)
	{
		if(str[i]==' '|| str[i]=='\n'|| str[i]=='\t')
		{
			pocet++;
		}
	i++;
	}
return(pocet);
}

int main(void)
{
	char text[]="prvy test";
	unsigned int vysledok = pocet_tokenov(text);
	
	printf("pocet tokenov: %d\n ",vysledok);
	return(0);
}

