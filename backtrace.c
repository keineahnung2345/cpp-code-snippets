/**
https://stackoverflow.com/questions/77005/how-to-automatically-generate-a-stacktrace-when-my-program-crashes/77336#77336
Compile with:
`gcc -g -rdynamic backtrace.cpp -o test`

Run with:
`./test`

The output:

Error: signal 11:
./test(_Z7handleri+0x2b)[0x400a31]
/lib/x86_64-linux-gnu/libc.so.6(+0x354b0)[0x7ff8e9cd04b0]
./test(_Z3bazv+0x14)[0x400a8a]
./test(_Z3barv+0x9)[0x400aa9]
./test(_Z3foov+0x9)[0x400ab5]
./test(main+0x23)[0x400adb]
/lib/x86_64-linux-gnu/libc.so.6(__libc_start_main+0xf0)[0x7ff8e9cbb830]
./test(_start+0x29)[0x400939]

**/

#include <stdio.h>
#include <stdlib.h>
#include <execinfo.h>
#include <signal.h> //SIGSEGV
#include <unistd.h> //STDERR_FILENO


void handler(int sig) {
  void *array[10];
  size_t size;

  // get void*'s for all entries on the stack
  size = backtrace(array, 10);

  // print out all the frames to stderr
  fprintf(stderr, "Error: signal %d:\n", sig);
  backtrace_symbols_fd(array, size, STDERR_FILENO);
  exit(1);
}

void baz() {
 int *foo = (int*)-1; // make a bad pointer
  printf("%d\n", *foo);       // causes segfault
}

void bar() { baz(); }
void foo() { bar(); }


int main(int argc, char **argv) {
  signal(SIGSEGV, handler);   // install our handler
  foo(); // this will call foo, bar, and baz.  baz segfaults.
}
