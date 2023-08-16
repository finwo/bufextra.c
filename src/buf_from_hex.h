#include "tidwall/buf.h"

struct buf * buf_from_hex(const char *aHex);
struct buf * buf_from_hexn(const char *aHex, size_t bytes);
