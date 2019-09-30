#include <assert.h>
#include <string.h>
#include "str.h"

void test_strcpy () {
    char first[20] = "e";
    char second[20] = "hello";
    char true_answer[20] = "hello";
    char * our_answer = my_strcpy(first, second);
    assert(!strcmp(true_answer, our_answer));
}

void test_strcat () {
    char first[20] = "e";
    char second[20] = "hello";
    char true_answer[20] = "ehello";
    char * our_answer = my_strcpy(first, second);
    assert(!strcmp(true_answer, our_answer));
}

void test_strcmp () {
    char first[20] = "e";
    char second[20] = "hello";
    assert(my_strcmp(first, second) > 0);
    char first1[20] = "hello";
    char second1[20] = "hello";
    assert(my_strcmp(first1, second1) == 0);
    char first2[20] = "hellow";
    char second2[20] = "h";
    assert(my_strcmp(first2, second2) < 0);

}

void test_strlen () {
    char s1[20] = "hellow";
    assert (my_strlen(s1) == 6);

}
