
#pragma once

#include <math.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "version.h"
#include "debug.h"

#include "log.h"

// Unit defines

#define SIZE_BYTE 1
#define SIZE_WORD 2

// Unit translations

#define KBYTE_TO_BYTE(v) (v * 1024)
#define MBYTE_TO_BYTE(v) (v * 1024 * 1024)
