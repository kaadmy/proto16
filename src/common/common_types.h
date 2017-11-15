
// Unit defines

#define SIZE_BYTE 1
#define SIZE_WORD 2

// Unit translations

#define KBYTE_TO_BYTE(v) (v * 1024)
#define MBYTE_TO_BYTE(v) (v * 1024 * 1024)

// Log levels

typedef enum {
  LOG_LEVEL_DEBUG, // Stuff the user should not need to see
  LOG_LEVEL_INFO, // Stuff the user should see a lot
  LOG_LEVEL_WARNING, // Stuff the user shouldn't need to care about
  LOG_LEVEL_ERROR, // Stuff the user should notice
  LOG_LEVEL_FATAL // Stuff the user will notice
} log_level_t;
