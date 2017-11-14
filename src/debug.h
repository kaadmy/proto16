
#pragma once

#include <assert.h>

// These debug options are only compile-time changes
// All debug macros should be prefixed with DEBUG_

// Debug defines

#define DEBUG_ENABLED

#ifdef DEBUG_ENABLED
#define DEBUG_ASSERT(cond) assert(cond)
#else
#define DEBUG_ASSERT(cond)
#endif
