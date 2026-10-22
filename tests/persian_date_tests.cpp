#include <iostream>
#include <ostream>

#include "persian_date.hpp"
#include "gtest/gtest.h"
using namespace notmot::pd;
class PersianDateTests : public testing::Test {
private:
    PersianDate pd;
protected:
    void SetUp() override {
        pd = PersianDate{};
    };
};

TEST_F(PersianDateTests, isLeapYearJalali) {
    ASSERT_TRUE(PersianDate::isLeapYearJalali(1403));
    ASSERT_FALSE(PersianDate::isLeapYearJalali(1405));
}