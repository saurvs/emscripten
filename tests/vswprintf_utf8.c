#include <stdio.h>
#include <stdarg.h>
#include <wchar.h>
#include <locale.h>
#include <errno.h>
#include <assert.h>

void test_vswprintf(const wchar_t *format, ...)
{
  wchar_t buffer[256];
  va_list args;
  va_start(args, format);
  int n = vswprintf(buffer, 256, format, args);
  fputws(buffer, stdout);
  va_end(args);
  wprintf(L"number of characters in above string: %d. errno: %d\n", n, errno);
  assert(n == 24);
  assert(errno == 0);
}

int main ()
{
  setlocale(LC_ALL, "");
  test_vswprintf(L"This is a character: %lc.\n", 0xF6 /* Unicode Character 'LATIN SMALL LETTER O WITH DIAERESIS' (U+00F6): http://www.fileformat.info/info/unicode/char/00f6/index.htm */);
  return 0;
}
