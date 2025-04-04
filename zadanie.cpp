#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int porovnaj_slova(char *a, char *b)
{
	int i, rovnake, rozne;
	
	i=0;
	
	while(a[i]!=0 && b[i]!=0)
	{
		if(a[i] != b[i])
		{
			return(0); // rozne slova
		}
	i++;
	}
	
	if (a[i]==0 && b[i]==0) // ak su rovnako dlhe slova
	{
		return(1); 
	}
	else
	{
		return (0); //su rozne
	}
}


unsigned int pocet_tokenov(char *str)
{
	int i,j,start,dlzka;
	unsigned int pocet, v_slove;
	char *nove_slovo;
	
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
			
			nove_slovo = (char *)malloc((dlzka + 1) * sizeof(char));
            for (j = 0; j < dlzka; j++)
            {
                nove_slovo[j] = str[start + j];
            }
            nove_slovo[dlzka] = '\0';
		}
	}
return(dlzka);
}

int main(void)
{
	char text[]="prvy test";
	unsigned int vysledok = pocet_tokenov(text);
	
	printf("pocet tokenov: %d\n ",vysledok);
	return(0);
}

