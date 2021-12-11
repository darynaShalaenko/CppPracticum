#include <stdio.h>
#include <string.h>

void test_intersection(char *text){
    int i = 0;
    int result = 1;
    char *yes = "так";
    char *no = "ні";
    int counter_b1 = 0, counter_b2 = 0, counter_b3 = 0;
    int remember_this = 0, remember_last = -1;
    char *b1 = "(){}[]";
    for(i = 0; i <strlen(text); i++){
        printf("%c",text[i]);
        if(text[i] == b1[0]){
            remember_this = 0;
            counter_b1 += 1;
        }
        else if(text[i] == b1[1]){
            remember_this = 1;
            counter_b1 -= 1;
        }
        else if(text[i] == b1[2]){
            remember_this = 2;
            counter_b2 += 1;
        }
        else if(text[i] == b1[3]){
            remember_this = 3;
            counter_b2 -= 1;
        }
        else if(text[i] == b1[4]){
            remember_this = 4;
            counter_b3 += 1;
        }
        else if(text[i] == b1[5]){
            remember_this = 5;
            counter_b3 -= 1;
        }
        //printf("\nrt = %d\n",remember_this);
        if(counter_b1 < 0 || counter_b2 < 0 || counter_b3 < 0){
            result = 0;
        }
        if((remember_this == 1 && counter_b1 == 0) && (counter_b2 != 0 || counter_b3 != 0)){
            result = 0;
        }
        if((remember_this == 3 && counter_b2 == 0) && (counter_b1 != 0 || counter_b3 != 0)){
            result = 0;
        }
        if((remember_this == 5 && counter_b3 == 0) && (counter_b1 != 0 || counter_b2 != 0)){
            result = 0;
        }
    }
    if(counter_b1 != 0 || counter_b2 != 0 || counter_b3 != 0){
        result = 0;
    }
    if(result == 1){
        printf("\n%s\n", yes);
    }
    else{
        printf("\n%s\n",no);
    }
}

int main()
{
    char *text1 = "({)}";
    printf("text1: %s\n", text1);
    test_intersection(text1);
    char *text2 = "(){}";
    printf("text2: %s\n", text2);
    test_intersection(text2);
    char *text3 = "adaff{asdad}ads(ads(ads)a)";
    printf("text3: %s\n", text3);
    test_intersection(text3);
    char *text4 = "ada(ff(asdad)ads(ads(ads)a)";
    printf("text3: %s\n", text4);
    test_intersection(text4);
}
