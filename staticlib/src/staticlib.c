/**
 * @Copyright (c) 2015 Stephen M Buben <smbuben@gmail.com>
 * See project LICENSE for details.
 */

#include <staticlib.h>

static const char * const HelloString = "Hello, template!";

const char *
Hello(
    void)
{
    return HelloString;
}

