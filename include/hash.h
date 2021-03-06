
#ifndef __INCLUDE_HASH__
#define __INCLUDE_HASH__

#include "common.h"

typedef int bucket_t;
typedef voidp hashCookie;

// Collision resolution is linked list.
// - hash_function returns the index (or bucket) where we need to insert thekey
// - compare fucntion compares 2 keys (note that key may be of any type, so,
//   we need compare fucntion. compare retuens 1 when it matches and 0 if keys
//   do not match
// - dump_dunction dumps entire hash table
hashCookie hash_init(bucket_t num_buckets,
                bucket_t (*hash_function)(voidp key, bucket_t num_buckets),
                int (*compare_function)(voidp key, voidp comparewith),
                void (*dump_function)(voidp key, voidp value));

/*
 *  0 : success
 * -1 : failure
 *  1 : Key already exists
 */
int
hash_insert(hashCookie cookie, voidp key, voidp data);

void
hash_remove(hashCookie cookie, voidp key);

voidp
hash_lookup(hashCookie cookie, voidp key);

void
hashtable_dump(hashCookie cookie);

#endif

