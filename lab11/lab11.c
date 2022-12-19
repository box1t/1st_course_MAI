#include <stdio.h>
#include <assert.h>

typedef enum{
 s0,
 s1,
 s2,
 s3,
 s4

}status;

int check_emptiness(char c){
  if (c == ' ')
    return 1;
  else
    return 0;

}

void test_check_emptiness(){
    char c=' ';
    assert(check_emptiness(c)==1);
    c='r';
    assert(check_emptiness(c)==0);
    c=EOF;
    assert(check_emptiness(c)==0);

}

int check_comma(char c){
   if ( c == ',')
    return 1;
   else
    return 0;
}

void test_check_comma(){
   char c=',';
    assert(check_comma(c)==1);
    c='r';
    assert(check_comma(c)==0);
    c=EOF;
    assert(check_comma(c)==0);
}

int check_tabulation(char c){
   if (c == '\t')
    return 1;
   else
    return 0;
}

void test_check_tabulation(){
    char c='\t';
    assert(check_tabulation(c)==1);
    c='r';
    assert(check_tabulation(c)==0);
    c=EOF;
    assert(check_tabulation(c)==0);
}

int check_new_string(char c){
   if (c == '\n')
    return 1;
   else
    return 0;
}

void test_check_new_string(){
    char c='\n';
    assert(check_new_string(c)==1);
    c='\t';
    assert(check_new_string(c)==0);
    c=EOF;
    assert(check_new_string(c)==0);
}

int check_num_10(char c ){
   if(c >= '0'&&c <= '9')
    return 1;
   else
    return 0;
}

int check_sign(char c){
    if(c == '+' || c == '-')
        return 1;
    else
        return 0;
}

void test_check_num_10(){
    char c='0';
    assert(check_num_10(c)==1);
     c='1';
    assert(check_num_10(c)==1);
     c='2';
    assert(check_num_10(c)==1);
     c='3';
    assert(check_num_10(c)==1);
     c='4';
    assert(check_num_10(c)==1);
     c='5';
    assert(check_num_10(c)==1);
     c='6';
    assert(check_num_10(c)==1);
     c='7';
    assert(check_num_10(c)==1);
     c='8';
    assert(check_num_10(c)==1);
    c='9';
    assert(check_num_10(c)==1);
    c='\t';
    assert(check_num_10(c)==0);
    c=EOF;
    assert(check_num_10(c)==0);
}

void test_check_sign(){
    char c='+';
    assert(check_sign(c)==1);
     c='-';
    assert(check_sign(c)==1);
     c='r';
    assert(check_sign(c)==0);
     c=EOF;
    assert(check_sign(c)==0);
}
int numbers (char a, char b){
    if( check_num_10(a) && check_num_10(b) ){

    switch(a){
        case '1':
            printf("dix");
        break;
        case '2':
            printf("vingt");
        break;
        case '3':
            printf("trente");
        break;
        case '4':
            printf("quarante");
        break;
        case '5':
            printf("cinquante");
        break;
        case '6':
            printf("soixante");
        break;
        case '7':
            printf("soixante-");
        break;
        default:
            return 0;
        break;
    }

    switch(b){
        case '0':
            if (a == '7')
                printf("dix\n");
            else
                printf("\n");
        break;
        case '1':
            if (a == '7')
                printf("et-onze\n");
            else
                printf(" et un\n");
        break;
        case '2':
            if (a == '7')
                printf("douze\n");
            else
                printf("-deux\n");
        break;
        case '3':
            if (a == '7')
                printf("treize'\n");
            else
                printf("-trois'\n");
        break;
        case '4':
            if (a == '7')
                printf("quatorze\n");
            else
                printf("-quatre\n");
        break;
        case '5':
            if (a == '7')
                printf("quinze\n");
            else
                printf("-cinq\n");
        break;
        case '6':
            if (a == '7')
                printf("seize\n");
            else
                printf("-six\n");
        break;
        case '7':
            if (a == '7')
                printf("dix-sept\n");
            else
                printf("-sept\n");
        break;
        case '8':
                printf("-huit\n");
        break;
        case '9':
                printf("-neuf\n");
        break;
        default:
            return 0;
        break;
    }

    return 1;
    }

    else{
        return 0;
    }
}

void test_numbers(){
    char a='4',b='0';
    assert(numbers(a,b)==1);
     a='r',b='8';
    assert(numbers(a,b)==0);
    a='7',b='3';
    assert(numbers(a,b)==1);
}

int main()
{   status var_status = s0;
    char c=' ', a=' ', b=' ';
    int indicator = 0;

    test_check_emptiness();
    test_check_comma();
    test_check_tabulation();
    test_check_num_10();
    test_check_new_string();
    test_check_sign();

    while( (c=getchar() ) != EOF ){ // пока не кончится входной поток, будем считывать знаки
           switch(var_status){
////////////////////////////////////////
           case s0:
            if ( check_emptiness(c) || check_new_string(c) || check_tabulation(c) || check_comma(c) ){
                    var_status = s1;    // если выполняется одна из функций, идём к s1
            }
            break;
////////////////////////////////////////
           case s1:
            if ( check_num_10(c) && c != '0' && c != '8' ){
                a = c;   // если 'c' != одной из границ, то число десятков = 'а', идём к s2
                var_status = s2;
                indicator = 0;

            }
            else if ( check_num_10(c) && (c=='0' || c=='8') ){ // если 'c' = одной из границ десятков, идём к s0
                var_status = s0;
                indicator = 0;
            }
            else if ( check_sign(c) && indicator == 0 ){ // если проверяем знак и индикатор = '0'', то индикатор = '1'
                indicator = 1;
            }
            else if ( check_sign(c) && indicator == 1 ){ // если проверяем знак и индикатор = '1', то идём к s0 и индикатор = '0'
                var_status = s0;
                indicator = 0;
            }
            else if ( check_emptiness(c) || check_new_string(c) || check_tabulation(c) || check_comma(c) ){
                indicator = 0; // если выполняется одна из функций, индикатор = '0'
            }
            else {
                var_status = s0; // иначе состояние s0, индикатор = '0'
                indicator = 0;
            }
            break;
////////////////////////////////////////
           case s2:
            if ( check_num_10(c) && !(a == '1' && c < '7') && !(a == '7' && c > '7') ){
                    b = c; // если (а != 1 и с >= '7') и (a != 7 и c <= '7'), идём в s3
                    var_status = s3;
            }
            else
                var_status = s0;
            break;
////////////////////////////////////////
           case s3:
            if ( check_emptiness(c) || check_new_string(c) || check_tabulation(c) || check_comma(c) ){
                    var_status = s4;   // если выполняется одна из функций, идём к s4, объявляем numbers
                    numbers(a,b);
                    a=' ';
                    b=' ';
            }
            else
                var_status = s0; // иначе s0
            break;
////////////////////////////////////////
           case s4:
            if( check_num_10(c) && c != '0' && c !='8' ){ //  если 'c' != одной из границ, идём к s2
                a = c;
                var_status = s2;
                indicator = 0;

            }
            else if ( check_num_10(c) && (c == '0' || c == '8') ){
                var_status = s0; // если 'c' = одной из границ десятков, идём к s0
                indicator = 0;
            }
            else if ( check_sign(c) && indicator == 0 ){
                indicator = 1;
                var_status = s1;
            }
            else if( check_sign(c) && indicator == 1 ){
                var_status = s0;
                indicator = 0;
            }
            else if ( check_emptiness(c) || check_new_string(c) || check_tabulation(c) || check_comma(c) ){
                indicator = 0;  // если выполняется одна из функций, индикатор = '0', идём к s1
                var_status = s1;
            }
            else{
                indicator = 0; // иначе индикатор = 0, идём к s0
                var_status = s0;
            }
            break;
////////////////////////////////////////
           }
    }

    if (var_status == s3){ // если состояние s3, идём в s4
        numbers(a,b);
        var_status = s4;
    }
    return 0;
}
