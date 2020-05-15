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
