#include <stdio.h>
#include <stdarg.h>
#include <errno.h>

int sb_fprintf(FILE *fp, const char *fmt, ...)
{
  va_list ap;
  va_start(ap, fmt);
  int ret = 0;
  do {
    errno = 0;
    ret = vfprintf(fp, fmt, ap);
  } while (errno == EINTR);
  return ret;
}
