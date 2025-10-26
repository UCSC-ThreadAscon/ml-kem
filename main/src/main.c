#include "main.h"
#include "tight_loop.h"
#include "independent_variables.h"

#define MLK_CONFIG_API_PARAMETER_SET 512
#define MLK_CONFIG_API_NAMESPACE_PREFIX mlkem

#include "mlkem_native.h"
#include "notrandombytes.h"

#define CHECK(x)                                              \
  do                                                          \
  {                                                           \
    int rc;                                                   \
    rc = (x);                                                 \
    if (!rc)                                                  \
    {                                                         \
      fprintf(stderr, "ERROR (%s,%d)\n", __FILE__, __LINE__); \
      return 1;                                               \
    }                                                         \
  } while (0)

void app_main(void)
{
  // startMain();
  return;
}
