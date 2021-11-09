#include <QDate>
#include "gtest/gtest.h"
#include "../Headers/Date.h"

#define ASSERT_EXCEPTION(TRY_BLOCK, EXCEPTION_TYPE, MESSAGE){             \
    try                                                                   \
    {                                                                     \
        TRY_BLOCK;                                                        \
        FAIL() << "exception '" << MESSAGE << "' not thrown at all!";     \
    }                                                                     \
    catch( const EXCEPTION_TYPE& e )                                      \
    {                                                                     \
        ASSERT_STREQ( MESSAGE, e.what() )                                 \
            << " exception message is incorrect. Expected the following " \
               "message:\n\n"                                             \
            << MESSAGE << "\n";                                           \
    }                                                                     \
    catch(...)                                                            \
    {                                                                     \
        FAIL() << "exception '" << MESSAGE                                \
               << "' not thrown with expected type '" << #EXCEPTION_TYPE  \
               << "'!";                                                   \
    }                                                                     \
}

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
    ASSERT_EXCEPTION(date.setDay(0), std::invalid_argument, "Invalid day");
    ASSERT_EXCEPTION(date.setDay(-1), std::invalid_argument, "Invalid day");
    ASSERT_EXCEPTION(date.setDay(32), std::invalid_argument, "Invalid day");
    ASSERT_EXCEPTION(date.setMonth(0), std::invalid_argument, "Invalid month");
    ASSERT_EXCEPTION(date.setMonth(-1), std::invalid_argument, "Invalid month");
    ASSERT_EXCEPTION(date.setYear(-1), std::invalid_argument, "Invalid year");
}

TEST(DateTest, isLeapYearTest) {
    Date date;
    date.setFullDate(1, 1, 2016);
    ASSERT_TRUE(date.getIsLeapYear());
    date.setFullDate(1, 1, 2016);
    ASSERT_TRUE(date.getIsLeapYear());
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
