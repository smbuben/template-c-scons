/**
 * @Copyright (c) 2015 Stephen M Buben <smbuben@gmail.com>
 * See project LICENSE for details.
 */

#ifndef STATICLIB_H
#define STATICLIB_H

#ifdef __cplusplus
extern "C" {
#endif


/**
 * Return the "Hello, template!" string.
 *
 * @return              The template's hello string.
 */
const char *
Hello(
    void)
__attribute__((visibility("default")));


#ifdef __cplusplus
} /* extern "C" */
#endif

#endif

