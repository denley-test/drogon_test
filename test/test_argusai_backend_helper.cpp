#include "argusai_backend/argusai_backend_helper.h"
#include <gtest/gtest.h>

TEST(ArgusaiBackendHelperTest, add)
{
  ASSERT_EQ(3, ArgusaiBackendHelper::add(1,2));
}
