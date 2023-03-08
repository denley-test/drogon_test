#include "drogon_test/drogon_helper.h"
#include <gtest/gtest.h>

TEST(DrogonHelperTest, add)
{
  ASSERT_EQ(3, DrogonHelper::add(1,2));
}
