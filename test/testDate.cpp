#include <QDate>
#include "gtest/gtest.h"

#include "../Headers/Date.h"

TEST(Date, DefaultConstructor) {
    Date date;
    QDate qDate = QDate::currentDate();;
    ASSERT_EQ(qDate.day(), date.getDay());
    ASSERT_EQ(qDate.dayOfWeek() - 1, date.getDayOfWeek());
    ASSERT_EQ(qDate.month(), date.getMonth());
    ASSERT_EQ(qDate.year(), date.getYear());
}

TEST(Date, InsertWringValue) {
    Date date;
    QDate qDate = QDate::currentDate();;
    ASSERT_EQ(qDate.day(), date.getDay());
    ASSERT_EQ(qDate.dayOfWeek() - 1, date.getDayOfWeek());
    ASSERT_EQ(qDate.month(), date.getMonth());
    ASSERT_EQ(qDate.year(), date.getYear());
}


