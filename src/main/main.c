
#include "common/common.h"

int main(int argc, char **argv) {
  common_log_level(LOG_LEVEL_INFO);
  common_log(LOG_LEVEL_INFO, ENGINE_TITLE " v" ENGINE_VERSION_STRING "\n");
}
