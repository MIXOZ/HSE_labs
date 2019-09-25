#include <stddef.h>

char *my_strcpy (char * restrict s1,
       const char * restrict s2) {
       char *k = s1;
       while ( *s2 != '\0' ) {
            *s1 = *s2;
            s1++;
            s2++;
       }
       return k;
}

char *my_strcat (char * restrict s1,
       const char * restrict s2) {
       char *k = s1;
       while ( *s1 != '\0' )
            s1++;
       while ( *s2 != '\0' ) {
            *s1 = *s2;
            s1++;
            s2++;
       }
       *s1 = '\0';
       return k;
}
      
int  my_strcmp (char * restrict s1,
       const char * restrict s2) {
       while (( *s2 != '\0' ) && ( *s1 != '\0' )) {
            if (*s1 - *s2 != 0) break;
            s1++;
            s2++;
       }
       if (( *s1 != '\0' ) && ( *s2 == '\0' )) return 1;
       if (( *s2 == '\0' ) && ( *s1 != '\0' )) return -1;
       return *s1 - *s2;
}

size_t my_strlen (const char *s) {
       const char * p = s;
       while (*p != '\0'){
            ++p;
       }
       return p - s;
}





























