#ifndef GRN_DAT_CURSOR_FACTORY_HPP_
#define GRN_DAT_CURSOR_FACTORY_HPP_

#include "cursor.hpp"

namespace grn {
namespace dat {

class Trie;

class CursorFactory {
 public:
  static Cursor *open(const Trie &trie,
                      const void *min_ptr, UInt32 min_length,
                      const void *max_ptr, UInt32 max_length,
                      UInt32 offset = 0,
                      UInt32 limit = UINT32_MAX,
                      UInt32 flags = 0);

 private:
  // Disallows copy and assignment.
  CursorFactory(const CursorFactory &);
  CursorFactory &operator=(const CursorFactory &);
};

}  // namespace dat
}  // namespace grn

#endif  // GRN_DAT_CURSOR_FACTORY_HPP_
