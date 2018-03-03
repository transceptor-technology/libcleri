/*
 * version.h
 *
 *  Created on: Jun 19, 2017
 *      Author: Jeroen van der Heijden <jeroen@transceptor.technology>
 */
#ifndef CLERI_VERSION_H_
#define CLERI_VERSION_H_

#define LIBCLERI_VERSION_MAJOR 0
#define LIBCLERI_VERSION_MINOR 9
#define LIBCLERI_VERSION_PATCH 4

#define LIBCLERI_VERSION "0.9.4"

/* public funtion */
#ifdef __cplusplus
extern "C" {
#endif

const char * cleri_version(void);

#ifdef __cplusplus
}
#endif

#endif /* CLERI_VERSION_H_ */
