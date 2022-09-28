
#include <stdio.h>
#include <stdlib.h>
#include "operations.h"
#include "design.h"


int main()
{

    start() ;
    char firts_print= 0 ;
    int arr[9][9]  ;

    init_arr(arr) ;

    defualt_numbers(arr) ;
    while (1)
    {
        check_win(arr) ;
        if(firts_print==0)
        {
            print_sudoku(arr) ;

        }
        firts_print=1 ;

        choose_opertion(arr) ;
        check_win(arr) ;

    }

    return 0;
}
