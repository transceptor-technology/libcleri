/*
 * token.h - cleri token element. note that one single char will parse
 *           slightly faster compared to tokens containing more characters.
 *           (be careful a token should not match the keyword regular
 *           expression)
 *
 * author       : Jeroen van der Heijden
 * email        : jeroen@transceptor.technology
 * copyright    : 2016, Transceptor Technology
 *
 * changes
 *  - initial version, 08-03-2016
 *  - refactoring, 17-06-2017
 */
#ifndef CLERI_TOKEN_H_
#define CLERI_TOKEN_H_

#include <stddef.h>
#include <inttypes.h>
#include <cleri/object.h>

typedef struct cleri_object_s cleri_object_t;

typedef struct cleri_token_s
{
    uint32_t gid;
    const char * token;
    size_t len;
} cleri_token_t;

cleri_object_t * cleri_token(
        uint32_t gid,
        const char * token);

#endif /* CLERI_TOKEN_H_ /*