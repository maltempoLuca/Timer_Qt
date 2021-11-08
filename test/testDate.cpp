#include <QDate>
#include "gtest/gtest.h"
#include "../Headers/Date.h"

#define ASSERT_EXCEPTION(TRY_BLOCK, EXCEPTION_TYPE, MESSAGE){             \
    try                                                                   \
    {                                                                     \
        TRY_BLOCK                                                         \
        FAIL() << "exception '" << MESSAGE << "' not thrown at all!";     \
    }                                                                     \
    catch( const EXCEPTION_TYPE& e )                                      \
    {                                                                     \
        ASSERT_STREQ( MESSAGE, e.what() )                                 \
            << " exception message is incorrect. Expected the following " \
               "message:\n\n"                                             \
            << MESSAGE << "\n";                                           \
    }                                                                     \
    catch( ... )                                                          \
    {                                                                     \
        FAIL() << "exception '" << MESSAGE                                \
               << "' not thrown with expected type '" << #EXCEPTION_TYPE  \
               << "'!";                                                   \
    }                                                                     \
}

TEST(DateTest, DefaultConstructor) {
    Date date;
    QDate qDate = QDate::currentDate();;
    ASSERT_EQ(qDate.day(), date.getDay());
    ASSERT_EQ(qDate.dayOfWeek() - 1, date.getDayOfWeek());
    ASSERT_EQ(qDate.month(), date.getMonth());
    ASSERT_EQ(qDate.year(), date.getYear());
}

TEST(DateTest, InsertingWrongDay) {
    Date date;
    ASSERT_EXCEPTION(date.setDay(0);, std::invalid_argument, "Invalid day");
}


