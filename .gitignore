# include <stdio.h>
# include <conio.h>
# include <stdlib.h>
# include <string.h>
 
# define MAX 100  /* constant*/
 
struct addr {                  /*struct called list*/
             char name[30]   ;
             char street[40] ;
             char town[20]   ;
             char county[20] ;
             char code[10]   ;
            }
            list[MAX];       /* 100 records*/
 
void menu_select(void);
void enter(void);
void find_free(void);
void inputs( char, char, int);
 
int main(void)
{
        clrscr();
        menu_select();
        getch();
        return 0;
}
 
void menu_select()
{
    int choice;
    printf("1. Enter a name\n")  ;
    printf("2. Delete a name\n") ;
    printf("3. List the File \n");
    printf("4. Search\n")        ;
    printf("5. Save the file\n") ;
    printf("6. Load the file\n") ;
    printf("7. Quit\n")          ;
 
    do {
    printf("\nEnter your choice: ");
       }
    while(choice<0 || choice>7);
 
         scanf("%d",&choice);
 
      switch(choice)
       {
                case 1: enter();         /* enter a new entry */
            break;
       //   case 2: del();           /* delete an entry */
      //        break;
      //    case 3: show_list();     /* display the list */
      //        break;
       //   case 4: search();        /* find an entry */
       //       break;
      //    case 5: save();          /* save to disk */
      //        break;
       //   case 6: load();          /* read from disk */
       //       break;
                case 7: exit(0);
 
    default:
        printf("Invalid choice. Please enter again");
      }
      getch();
}
 
void enter()
{
    int i;
 
    for(;;)
     {
      i = find_free();
      if(i<0)
      {
    printf("list full\n");
    return;
      }
      inputs("enter name: ", list[i].name,30);
      if
        (!*list[i].name) break;
      inputs("enter street: ", list[i].street, 40);
      inputs("enter town: ", list[i].town, 20);
      inputs("enter county: ", list[i].county, 20);
      inputs("enter Postal code: ", list[i].code, 10);
    }
}
 
void find_free()
{
    register int i;
    for(i=0; i<MAX; i++)
      if(!*list[i].name)
      return i;
      return -1;
}
 
void inputs( char *prompt , char *s , int count)
{
    char str[255];
 
    do
    {
    printf(prompt);
    gets(str);
    if
          (strlen(str)>=count)
          printf("\ntoo long\n");
    }
    while(strlen(str)>=count);
 
    strcpy(s , str);
}
