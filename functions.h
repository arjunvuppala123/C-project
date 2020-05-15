#include<stdio.h>
#include<string.h>
struct bug
{
    int id;
    char description[500];
    char Filled_by_name[50];
    char priority[10];
    char type[10];
    char status[50];
    char Assigned_to[50];
    char logdatetime[90];
};

typedef struct bug bug;

int id(bug FileRec)
{
    FILE *ipt;
	int max=0;
	 ipt = fopen ("sample.dat", "rb");
	 rewind(ipt);
	 while(fread(&FileRec, sizeof(FileRec), 1, ipt)==1)
            {
                if(FileRec.id>max)
                {
                    max=FileRec.id;
                }
            }
	 max=max+1;
	 return max;
}

void checkstring(char str[])
{
    int i,count=0;
    for (i=0; str[i]!= '\0'; i++)
    {
        if (isdigit(str[i]))
            {
                count=count+1;
            }
    }
    if (count>0)
    {
        printf("Enter string only!!::");
        fflush(stdin);
        scanf(" %s",str);
    }

}

int availbug(bug x,int item)
{
    FILE *ipt;
    int flag=0;
    ipt=fopen("sample.dat", "rb");
    rewind(ipt);
    while(fread(&x, sizeof(x), 1, ipt)==1)
        {
            if (x.id==item)
            {
                flag=1;
            }
        }
    fclose(ipt);
    return flag;
}

void bugentry()
{
    bug b;
    FILE *fpt;
    char ch,c;
    int index=0;

    do{
            fpt=fopen("sample.dat","ab");

            b.id=id(b);
            printf("ID:#%d\n",b.id);

            printf("Enter name of user who filed the bug:");
            scanf("%s",b.Filled_by_name);
            checkstring(b.Filled_by_name);

            printf("Enter Description:");
            scanf(" %[^\n]%*c",b.description);
            checkstring(b.description);

           strcpy(b.status,"Not-Assigned");
           printf("Default Status is:%s\n", b.status);

            printf("Enter priority of Bug(High , Low , Medium):");
            scanf("%s",b.priority);
            checkstring(b.priority);

            printf("Enter type of bug(major, minor, cosmetic):");
            scanf("%s",b.type);
            checkstring(b.type);

            fwrite(&b,sizeof(b),1,fpt);

             if(fwrite != 0)
                printf("contents to file written successfully !\n");

            else
                printf("error writing file !\n");

            printf("Want to enter more Bugs?? (y for yes and n for no):");
            scanf(" %c",&ch);

           }while(ch=='y' || ch=='Y');
}

void dispbugstatsbyname()
{
    FILE *ipt;
    bug b;
    char item[50];
    int  flag=0,a;
    printf("Enter the name of the user:");
    scanf(" %s",item);
    checkstring(item);
    ipt = fopen ("sample.dat", "rb");
    rewind(ipt);
    while(fread(&b, sizeof(b), 1, ipt)==1)
        {
            if(strcmp(item,b.Filled_by_name)==0)
                {
                    flag=1;
                    printf("ID:%d\nName of user who Filled the bug:%s\nStatus:%s\nType:%s\nPriority:%s\nDescription:%s\n",b.id,b.Filled_by_name,b.status,b.description,b.priority,b.type);
                }
        }
    if (flag==0)
        printf("Name not found!!");
   fclose(ipt);
}
void dispbugstatsbytype()
{
    FILE *ipt;
    bug b;
    char item[50],item1[50];
    char ch;
    int  flag=0,a,j=0;
    printf("Enter type of bug (major,minor,cosmetic):");
    scanf("%s",item);
    checkstring(item);
    while (item[j]!='\0') {
        ch = item[j];
        item1[j]=toupper(ch);
        j++;
    }
    while ( strcmp(item1,"MAJOR")!=0 && strcmp(item1,"MINOR")!=0 && strcmp(item1,"COSMETIC")!=0 )
    {
        printf("Invalid value !!! Re-enter:");
        fflush(stdin);
        scanf("%s",item);
    }
    ipt = fopen ("sample.dat", "rb");
    rewind(ipt);
    while(fread(&b, sizeof(b), 1, ipt)==1)
        {
            if(strcmp(item,b.type)==0)
                {
                    flag=1;
                    printf("ID:%d    Name of user who Filled the bug:%s   Status:%s   Description:%s  Priority:%s  Type:%s",b.id,b.Filled_by_name,b.status,b.description,b.priority,b.type);
                }
        }
    if (flag==0)
        printf("Name not found!!");
    fclose(ipt);
}

void dispbugstatsbystatus()
{
     FILE *ipt;
    bug b;
    char item[50];
    int  flag=0,a;
    printf("Enter the status(Not yet assigned, In process, Fixed, Delivered):");
    scanf("%s",item);
    checkstring(item);
    ipt = fopen ("sample.dat", "rb");
    rewind(ipt);
    while(fread(&b, sizeof(b), 1, ipt)==1)
        {
            if(strcmp(item,b.status)==0)
                {
                    flag=1;
                    printf("ID:%d    Name of user who Filled the bug:%s   Status:%s   Description:%s  Priority:%s  Type:%s",b.id,b.Filled_by_name,b.status,b.description,b.priority,b.type);
                }
        }
    if (flag==0)
        printf("Name not found!!");
   fclose(ipt);
}
void BugStats()
{
    int ch,a;
    printf("\nList of Bugs through:");
    printf("\n1. Filed by the same person");
    printf("\n2. Have the same type");
    printf("\n3. Have the same status");
    printf("\nEnter Choice:");
    a=scanf("%d",&ch);
    while (a!=1)
        {
            printf("\nonly integer type allowed\n");
            fflush(stdin);
                a=scanf("%d",&ch);
        }
    switch(ch)
    {
        case 1:
            dispbugstatsbyname();
             break;

        case 2:
            dispbugstatsbytype();
            break;

        case 3:
            dispbugstatsbystatus();
            break;

        default:
            printf("Wrong choice!! Enter again");
            break;
        }
}
/*
void usermenu()
{
    int ch,a;
    printf("\nUser Menu");
    printf("\n1.Report a bug");
    printf("\n2.Bug Statistics");
    printf("\n3.Quit");
    printf("\nEnter Your Choice:");
    a=scanf("%d",&ch);
    while (a!=1)
        {
            printf("\nonly integer type allowed\n");
            fflush(stdin);
                a=scanf("%d",&ch);
        }
    switch(ch)
    {
    case 1:
        bugentry();
        break;
    case 2:
        BugStats();
        break;
    case 3:
        break;
    default: printf("Wrong Choice:");
    }
}
*/

void AssignBug()
{
    bug b;
    FILE *fpt,*fpo;
    int s, r, ch,flag1=0,a;
    printf("Enter bug id:");
    a=scanf("%d", &r);
    while (a!=1)
        {
            printf("\nonly integer type allowed\n");
            fflush(stdin);
                a=scanf("%d",&r);
        }
    ch=availbug(b,r);
    if (ch==0)
    {

        printf("\nbug id not found!\n");
    }
    else
    {
        fpo = fopen("sample.dat", "rb");
        fpt = fopen("TempFile.dat", "wb");
        rewind(fpo);
        while (fread(&b, sizeof(b), 1, fpo)==1)
            {
                if (b.id != r)
                    {
                        fwrite(&b, sizeof(b), 1, fpt);
                    }
                else
                    {
                        if (strcmp(b.status,"Not-Assigned")!=0)
                        {
                            printf("Bug is already assigned");
                            fwrite(&b, sizeof(b), 1, fpt);
                        }
                        else
                        {
                        printf("enter the name you assigned bug to:");
                        scanf(" %s", b.Assigned_to);
                        strcpy(b.status,"Assigned");
                        printf("%s",b.status);
                        fwrite(&b, sizeof(b), 1, fpt);
                        }
                    }
            }
                fclose(fpo);
                fclose(fpt);
                fpo = fopen("sample.dat", "wb");
                fpt = fopen("TempFile.dat", "rb");
                while (fread(&b, sizeof(b), 1, fpt))
                    {
                        fwrite(&b, sizeof(b), 1, fpo);
                    }
                fclose(fpo);
                fclose(fpt);
        }
}

void modifyStatus()
{
    bug b;
    FILE *fpt,*fpo;
    int s, r, ch,flag1=0,a;
    printf("Enter bug id:");
    a=scanf("%d", &r);
    while (a!=1)
        {
            printf("\nonly integer type allowed\n");
            fflush(stdin);
                a=scanf("%d",&r);
        }
    ch=availbug(b,r);
    if (ch==0)
    {

        printf("\nbug id not found!\n");
    }
    else
    {
        fpo = fopen("sample.dat", "rb");
        fpt = fopen("TempFile.dat", "wb");
        rewind(fpo);
        while (fread(&b, sizeof(b), 1, fpo)==1)
            {
                s = b.id;
                if (s != r)
                    {
                        fwrite(&b, sizeof(b), 1, fpt);
                    }
                else
                    {
                        if (strcmp(b.status,"Not-Assigned")==0)
                        {
                            printf("Bug has not got assigned!!please assign!!");
                            fwrite(&b, sizeof(b), 1, fpt);
                        }
                        else if(strcmp(b.status,"Assigned")==0)
                        {
                            printf("Bug status has changed from Assigned to In process!!");
                            strcpy(b.status,"In process");
                            fwrite(&b, sizeof(b), 1, fpt);
                        }
                        else if(strcmp(b.status,"In process")==0)
                        {
                            printf("Bug status has changed from In process to Fixed!!");
                            strcpy(b.status,"Fixed");
                            fwrite(&b, sizeof(b), 1, fpt);
                        }
                        else if(strcmp(b.status,"Fixed")==0)
                        {
                            printf("Bug status has changed from Fixed to Delivered!!");
                            strcpy(b.status,"Delivered");
                            fwrite(&b, sizeof(b), 1, fpt);
                        }
                        else
                        {
                            printf("The bug has been fixed and delivered!!");
                            fwrite(&b, sizeof(b), 1, fpt);
                        }
                    }
            }
            fclose(fpo);
            fclose(fpt);
            fpo = fopen("sample.dat", "wb");
            fpt = fopen("TempFile.dat", "rb");
            while (fread(&b, sizeof(b), 1, fpt))
                {
                    fwrite(&b, sizeof(b), 1, fpo);
                }
            fclose(fpo);
            fclose(fpt);
    }
}
/*
void managermenu()
{
     int ch;
     printf("\nManager Menu");
     printf("\n1.Assign the person to change status");
     printf("\n2.Modify status of bug");
     printf("\n3.Bug Statistics");
     printf("\n4.Quit");
     printf("\nEnter Your Choice:");
     scanf("%d",&ch);
     switch(ch)
    {
    case 1:
        AssignBug();
        break;
    case 2:
        modifyStatus();
        break;
    case 3:
        BugStats();
        break;
    case 4:
        break;
    default: printf("Wrong Choice");
    }
}
*/
