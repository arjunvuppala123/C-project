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
