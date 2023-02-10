#include <stdio.h>
#include <string.h>

int main()
{
	char s1[25], s2[25], s3[25], snou[75] = ""; int l1, l2, l3, i, k;

	gets(s1); gets(s2); gets(s3);

	//strcat(s1, s2); strcat(s1, s3);
    //puts(s1);

    for(i = 0; i < strlen(s1); i++)
        snou[k++] = s1[i];

    for(i = 0; i < strlen(s2); i++)
        snou[k++] = s2[i];

    for(i = 0; i < strlen(s3); i++)
        snou[k++] = s3[i];

    snou[k] = '\0';

    puts(snou);

	return 0;
}
