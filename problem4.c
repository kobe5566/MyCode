/*
 *Problem4 實戰題  ( Deadline 4/6 )
 *這個實戰題，是一個流程很亂的 code
 *他的流程是：請輸入一個整數 ，程式會判別這個整數和 10 的大小。請將 if else block 中的程式碼，都只用一行function實作。為什麼要出這樣的題目，是因為：
 *只有熟悉使用指標的人，才能將你的 function (main)寫的精簡具有模組化的概念，並且藉由這個code就知道，設計的方式很重要！
 */

#include<stdio.h>

#define STATE_INIT 	  0
#define STATE_PROCESSING  1
#define STATE_END	  2


void state_init(int *state,int *number)
{

    if ( *state == STATE_INIT )
    {

        printf("Please input a integer number, -1 will kill process\n");
        scanf("%d", number);
        *state = STATE_PROCESSING;

    }

}


void state_processing(int *state,int *number)
{


    if ( *number == -1 )
    {
        *state = STATE_END;

        return;
    }

    printf("%s\n", (*number > 10) ? "The number is bigger than 10" :
           "The number is not bigger than 10" );
    printf("-------------------------------------------------\n");
    *state = STATE_INIT;



}


int main()
{

    int state = STATE_INIT;
    int number = 0;

    while ( 1 )
    {

        if ( state == STATE_INIT )
        {
            /*****  將註解區塊整個改成一個 function ********/
            state_init(&state,&number);
            /***********************************************/
        }
        else if ( state == STATE_PROCESSING )
        {

            /************************************************/
            state_processing(&state,&number);

            /************************************************/
        }
        else if ( state == STATE_END )
        {
            break;
        }
    }



}
