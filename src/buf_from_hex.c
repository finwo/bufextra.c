#include "finwo/str_extra.h"
#include "tidwall/buf.h"
#include "buf_init.h"
#include "buf_from_hex.h"

struct buf * buf_from_hexn(const char *aHex, size_t bytes) {
  if (!str_isHex(aHex)) return NULL;
  int i;

  struct buf *out = buf_init();
  out->data       = calloc(1, bytes);
  out->cap        = bytes;

  // Parse hex-encoded pub and sig values into ev
  while((i < bytes) && (sscanf(aHex + (i*2), "%2hhx", out->data + i) == 1)) i++;
  out->len = i;

  return out;
}

struct buf * buf_from_hex(const char *aHex) {
  int aLen = strlen(aHex);

  // We're decoding into bytes, we need an even number of hex characters
  if (aLen % 2) return NULL;
  int bLen = (aLen / 2);

  return buf_from_hexn(aHex, bLen);
}
