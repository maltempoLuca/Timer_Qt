#include <QDate>
#include "gtest/gtest.h"
#include "../Headers/Date.h"


TEST(DateTest, DefaultConstructorTest) {
    Date date;
    QDate qDate = QDate::currentDate();
    ASSERT_EQ(qDate.day(), date.getDay());
    ASSERT_EQ(qDate.month(), date.getMonth());
    ASSERT_EQ(qDate.year(), date.getYear());
}

TEST(DateTest, NonDefaultConstructorTest) {
    Date date0 = Date(12, 10, 1492);
    Date date1 = Date(24, 4, 1998);
    Date date2 = Date(29, 2, 2020);
    ASSERT_EQ(date0.getFullDate(DMY), "12/10/1492");
    ASSERT_EQ(date0.getDayOfWeekAsString(), "Wednesday");
    ASSERT_EQ(date1.getFullDate(DMY), "24/04/1998");
    ASSERT_EQ(date1.getDayOfWeekAsString(), "Friday");
    ASSERT_EQ(date2.getFullDate(DMY), "29/02/2020");
    ASSERT_EQ(date2.getDayOfWeekAsString(), "Saturday");
}

TEST(DateTest, InsertingInvalidDay) {
    Date date;
    ASSERT_THROW(date.setDay(0), std::invalid_argument);
    ASSERT_THROW(date.setDay(-1), std::invalid_argument);
    ASSERT_THROW(date.setDay(32), std::invalid_argument);
}

TEST(DateTest, InsertingInvalidMonth) {
    Date date;
    ASSERT_THROW(date.setMonth(0), std::invalid_argument);
    ASSERT_THROW(date.setMonth(-1), std::invalid_argument);
}

TEST(DateTest, InsertingInvalidYear) {
    Date date;
    ASSERT_THROW(date.setYear(-1), std::invalid_argument);
}

TEST(DateTest, InsertingInvalidFullDate) {
    Date date;
    ASSERT_THROW(date.setFullDate(29, 2, 1998), std::invalid_argument);  // 1998 is not leap.
    ASSERT_NO_THROW(date.setFullDate(29, 2, 2000));  // 2000 is leap.
}

TEST(DateTest, isLeapYearTest) {
    Date date0 = Date(1, 1, 2016);
    Date date1 = Date(1, 1, 2018);
    ASSERT_TRUE(date0.isLeapYear());
    ASSERT_FALSE(date1.isLeapYear());
}

TEST(DateTest, isLastDayOfMonthTest) {
    Date date;
    date.setFullDate(31, 1, 2016);
    ASSERT_TRUE(date.isLastDayOfMonth());
    date.setFullDate(30, 1, 2016);
    ASSERT_FALSE(date.isLastDayOfMonth());
}

TEST(DateTest, DateFormatTest) {
    Date date;
    ASSERT_NO_THROW(date.setFullDate(24, 4, 1998));
    ASSERT_EQ(date.getFullDate(DMY), "24/04/1998");
    ASSERT_EQ(date.getFullDate(MDY), "04/24/1998");
    ASSERT_EQ(date.getFullDate(YMD), "1998/04/24");
    ASSERT_EQ(date.getFullDate(ReducedFormat), "24/04");
}
