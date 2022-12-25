#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

typedef unsigned long long set;

bool is_separator(int sym) {
     return (sym == ' ' || sym == '\t' || sym == '\n');
     }

void test_is_separator() {
    assert(is_separator(' ') == 1);
    assert(is_separator('\t') == 1);
    assert(is_separator('\n') == 1);
}

int letter_to_int(int sym) {
     if (sym >= 'a' && sym <= 'z')
         return sym - 'a';
     if (sym >= 'A' && sym <= 'Z')
         return sym - 'A';
     else
       return -1;
 }

set letter_to_set(int sym) {
     int ind = letter_to_int(sym);
     return (1U) << ind;
     }

void check_letters() {
     int c;
     set all_letters = 0;
     set vowel_letters = letter_to_set('A') | letter_to_set('E') | letter_to_set('I') | letter_to_set('O') | letter_to_set('U') | letter_to_set('Y');
     while (1) {
         c = getchar();
         if (is_separator(c)) {
             continue;
         } else if (c == EOF) {
             if (((all_letters & vowel_letters) == vowel_letters)) {
                 printf("\nAll vowel letters are in the line. \n");
             } else {
                 printf("\nNot all vowel letters are in the line.\n");
             }
             break;
         } else {
             all_letters = all_letters | letter_to_set(c);
         }
     }
 }

 int main() {
     test_is_separator();
     check_letters();
     return 0;
 }
