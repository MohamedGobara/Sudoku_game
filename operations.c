
#include "operations.h"

void defualt_numbers(int arr[9][9])
{


    arr[0][1] = 7;
    arr[0][2] = 2;
    arr[0][5] = 4;
    arr[0][6] = 9;

    arr[1][0] = 3;
    arr[1][2] = 4;
    arr[1][4] = 8;
    arr[1][5] = 9;
    arr[1][6] = 1;

    arr[2][0] = 8;
    arr[2][1] = 1;
    arr[2][2] = 9;
    arr[2][5] = 6;
    arr[2][6] = 2;
    arr[2][7] = 5;
    arr[2][8] = 4;

    arr[3][0] = 7;
    arr[3][2] = 1;
    arr[3][7] = 9;
    arr[3][8] = 5;

    arr[4][0] = 9;
    arr[4][5] = 2;
    arr[4][7] = 7;

    arr[5][3] = 8;
    arr[5][5] = 7;
    arr[5][7] = 1;
    arr[5][8] = 2;

    arr[6][0] = 4;
    arr[6][2] = 5;
    arr[6][5] = 1;
    arr[6][6] = 6;
    arr[6][7] = 2;

    arr[7][0] = 2;
    arr[7][1] = 3;
    arr[7][2] = 7;
    arr[7][6] = 5;
    arr[7][8] = 1;

    arr[8][4] = 2;
    arr[8][5] = 5;
    arr[8][6] = 7;


}


void init_arr(int arr[9][9])
{


    for(int i =0 ; i<9 ; i++)
    {
        for(int j= 0 ; j <9 ; j++)
        {


            arr[i][j] = -1 ;
        }


    }
}

int check_primary_numbers(int x, int y)
{

    if(x==1 &&y==2 ||
            x== 1&&y==3 ||
            x==1 &&y==6 ||
            x==1 &&y== 7||

            x==2 &&y== 1||
            x==2 &&y== 3||
            x== 2&&y== 5||
            x== 2&&y== 6||
            x== 2&&y== 7||

            x== 3&&y== 1||
            x== 3&&y== 2||
            x== 3&&y== 3||
            x== 3&&y== 6||
            x== 3&&y== 7||
            x== 3&&y== 8||
            x== 3&&y== 9||

            x== 4&&y== 1||
            x== 4&&y== 3||
            x== 4&&y== 8||
            x== 4&&y== 9||

            x== 5&&y== 1||
            x== 5&&y== 6||
            x== 5&&y== 8||


            x== 6&&y== 4||
            x== 6&&y== 6||
            x== 6&&y== 8||
            x== 6&&y== 9||

            x== 7&&y== 1||
            x== 7&&y== 3||
            x== 7&&y== 6||
            x== 7&&y== 7||
            x== 7&&y== 8||

            x== 8&&y==1 ||
            x== 8&&y== 2||
            x== 8&&y== 3||
            x== 8&&y== 7||
            x== 8&&y== 9||

            x== 9&&y== 5||
            x== 9&&y== 6||
            x== 9&&y== 7
      )
    {


        return 0 ;

    }
    else

        return 1 ;



}




void  print_sudoku(int arr[9][9])
{
    char flag1=0, flag2 =0 ;
    for (int i = 0; i < 9; i++)
    {

        change_text(11) ;



        printf("\n\n\n");
        for (int j = 0; j < 9; j++)

        {


            if (i==3&&flag1==0)
            {
                int c=13, b=0;

                while (c--)
                {
                    if(b==0)
                    {
                        printf("\t\t\t\t\t\t%10s","||") ;
                        b++ ;
                    }
                    else
                    {
                        printf("%10s","=========") ;


                    }

                }
                flag1=1 ;
                printf("\n\n\n") ;


            }
            if (i==6&&flag2==0)
            {
                int c=13, b=0;

                while (c--)
                {
                    if(b==0)
                    {
                        printf("\t\t\t\t\t\t%10s","||") ;
                        b++ ;
                    }
                    else
                    {
                        printf("%10s","=========") ;


                    }

                }
                flag2=1 ;

                printf("\n\n\n") ;
            }



            if(j==0)
            {
                change_text(3) ;

                printf("\t\t\t\t\t\t%10s","||") ;
            }



            if(j == 3 || j == 6 )
            {
                change_text(3) ;

                printf("%10s","||") ;

            }


            if(arr[i][j]== -1)
            {
                change_text(14) ;

                printf("%10s","..." ) ;


            }
            else
            {
                change_text(4) ;


                printf("%10d", arr[i][j]);



            }

            if(j==8)
            {
                change_text(3) ;


                printf("%10s","||") ;
            }
        }




        printf("\n");
    }
    printf("\n\n\n");

    for(int i=0 ; i<13 ; i++)
    {


        if(i==0)
        {

            printf("\t\t\t\t\t\t%10c",' ') ;

        }
        else
        {
            printf("%10s","=========") ;


        }
    }
    printf("\n") ;

}



void take_number (int arr[9][9] )
{

    int x, y, num ;
    printf("Enter number with x , y , num :  ") ;


    scanf("%d%d%d", &x,&y,&num)  ;

    if(check_primary_numbers(x, y) )
    {
        if(check_row(arr, x-1, y-1, num)==0 && check_column(arr, x-1, y-1, num)==0)
        {
            printf("this number will already be in this row and this column\n") ;
            choose_opertion(arr) ;
        }

        else if(check_row(arr, x-1, y-1, num)==0)
        {

            printf("this number will already be in this row \n") ;
            choose_opertion(arr) ;

        }
        else if(check_column(arr, x-1, y-1, num)==0)
        {
            printf("this number will already be in this column \n") ;
            choose_opertion(arr) ;

        }


        else
        {

            arr[x-1][y-1] = num ;
            system("cls");
            start() ;
            print_sudoku(arr) ;
            choose_opertion(arr) ;

        }




    }
    else
    {
        printf("you can't edit in this number\n") ;


    }



}



int check_row(int arr[9][9],int x, int y, int num)
{


    for(int j = 0 ; j <9 ; j++)
    {

        if(arr[x][j]==num)
        {

            return 0 ;

        }



    }


    return 1 ;

}




int check_column(int arr[9][9],int x, int y, int num)
{


    for(int i = 0 ; i<9 ; i++)
    {

        if(arr[i][y]==num)
        {

            return 0;

        }


    }
    return 1 ;



}



void choose_opertion(int arr[9][9])
{
    printf("\n\n") ;
    change_text(7) ;

    printf("choose any opertion: \n") ;
    change_text(11) ;

    printf("-insert/edit -> i \n") ;
    change_text(12) ;

    printf("-exit  -> e \n") ;

    change_text(2) ;

    char choose  ;
    scanf(" %c", &choose) ;
    if(choose=='i')
    {

        take_number(arr) ;

    }
    else if(choose=='e')
    {
        exit(0) ;
    }

    else
    {

        printf("wrong input!, try again \n") ;

        choose_opertion(arr) ;



    }
}


int check_win(int arr[9][9])
{


    for(int i = 0 ; i <9 ; i++)
    {


        for(int j = 0 ; j<9 ; j++)
        {

            if(arr[i][j]==-1)
            {

                return 0  ;
            }




        }
        printf("You win!!\n") ;
        return 1 ;

    }


}


