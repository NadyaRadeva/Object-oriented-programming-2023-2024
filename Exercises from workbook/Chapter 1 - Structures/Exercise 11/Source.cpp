#include<string.h>

void sortGroup(int n, Student** s) {
  for(size_t i = 0; i < n - 1; ++i) {
      int k = i;
      Student* MAX_STUDENT = s[i];
      for(size_t j = i + 1; j < n; ++j) {
          int x = strcmp(s[i]->name, MAX_STUDENT->name);
          if(x > 0 || x == 0 && result(*s[j]) > result(*MAX_STUDENT)) {
              k = j;
              MAX_STUDENT = s[j];
          }
      }
      Student* x;
      x = s[i];
      s[i] = s[k];
      s[k] = x;
  }
}
