#include "bs.h"

namespace bookStore {
double Sales_item::avg_price() const {
  if (units_sold)
    return revenue / units_sold;
  else
    return 0;
}
}  // namespace bookStore