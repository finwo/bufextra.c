#include "tidwall/buf.h"
#include "buf_init.h"

struct buf * buf_init() {
  return calloc(1, sizeof(struct buf));
}
