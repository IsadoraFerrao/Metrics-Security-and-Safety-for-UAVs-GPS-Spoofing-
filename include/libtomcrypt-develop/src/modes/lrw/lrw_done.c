/* LibTomCrypt, modular cryptographic library -- Tom St Denis
 *
 * LibTomCrypt is a library that provides various cryptographic
 * algorithms in a highly modular and flexible manner.
 *
 * The library is free for all purposes without any express
 * guarantee it works.
 */
#include "tomcrypt_private.h"

/**
   @file lrw_done.c
   LRW_MODE implementation, Free resources, Tom St Denis
*/

#ifdef LTC_LRW_MODE

/**
  Terminate a LRW state
  @param lrw   The state to terminate
  @return CRYPT_OK if successful
*/
int lrw_done(symmetric_LRW *lrw)
{
   int err;

   LTC_ARGCHK(lrw != NULL);

   if ((err = cipher_is_valid(lrw->cipher)) != CRYPT_OK) {
      return err;
   }
   cipher_descriptor[lrw->cipher].done(&lrw->key);

   return CRYPT_OK;
}

#endif
/* ref:         HEAD -> develop */
/* git commit:  e8afa13d5c19d2757ff56537d34802c1dad2c507 */
/* commit time: 2019-04-10 17:05:59 +0200 */
