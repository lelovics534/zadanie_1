#include<stdio.h>
#include<string.h>

unsigned int pocet_tokenov(char *str)
{
	int i,start,dlzka;
	unsigned int pocet, v_slove;
	
	i=0;
	pocet=0;
	v_slove=0; // v_slove=0 == nie sme v slove ale v bielom znaky, v_slove=1 == sme v nejakom slove
	
	while(str[i]!=0)
	{
		while(str[i]==' '|| str[i]=='\n'|| str[i]=='\t')
		{
			i++;
		}
		
		if(str[i]!=0)
		{
			start=i;
			
			while(str[i]!=0 && str[i]!= ' '|| str[i]!= '\n'|| str[i]!= '\t')
			{
				i++;
			}
			
			dlzka= i -start;
		}
	}
return(pocet);
}

int main(void)
{
	char text[]="prvy test";
	unsigned int vysledok = pocet_tokenov(text);
	
	printf("pocet tokenov: %u\n ",vysledok);
	return(0);
}

