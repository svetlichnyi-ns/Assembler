#include <stdio.h>
#include <sys/mman.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>

void honest_func1() {
  printf("It's over, Anakin! I have the high ground!\n");
  return;
}

void honest_func2() {
  printf("You underestimate my power!\n");
  return;
}

int hacker_func() {
  void * add1 = &honest_func1; // в переменную add1 типа void * кладём адрес функции honest_func1
  void * add2 = &honest_func2; // в переменную add2 типа void * кладём адрес функции honest_func2
  void * add1_2 = &honest_func1 + 1; // в переменную add1_2 типа void * кладём адрес второго по счёту байта, относящегося к коду функции honest_func1
  size_t page_size = sysconf(_SC_PAGESIZE); // в переменную page_size типа size_t кладём размер страницы в байтах
  int res = mprotect(add1 - (unsigned long) add1 % page_size, page_size, PROT_READ | PROT_WRITE | PROT_EXEC); // адрес add1 должен быть выровнен по границе страницы
  if (res == -1) {
    printf("Memory access violation\n");
    printf("Code error: %d\n", errno);
    return errno;
  } // обработка ошибок при вызове функции mprotect
  *(char*) add1 = 0xeb; // 0xeb -- операционный код безусловного перехода jmp
  *(char*) add1_2 = (char*) &honest_func2 - ((char*) &honest_func1 + 2); // вычисление смещения
  return 0;
}

int main() {
  printf("The results, given by functions before hacking:\n");	
  printf("honest_func1: ");
  honest_func1();
  printf("honest_func2: ");
  honest_func2();
  int result = hacker_func();
  if (result != 0) {
    return errno;
  }
  printf("The results, given by functions after hacking:\n");
  printf("honest_func1: ");
  honest_func1();
  printf("honest_func2: ");
  honest_func2();
  return 0;
}
