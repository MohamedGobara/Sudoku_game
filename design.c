#include "design.h"
#include <time.h>
#include <windows.h>   // WinApi header
#include <stdio.h>

// check if being compiled for windows or posix (linux/bsd/mac)
#ifdef _WIN32
// include minimal windows headers
#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#else
// include posix headers
#include <time.h>
#endif

void milli_sleep(unsigned int milliseconds);
void delay_print(char *str, unsigned int milliseconds);



void delay_print(char *str, unsigned int milliseconds)
{
    for (; *str; str++)
    {
        putchar(*str);
        fflush(stdout);
        milli_sleep(milliseconds);
    }
}

void milli_sleep(unsigned int milliseconds)
{
#ifdef _WIN32
    // use windos Sleep function, sleeps for a number of milliseconds
    Sleep(milliseconds);
#else
    // use posix nanosleep function, sleeps for a number of nanoseconds
    struct timespec ts;
    ts.tv_sec = milliseconds / 1000;
    ts.tv_nsec = (milliseconds % 1000) * 1000000L;
    nanosleep(&ts, NULL);
#endif
}

void change_text(int k)
{
    HANDLE  hConsole;

    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, k);

}

void start_firstTime(void)
{

    change_text(4) ;
    delay_print("\nHow to play Sudoku?\n\n",50);

    change_text(6) ;

    delay_print("The goal of Sudoku is to fill in a 9*9 grid with digits so that each column, row, and 3*3 section"
                " contain the numbers between 1 to 9\nAt the beginning of the game, the 9*9 grid will have some of the squares filled in\nYour job is to use logic to fill in the missing "
                "  digits and complete the grid. Don’t forget, a move is incorrect if:\n\n",10) ;


    delay_print("# Any row contains more than one of the same number from 1 to 9\n",10) ;
    delay_print("# Any column contains more than one of the same number from 1 to 9\n",10) ;
    delay_print("# Any 3*3 grid contains more than one of the same number from 1 to 9\n",10) ;


    printf("\n\n") ;



}


void seconed_time(void)
{

    change_text(4) ;
    printf("\nHow to play Sudoku?\n\n");

    change_text(6) ;

    printf("The goal of Sudoku is to fill in a 9*9 grid with digits so that each column, row, and 3*3 section"
           " contain the numbers between 1 to 9\nAt the beginning of the game, the 9*9 grid will have some of the squares filled in\nYour job is to use logic to fill in the missing "
           "  digits and complete the grid. Don’t forget, a move is incorrect if:\n\n") ;


    printf("# Any row contains more than one of the same number from 1 to 9\n") ;
    printf("# Any column contains more than one of the same number from 1 to 9\n") ;
    printf("# Any 3*3 grid contains more than one of the same number from 1 to 9\n") ;


    printf("\n\n") ;



}
char first_use = 0 ;

void start(void)
{

    change_text(2) ;
    printf(





        "                                                 dddddddd                                                                                \n"
        "   SSSSSSSSSSSSSSS                               d::::::d                 kkkkkkkk                                          GGGGGGGGGGGGG                                                              \n"
        " SS:::::::::::::::S                              d::::::d                 k::::::k                                       GGG::::::::::::G                                                              \n"
        "S:::::SSSSSS::::::S                              d::::::d                 k::::::k                                     GG:::::::::::::::G                                                              \n"
        "S:::::S     SSSSSSS                              d:::::d                  k::::::k                                    G:::::GGGGGGGG::::G                                                              \n"
        "S:::::S            uuuuuu    uuuuuu      ddddddddd:::::d    ooooooooooo    k:::::k    kkkkkkkuuuuuu    uuuuuu        G:::::G       GGGGGG  aaaaaaaaaaaaa      mmmmmmm    mmmmmmm       eeeeeeeeeeee    \n"
        "S:::::S            u::::u    u::::u    dd::::::::::::::d  oo:::::::::::oo  k:::::k   k:::::k u::::u    u::::u       G:::::G                a::::::::::::a   mm:::::::m  m:::::::mm   ee::::::::::::ee  \n"
        " S::::SSSS         u::::u    u::::u   d::::::::::::::::d o:::::::::::::::o k:::::k  k:::::k  u::::u    u::::u       G:::::G                aaaaaaaaa:::::a m::::::::::mm::::::::::m e::::::eeeee:::::ee\n"
        "  SS::::::SSSSS    u::::u    u::::u  d:::::::ddddd:::::d o:::::ooooo:::::o k:::::k k:::::k   u::::u    u::::u       G:::::G    GGGGGGGGGG           a::::a m::::::::::::::::::::::me::::::e     e:::::e\n"
        "    SSS::::::::SS  u::::u    u::::u  d::::::d    d:::::d o::::o     o::::o k::::::k:::::k    u::::u    u::::u       G:::::G    G::::::::G    aaaaaaa:::::a m:::::mmm::::::mmm:::::me:::::::eeeee::::::e\n"
        "       SSSSSS::::S u::::u    u::::u  d:::::d     d:::::d o::::o     o::::o k:::::::::::k     u::::u    u::::u       G:::::G    GGGGG::::G  aa::::::::::::a m::::m   m::::m   m::::me:::::::::::::::::e \n"
        "            S:::::Su::::u    u::::u  d:::::d     d:::::d o::::o     o::::o k:::::::::::k     u::::u    u::::u       G:::::G        G::::G a::::aaaa::::::a m::::m   m::::m   m::::me::::::eeeeeeeeeee  \n"
        "            S:::::Su:::::uuuu:::::u  d:::::d     d:::::d o::::o     o::::o k::::::k:::::k    u:::::uuuu:::::u        G:::::G       G::::Ga::::a    a:::::a m::::m   m::::m   m::::me:::::::e           \n"
        "SSSSSSS     S:::::Su:::::::::::::::uud::::::ddddd::::::ddo:::::ooooo:::::ok::::::k k:::::k   u:::::::::::::::uu       G:::::GGGGGGGG::::Ga::::a    a:::::a m::::m   m::::m   m::::me::::::::e          \n"
        "S::::::SSSSSS:::::S u:::::::::::::::u d:::::::::::::::::do:::::::::::::::ok::::::k  k:::::k   u:::::::::::::::u        GG:::::::::::::::Ga:::::aaaa::::::a m::::m   m::::m   m::::m e::::::::eeeeeeee  \n"
        "S:::::::::::::::SS   uu::::::::uu:::u  d:::::::::ddd::::d oo:::::::::::oo k::::::k   k:::::k   uu::::::::uu:::u          GGG::::::GGG:::G a::::::::::aa:::am::::m   m::::m   m::::m  ee:::::::::::::e  \n"
        " SSSSSSSSSSSSSSS       uuuuuuuu  uuuu   ddddddddd   ddddd   ooooooooooo   kkkkkkkk    kkkkkkk    uuuuuuuu  uuuu             GGGGGG   GGGG  aaaaaaaaaa  aaaammmmmm   mmmmmm   mmmmmm    eeeeeeeeeeeeee  \n"




    )  ;



if(first_use==0){



    start_firstTime() ;
}
else {

    seconed_time() ;

}


    for(int i=0 ; i<13 ; i++)
    {

        change_text(3) ;

        if(i==0)
        {

            printf("\t\t\t\t\t\t%10c",' ') ;

        }
        else
        {
            printf("%10s","=========") ;


        }
    }
first_use =1 ;

}
