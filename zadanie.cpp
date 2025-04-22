#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int porovnaj_slova(char *a, char *b)
{
	int i;
	
	i = 0;
	
	while(a[i] != 0 && b[i] != 0)
	{
		if(a[i] != b[i])
			return 0; // rozne slova
	    i++;
	}
	
	if (a[i] == 0 && b[i] == 0) // su rovnako dlhe slova
		return 1; 
	else
        return 0; //su rozne
}

unsigned int pocet_tokenov(char *str)
{
	int i, j, start, dlzka, existuje;
	unsigned int pocet, k, m;
	char *nove_slovo;
	char **slova;
	char **zoznam_slov;
	
	i = 0;
	pocet = 0;
	slova = NULL;
	
	while(str[i] != 0)
	{
		while(str[i] == ' '|| str[i] == '\n'|| str[i] == '\t')
			i++;
		
		if(str[i] != 0)
		{
			start = i;
			existuje=0; // pred kazdym slovom musime prepisat na 0
			
			while(str[i] != 0 && str[i] != ' ' && str[i] != '\n' && str[i]!= '\t')
				i++;
			
			dlzka= i -start;
			
			nove_slovo = (char *)malloc((dlzka + 1) * sizeof(char));
            for (j = 0; j < dlzka; j++)
                nove_slovo[j] = str[start + j];
            nove_slovo[dlzka] = '\0';
            
            for(k = 0; k < pocet; k++)
            	if (porovnaj_slova(slova[k], nove_slovo))
            	{
            		existuje = 1;
            		break;
				}
			
			if (existuje == 0)
			{
				zoznam_slov = (char **)malloc((pocet + 1) * sizeof(char *));
				for(m = 0; m < pocet; m++)
					zoznam_slov[m] = slova[m];
				zoznam_slov[pocet] = nove_slovo;
				
				free(slova);
				slova= zoznam_slov;
				pocet++;
			}
			else 
				free(nove_slovo);
		}
	}
	
	for (i = 0; i < pocet; i++)
		free(slova[i]);
	free(slova);
	
    return(pocet);
}


int main(void)
{
	char text[]="prvy test test ahoj svet sve";
	unsigned int vysledok = pocet_tokenov(text);
	
	printf("pocet roznych slov: %d\n ",vysledok);
	return(0);
}

