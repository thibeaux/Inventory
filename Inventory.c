#include<stdio.h>
#include<stdlib.h>
#include<string.h>
/*This is the original HARD COPY DO NOT DELETE this file*/
FILE *fp, *fr;
int main()
{
    int qty;
    int menu;
    char nomen[26];
    char pN[26];
    char ans;
    char ans2;
//Header Intro
do
{
    printf("Metro Aviation Tools List\n\n");
    printf("1. Add New List(overwrite file)\n");
    printf("2. View File\n");
    printf("3. Add to Existing list\n");
    printf("4. Delete Item\n");
    printf("5. Check Out/Edit/Return Items\n");
    printf("What would you like to do?\t");
    scanf("%d", &menu);

//Add new list
    if (menu == 1)
        {
            fp = fopen("Metro Inventory Master.txt", "w");
            fprintf(fp," List of Special Tools:");
            fprintf(fp,"\t\t\tPart Number:");
            fprintf(fp,"\t\t\t Quantity:\n\n");
            do
            {
            //Nomenclature
            printf("Enter Nomenclature(no spaces):\n");
            scanf("%s", nomen);
            fputs(nomen, fp);
            fputs("\t\t\t",fp);

            //Part Number

            printf("What is the part number?\n");
            scanf("%s", pN);
            fputs(pN, fp);
            fputs("\t\t\t", fp);
            //QTY
            printf("What is the quantity?\n");
            scanf("%d", &qty);
            fprintf(fp,"%d",qty);
            fputs("\n", fp);

        printf("To loop type Y.\n To exit type N.\n");
        getch();
        scanf("\n%c", &ans);
            }
//loop

while ((ans == 'Y')||(ans == 'y'));
}
//Display
            if (menu == 2)
                {

                int c;

                fp = fopen("Metro Inventory Master.txt", "r");
                    if (fp) {
                    while ((c = getc(fp)) != EOF)
                        putchar(c);
                            }
                }
/*Adds to the list*/
            if (menu == 3)
            {
                fp = fopen("Metro Inventory Master.txt","a");
            do
            {
            //Nomenclature
            printf("Enter Nomenclature(no spaces):\n");
            scanf("%s", nomen);
            fputs(nomen, fp);
            fputs("\t\t\t",fp);

            //Part Number

            printf("What is the part number?\n");
            scanf("%s", pN);
            fputs(pN, fp);
            fputs("\t\t\t", fp);
            //QTY
            printf("What is the quantity?\n");
            scanf("%d", &qty);
            fprintf(fp,"%d",qty);
            fputs("\n", fp);

        printf("To loop type Y.\n To exit type N.\n");
        getch();
        scanf("\n%c", &ans);
            }
//loop

while ((ans == 'Y')||(ans == 'y'));
            }
//Delete Line
// Deletes first character of the file each time ran. NEED TO FIX Menu 4
        if (menu == 4)
        {

    char ch;
    int delete_line, temp = 1;
    fp = fopen("Metro Inventory Master.txt", "r");
    ch = getc(fp);
    while (ch != EOF)
    {
        printf("%c", ch);
        ch = getc(fp);
    }
    //rewind
    rewind(fp);
    printf("\n Enter line number of the line to be deleted:\n");
    scanf("%d", &delete_line);
    //open new file in write mode
    fr = fopen("replica.c", "w");
    ch = getc(fp);
    while (ch != EOF)
    {
        ch = getc(fp);
        if (ch == '\n')
            temp++;
            //except the line to be deleted
            if (temp != delete_line)
            {
                //copy all lines in file replica.c
                putc( ch, fr);
            }
    }
    fclose(fp);
    fclose(fr);
    remove("Metro Inventory Master.txt");
    //rename the file replica.c to original name
    rename("replica.c", "Metro Inventory Master.txt");
    printf("\n The contents of file after being modified are as follows:\n");
    fp = fopen("Metro Inventory Master.txt", "r");
    ch = getc(fp);

    while (ch != EOF)
    {
        printf("%c", ch);
        ch = getc(fp);
    }
    fclose(fp);

        }
//check out
    if (menu == 5)
        {
            printf("Check out system\n");
    FILE *fileptr1, *fileptr2;
    char c;
    int delete_line, temp = 1;

    fileptr1 = fopen("Metro Inventory Master.txt", "r");
    c = getc(fileptr1);
    //print the contents of file .
    while (c != EOF)
    {
        printf("%c", c);
        c = getc(fileptr1);
    }
    printf(" \n Enter line number to be deleted and replaced");
    scanf("%d", &delete_line);
    //take fileptr1 to start point.
    rewind(fileptr1);
    //open replica.c in write mode
    fileptr2 = fopen("replica.c", "w");
    c = getc(fileptr1);
    while (c != EOF)
    {
        if (c == '\n')
        {
            temp++;
        }
        //till the line to be deleted comes,copy the content to other
        if (temp != delete_line)
        {
            putc(c, fileptr2);
        }
        else
        {
            while ((c = getc(fileptr1)) != '\n')
            {
            }
            //read and skip the line ask for new text
            printf("Enter new text\n");
            //flush the input stream
            fflush(stdin);
            putc('\n', fileptr2);
            //put 'n' in new file
            while ((c = getchar()) != '\n')
                putc(c, fileptr2);
            //take the data from user and place it in new file
            fputs("\n", fileptr2);
            temp++;
        }
        //continue this till EOF is encountered
        c = getc(fileptr1);
    }
    fclose(fileptr1);
    fclose(fileptr2);
    remove("Metro Inventory Master.txt");
    rename("replica.c", "Metro Inventory Master.txt");
    fileptr1 = fopen("Metro Inventory Master.txt", "r");
    //reads the character from file
    c = getc(fileptr1);
    //until last character of file is encountered
    while (c != EOF)
    {
        printf("%c", c);
        //all characters are printed
        c = getc(fileptr1);
    }
    fclose(fileptr1);

        }
fclose(fp);
printf("Go back to main menu?");
getch();
scanf("\n%c", &ans2);
}

while ((ans2 == 'Y') || (ans2 == 'y'));
return 0;
}

