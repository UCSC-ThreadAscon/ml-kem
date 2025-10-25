#include "main.h"
#include "tight_loop.h"
#include "independent_variables.h"

#include "kem.h"

#include "esp_random.h"

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

  unsigned char pk[MLKEM_PUBLICKEYBYTES];
  unsigned char sk[MLKEM_SECRETKEYBYTES];

  esp_fill_random(pk, sizeof(pk));
  esp_fill_random(sk, sizeof(sk));
  crypto_kem_keypair(pk, sk);

  printf("DONE key pair generation!\n");

  return;
}
