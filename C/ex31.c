#include <stdio.h>
#include <string.h>
 
char s1[81], s2[81];
 
int main()
{
	int i, k;
	gets(s1);
	gets(s2);
	char *p = strstr(s1, s2);
	printf("%p\n", p);
	printf("%p\n", s1);
	printf("%c\n", p[0]);
	/*while(1)
	{
		char *p = strstr(s1, s2);
		if ( p )
		{
			
			for ( i=0; i<strlen(p) - strlen(s2); i++ )
			{
				p[i] = p[strlen(s2) + i];
			}
			p[i] = '\0';
	    }
	    else
		{
	    	puts(s1);
	    	break;
		}
	}*/
	
	return 0;
}
