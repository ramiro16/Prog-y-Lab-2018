#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE* f;

    f = fopen("mihtml.html","w");

    if(f!=NULL)
    {
        fprintf(f,"<hmtl><head>HOLA</head></htmal>");
        fclose(f);
    }

    fclose(f);

    return 0;
}
