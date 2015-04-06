#include<stdio.h>



void chage_num(int *num,const int source){

	
	*num = source;


}





int main(){ 
	
	int number = 10;
	/* 怎麼樣寫一個 function 將 number 改成你想要改的值？ */


	//change_num(&number,8);  







	/* 請用自己的想法說明下面這段 code 的意思 */
	









	char *str = "hello world";  /*char  (*str) 因為是宣告,所以*看為指標,str為指標變數,指向為char
				      因為字串為連續的字元資料結構,所以只要宣告出字串的的第一個位址,就可以存字串
				      效果同陣列的宣告原理char str[] = "hello world";*/


	
	while ( *str ) { 		
		printf("%c\n", *str++);	  
	}				/*此段敘述功能為印出字串,因為一個完整的字串會在最後添加'\0',其ASCII值為0
					  *str此時*不是宣告所以是取值運算子,當印出str*後,str++就會跳到下一位了
					str+0 str+1  str+2   因為char大小為1byte, str++後會將指標位址+1byte
					2000  2001   2002  			
						

					*(str+0) *(str+1) *(str+2)
					str[0]    str[1]   str[2]
							*/
	
	
	/* 下面這段 code ， str2 是一個指向 char 的指標
	 * 他只向了字串 "hello world" 的第一個位址
	 * 在這裡 "hello world" 會被分配在 .text 段位，
	 * 當作是一個 const 型別的唯讀字串，不能進行任何修改
	 * 但是 pointer to char : str2 卻可以一直移動
	 */

	char *str2 = "hello world";
	int i = 0;
	while ( i < 100 ){ 
		printf("%c\n", *str2++);
	}
	return 0;

}











