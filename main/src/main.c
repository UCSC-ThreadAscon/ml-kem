#include "main.h"
#include "tight_loop.h"
#include "independent_variables.h"

#include "kem.h"
#include "notrandombytes.h"


#include <stdio.h>
#include <string.h>

const uint8_t canary[8] = {
    0x01, 0x23, 0x45, 0x67, 0x89, 0xAB, 0xCD, 0xEF
};

/* allocate a bit more for all keys and messages and
 * make sure it is not touched by the implementations.
 */
static void write_canary(uint8_t *d) {
    for (size_t i = 0; i < 8; i++) {
        d[i] = canary[i];
    }
}

static int check_canary(const uint8_t *d) {
    for (size_t i = 0; i < 8; i++) {
        if (d[i] != canary[i]) {
            return -1;
        }
    }
    return 0;
}

#if ((DELAY_SERVER || DELAY_CLIENT) && !CONFIG_OPENTHREAD_TIME_SYNC)
#error "You must TURN ON Time Sync for the Delay experiments."
#elif (!(DELAY_SERVER || DELAY_CLIENT) && CONFIG_OPENTHREAD_TIME_SYNC)
#error "You must TURN OFF Time Sync for the Throughput & Packet Loss experiments."
#endif

void app_main(void)
{
  // startMain();

  unsigned char key_a[CRYPTO_BYTES + 16], key_b[CRYPTO_BYTES + 16];
  unsigned char pk[CRYPTO_PUBLICKEYBYTES + 16];
  unsigned char sendb[CRYPTO_CIPHERTEXTBYTES + 16];
  unsigned char sk_a[CRYPTO_SECRETKEYBYTES + 16];

  write_canary(key_a);
  write_canary(key_a + sizeof(key_a) - 8);
  write_canary(key_b);
  write_canary(key_b + sizeof(key_b) - 8);
  write_canary(pk);
  write_canary(pk + sizeof(pk) - 8);
  write_canary(sendb);
  write_canary(sendb + sizeof(sendb) - 8);
  write_canary(sk_a);
  write_canary(sk_a + sizeof(sk_a) - 8);

  printf("DONE\n");

  return;
}
