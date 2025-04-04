#include<stdio.h>
#include<string.h>

unsigned int pocet_tokenov(char *str)
{
	int i;
	unsigned int pocet, v_slove;
	
	i=0;
	pocet=0;
	v_slove=0; // v_slove=0 == nie sme v slove ale v bielom znaky, v_slove=1 == sme v nejakom slove
	
	while(str[i]!=0)
	{
		if(str[i]==' '|| str[i]=='\n'|| str[i]=='\t')
		{
			v_slove=0;
		}
		else
		{
			if(v_slove==0)
			{
			pocet++;
			v_slove=1;
			}
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

