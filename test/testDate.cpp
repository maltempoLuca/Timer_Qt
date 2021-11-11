#include <QDate>
#include "gtest/gtest.h"
#include "../Headers/Date.h"


TEST(DateTest, DefaultConstructorTest) {
    Date date;
    QDate qDate = QDate::currentDate();;
    ASSERT_EQ(qDate.day(), date.getDay());
    ASSERT_EQ(qDate.month(), date.getMonth());
    ASSERT_EQ(qDate.year(), date.getYear());
}

TEST(DateTest, NonDefaultConstructorTEST) {
    Date date0 = Date(12, 10, 1492);
    Date date1 = Date(24, 4, 1998);
    Date date2 = Date(29, 2, 2020);
    ASSERT_EQ(date0.getFullDate(), "12/10/1492");
    ASSERT_EQ(date0.gatDayOfWeekAsString(), "Wednesday");
    ASSERT_EQ(date1.getFullDate(), "24/4/1998");
    ASSERT_EQ(date1.gatDayOfWeekAsString(), "Friday");
    ASSERT_EQ(date2.getFullDate(), "29/2/2020");
    ASSERT_EQ(date2.gatDayOfWeekAsString(), "Saturday");
}

TEST(DateTest, InsertingInvalidDayMonthYear) {
    Date date;
    ASSERT_THROW(date.setDay(0), std::invalid_argument);
    ASSERT_THROW(date.setDay(-1), std::invalid_argument);
    ASSERT_THROW(date.setDay(32), std::invalid_argument);
    ASSERT_THROW(date.setMonth(0), std::invalid_argument);
    ASSERT_THROW(date.setMonth(-1), std::invalid_argument);
    ASSERT_THROW(date.setYear(-1), std::invalid_argument);
}

TEST(DateTest, InsertingInvalidFullDate) {
    Date date;
    date.setFullDate(29, 2, 1998);  // 1998 is not leap.
    ASSERT_NE(date.getFullDate(), "29/2/1998");
    date.setFullDate(29, 2, 2000);  // 2000 is leap.
    ASSERT_EQ(date.getFullDate(), "29/2/2000");
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
    date.setFullDate(24, 4, 1998);
    date.setDateFormat(DMY);
    ASSERT_EQ(date.getFullDate(), "24/4/1998");
    date.setDateFormat(MDY);
    ASSERT_EQ(date.getFullDate(), "4/24/1998");
    date.setDateFormat(YMD);
    ASSERT_EQ(date.getFullDate(), "1998/4/24");
    date.setDateFormat(ReducedFormat);
    ASSERT_EQ(date.getFullDate(), "24/4");
}
