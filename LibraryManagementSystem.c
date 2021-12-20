#include <stdio.h>
#include <stdlib.h>

int main()
{
    struct reader{            //Define structure reader
        int id;               //id stores reader id
        char name[20];        //name stores reader's name
        char due;               //due stores y/n for if any book is due by particular leader
        int dbid;               //dbid stores due book's id
    } rdr[10]={0};              //rdr array is initialised with structure of reader

    struct book{                //structure book defined
        int id;                 //id here stores book id
        char name[30];          //name stores name of the book
        char author[20];        //author stores name of the author
        char avbl;              //avbl stores availability of the book as y/n
        int rid;                //rid stores reader id having the book
    } bk[20]={0};               //bk array is initialised with structure of book

    int choice, searchid, searchid1, n, m;          //some integer variables are declared to be used for performing different functions in program

    printf("\n\t\tWELCOME!\n");               //Welcome message
    
    do{                            //do-while loop is used to return to main menu after every case is over.i.e.task is done
    printf("\n\tLibrary Management System\n\t=========================\n1. Add new book\t\t2. Search book\n3. Add new reader\t4. Search reader\n5. Issue book\t\t6. Submit book\n7. Delete book\t\t8. Delete reader\n9. List of books\t10. Exit\n\nEnter your choice: ");
    scanf("%d", &choice);

    switch(choice){

        case 1:                             //Add a book
                for(int i=0; i<20; i++){
                    if (bk[i].id==0){               //to find empty space in bk array
                        printf("Enter name of the book: ");
                        scanf("%s", bk[i].name);
                        printf("Enter name of the author: ");
                        scanf("%s", bk[i].author);
                        printf("Enter book ID: ");
                        scanf("%d", &bk[i].id);
                        bk[i].avbl='y';             //set availability to y
                        bk[i].rid=0;                //set readers id to 0 as default
                        i=20;                       //to exit from for loop
                        printf("Book added successfully.\n\n");
                    }
                }
        break;

        case 2:
                printf("Enter book ID: ");
                scanf("%d", &searchid);
                n=0;
                for(int i=0; i<20; i++){
                    if (searchid == bk[i].id){
                    printf("\n\tBook Information\nBook ID: %d\tBook Name: %s\nAuthor Name: %s\nAvailable: %c\tDue by Reader ID: %d\n", bk[i].id, bk[i].name, bk[i].author, bk[i].avbl, bk[i].rid);
                    n++;
                    }
                }
                if(n==0){
                    printf("Book not found.\n\n");
                }

        break;

        case 3:
                for(int i=0; i<10; i++){        
                    if (rdr[i].id==0){                  // to search empty space in rdr array
                        printf("Enter Reader's name: ");
                        scanf("%s", rdr[i].name);
                        printf("Enter Reader id: ");
                        scanf("%d", &rdr[i].id);
                        rdr[i].due='n';
                        rdr[i].dbid=0;
                        i=10;
                        printf("Reader added successfully.\n\n");
                    }
                }
        break;

        case 4:
                printf("Enter Reader ID: ");
                scanf("%d", &searchid);
                n=0;
                for(int i=0; i<10; i++){
                    if (searchid==rdr[i].id){
                        printf("\n\tReader Information\nReader ID: %d\tReader Name: %s\nDue: %c\t\tDue book ID: %d\n", rdr[i].id, rdr[i].name, rdr[i].due, rdr[i].dbid);
                    n++;
                    }
                }
                if(n==0){
                    printf("Reader not found.\n\n");
                }   
        break;

        case 5:
                printf("Enter book ID: ");
                scanf("%d", &searchid);
                printf("Enter reader ID: ");
                scanf("%d", &searchid1);
                n=0;
                m=0;
                for(int i=0; i<20; i++){
                    if (searchid==bk[i].id && bk[i].avbl=='y'){
                        bk[i].avbl='n';
                        bk[i].rid=searchid1;
                        n++;
                        i=20;
                    }
                }
                for(int i=0; i<10; i++){
                    if (searchid1==rdr[i].id && rdr[i].due=='n'){
                        rdr[i].due='y';
                        rdr[i].dbid=searchid;
                        m++;
                        i=10;
                    }
               }
               if(n==1 && m==1){
                    printf("Book issued successfully.\n\n");
               }
               else if(n==1 && m==0){
                   for(int i=0; i<20; i++){
                        if (searchid==bk[i].id){
                            bk[i].avbl='y';
                            bk[i].rid=0;
                            i=20;
                        }
                    }
                    printf("Book not issued.\nReader has a due book.\n\n");
                }
        break;

        case 6:
                printf("Enter book ID: ");
                scanf("%d", &searchid);
                for(int i=0; i<20; i++){
                    if (searchid==bk[i].id){
                        bk[i].avbl='y';
                        searchid1=bk[i].rid;
                        bk[i].rid=0;
                    }
                }
                for(int i=0; i<10; i++){
                    if (searchid1==rdr[i].id){
                        rdr[i].due='n';
                        rdr[i].dbid=0;
                    }
                }
                printf("Book ID %d submitted successfully.\n\n", searchid);
        break;

        case 7:
                printf("Enter book ID to be deleted: ");
                scanf("%d", &searchid);
                n=0;
                for(int i=0; i<20; i++){
                    if (searchid==bk[i].id){
                        for(i=i; i<20; i++){
                            bk[i]=bk[i+1];
                        }
                        n++;
                    }
                }
                if(n!=0){
                    printf("Book ID %d deleted.\n\n", searchid);
                }
                else
                    printf("Book not found.\n\n");
        break;

        case 8:
                printf("Enter reader ID to be deleted: ");
                scanf("%d", &searchid);
                n=0;
                for(int i=0; i<10; i++){
                    if (searchid==rdr[i].id){
                        for(i=i; i<10; i++){
                            rdr[i]=rdr[i+1];
                        }
                        n++;
                    }
                }
                if(n!=0){
                    printf("Reader ID %d deleted.\n\n", searchid);
                }
                else
                    printf("Reader not found.\n\n");
        break;

        case 9:
                n=0;
                for(int i=0; i<20; i++){
                    if(bk[i].id != 0){
                        n++;
                    }
                }
                printf("\n\t\tBook list\tTotal books: %d\n\nID\tName\t\t\tAuthor\t\t\tAvailable\tReader ID\n\n", n);
                for(int i=0; i<20; i++){
                    if(bk[i].id != 0){
                    printf("%d\t%s\t\t%s\t\t%c\t\t%d\n", bk[i].id, bk[i].name, bk[i].author, bk[i].avbl, bk[i].rid);
                    }
                }
        break;

        case 10:
                printf("\n\t\tTHANK YOU!");

                exit(0);
        break;
        }

    }while(choice!=10);

    return 0;
}