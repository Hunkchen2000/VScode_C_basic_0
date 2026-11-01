#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#define SLEN 40
#define LIM 5
void array_test(int (*ptr)[2]);
int main(void)
{

    int array[4][2]={{11,27},
				          	 {35,41},
					           {52,64},
					           {70,80}};
					 
	  char name[4][20]={"hunkchen",
					             "2000",
					             "California",
	                      "American"};
    const char *mytelents[5]={"hunkchen2000@gmail",
                              "California",
                              "I was lived in cuvery city",
                              "I was expecting ptr to be",
                              " It is a pointer to an array of 10 elements"
                            };
                                
                                
    const char hnkchen2000[5][80]={"ABCDEFGHIJKLM",
                                  "Such pointer can be used to point to a 2D array",
                                  "I was lived in cuvery city",
                                  "I was expecting ptr to be",
                                  "It is a pointer to an array of 10 elements"
                                };    

   char Pokercards[52][20]={"Piques_1"  ,"COEURS_1"  ,"TREFLES_1"   ,"CARREAUX_1",
                            "Piques_2"  ,"COEURS_2"  ,"TREFLES_2"   ,"CARREAUX_2",
                            "Piques_3"  ,"COEURS_3"  ,"TREFLES_3"   ,"CARREAUX_3",
                            "Piques_4"  ,"COEURS_4"  ,"TREFLES_4"   ,"CARREAUX_4",
                            "Piques_5"  ,"COEURS_5"  ,"TREFLES_5"   ,"CARREAUX_5",
                            "Piques_6"  ,"COEURS_6"  ,"TREFLES_6"   ,"CARREAUX_6",
                            "Piques_7"  ,"COEURS_7"  ,"TREFLES_7"   ,"CARREAUX_7",
                            "Piques_8"  ,"COEURS_7"  ,"TREFLES_8"   ,"CARREAUX_8",
                            "Piques_9"  ,"COEURS_9"  ,"TREFLES_9"   ,"CARREAUX_9",
                            "Piques_10" ,"COEURS_10" ,"TREFLES_10"  ,"CARREAUX_10",
                            "Piques_11" ,"COEURS_11" ,"TREFLES_11"  ,"CARREAUX_11",
                            "Piques_12" ,"COEURS_12" ,"TREFLES_12"  ,"CARREAUX_12",
						                "Piques_13" ,"COEURS_13" ,"TREFLES_13"  ,"CARREAUX_13"};   

//上面有兩種寫法~~~一個用指標的記憶體位置不需要寫Col,另一個則是寫上[ROW][]                         
                                
     int (*ptr)[2]=array;	
     char (*ptrchar)[20]=name;
    //顯示整個字串~~//
      printf("%s\n", mytelents[0]); 
      printf("%s\n", mytelents[1]);
      printf("%s\n", mytelents[2]); 
      printf("%s\n", mytelents[3]); 
      printf("%s\n", mytelents[4]); 
       
//        //~~~顯示其中一個字元//
       
//        for(int x=0;x<=5;x++)
//        printf("%c", mytelents[0][x]); 
//  //==================================================================//
//      //顯示整個字串~~//
         printf("%s\n", hnkchen2000[0]); 
         printf("%s\n", hnkchen2000[1]);
         printf("%s\n", hnkchen2000[2]); 
         printf("%s\n", hnkchen2000[3]); 
         printf("%s\n", hnkchen2000[4]); 
         //~~~顯示其中一個字元//
//        for(int x=0;x<=5;x++)
//        printf("%c", hnkchen2000[0][x]); 

     printf("=Pokercards ~~%s\n", Pokercards[0]); 
     printf("=Pokercards ~~%s\n", Pokercards[1]); 
     printf("=Pokercards ~~%s\n", Pokercards[2]); 
     printf("=Pokercards ~~%s\n", Pokercards[3]); 
     printf("=Pokercards ~~%s\n", Pokercards[4]); 
     printf("=Pokercards ~~%s\n", Pokercards[5]);
     printf("=Pokercards ~~%s\n", Pokercards[6]);  
     printf("%s\n",ptrchar[0]);
     printf("%s\n",ptrchar[1]);	
     printf("%s\n",ptrchar[2]);
     printf("%s\n",ptrchar[3]);			  
     array_test(ptr);

	return 0;
}
void array_test(int (*ptr)[2])
{
   printf("array ptr *(*(ptr+2)+1)==%d\n",ptr[2][1]);	
   printf("array ptr *(*(ptr+2)+1)==%d\n",*(*(ptr+0)+0));
   printf("array ptr *(*(ptr+2)+1)==%d\n",*(*(ptr+1)+0));
   printf("array ptr *(*(ptr+2)+1)==%d\n",*(*(ptr+2)+0));
   printf("array ptr *(*(ptr+2)+1)==%d\n",*(*(ptr+3)+0));
}
