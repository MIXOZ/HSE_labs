#include <assert.h>
#include <string.h>
#include "str.h"

void test_strcpy () {
      char first[] = "e";
      char second[] = "hello";
      char true_answer[] = "hello";
      char * our_answer = my_strcpy(first, second);
      assert(!strcmp(true_answer, our_answer));
      
}

void test_strcat () {
      char first[] = "e";
      char second[] = "hello";
      char true_answer[] = "ehello";
      char * our_answer = my_strcpy(first, second);
      assert(!strcmp(true_answer, our_answer));

}
void test_strcmp () {
      char first[] = "e";
      char second[] = "hello";
      assert(my_strcmp(first, second) == 1);

}
void test_strlen () {
      char s1[] = "hellow";
      assert (my_strlen(s1) == 6);

}
