#include "functions.h"
#include "user.c"
#include "manager.c"

int main()
{
    int ch;
    bug x;
    FILE *ipt;
    ipt=fopen("sample.dat","rb");
    while(fread(&x, sizeof(x), 1, ipt)==1)
        {
            printf("%d\n%s\n%s\n%s\n%s\n%s\n", x.id , x.Filled_by_name , x.description , x.priority , x.status , x.type);
            printf("%s\n",x.Assigned_to);
        }
    printf("Log in as:");
    printf("\n1.User");
    printf("\t2.Manager");
    printf("\nEnter your  choice:(1-User 2-Manager):");
    scanf("%d", &ch);
    switch(ch)
    {
        case 1:
            usermenu();
            break;

        case 2:
            managermenu();
            break;

        default:
            printf("\nWrong Choice!!Try again\n");
            break;
    }
}
