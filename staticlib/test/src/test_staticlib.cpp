/**
 * @Copyright (c) 2015 Stephen M Buben <smbuben@gmail.com>
 * See project LICENSE for details.
 */

#include <gtest/gtest.h>
#include <staticlib.h>

namespace {

class TestStaticLib : public ::testing::Test
{
    protected:
        // Initalization for each test.
        //TestStaticLib()
        //{
        //}

        // Clean-up that does not throw exceptions.
        //virtual ~TestStaticLib()
        //{
        //}

        // Extra initialization immediately after constructor.
        //virtual void SetUp()
        //{
        //}

        // Extra clean-up immediately before destructor.
        //virtual void TearDown()
        //{
        //}
};

TEST_F(TestStaticLib, MethodHello)
{
    ASSERT_TRUE(NULL != Hello());
    EXPECT_STREQ("Hello, template!", Hello());
}

} // namespace

