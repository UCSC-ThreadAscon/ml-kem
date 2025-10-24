#include "main.h"
#include "tight_loop.h"
#include "independent_variables.h"

// NOTE: `mlkem` must NOT be wrriten in quotes.
#define MLK_CONFIG_API_NAMESPACE_PREFIX mlkem
#define MLK_CONFIG_API_PARAMETER_SET 512
#include "mlkem/mlkem_native.h"

#if ((DELAY_SERVER || DELAY_CLIENT) && !CONFIG_OPENTHREAD_TIME_SYNC)
#error "You must TURN ON Time Sync for the Delay experiments."
#elif (!(DELAY_SERVER || DELAY_CLIENT) && CONFIG_OPENTHREAD_TIME_SYNC)
#error "You must TURN OFF Time Sync for the Throughput & Packet Loss experiments."
#endif

void app_main(void)
{
  startMain();
  return;
}
