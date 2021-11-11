#include <QDate>
#include "gtest/gtest.h"
#include "../Headers/Time.h"


TEST(TimeTest, DefaultConstructorTest) {
    Time time;
    QTime qTime = QTime::currentTime();
    ASSERT_EQ(qTime.second(), time.getSeconds());
    ASSERT_EQ(qTime.minute(), time.getMinutes());
    ASSERT_EQ(qTime.hour(), time.getHours());
}

TEST(TimeTest, NonDefaultConstructorTest) {
    Time time0 = Time(13, 10, 43);
    Time time1 = Time(00, 4, 4);
    Time time2 = Time(18, 2, 59);
    ASSERT_EQ(time0.getFullTime(), "13:10:43");
    ASSERT_EQ(time1.getFullTime(), "00:04:04");
    ASSERT_EQ(time2.getFullTime(), "18:02:59");
}

TEST(TimeTest, InsertingInvalidSecond) {
    Time time;
    ASSERT_THROW(time.setSeconds(-1), std::invalid_argument);
    ASSERT_THROW(time.setSeconds(60), std::invalid_argument);
    ASSERT_THROW(time.setSeconds(125), std::invalid_argument);

}

TEST(TimeTest, InsertingInvalidMinute) {
    Time time;
    ASSERT_THROW(time.setMinutes(-1), std::invalid_argument);
    ASSERT_THROW(time.setMinutes(60), std::invalid_argument);
    ASSERT_THROW(time.setMinutes(125), std::invalid_argument);
}

TEST(TimeTest, InsertingInvalidHour) {
    Time time;
    ASSERT_THROW(time.setHours(-1), std::invalid_argument);
    ASSERT_THROW(time.setHours(24), std::invalid_argument);
    ASSERT_THROW(time.setHours(125), std::invalid_argument);
}

TEST(TimeTest, InsertingInvalidFullTime) {
    Time time;
    time.setFullTime(25, 2, 23);  // 1998 is not leap.
    ASSERT_NE(time.getFullTime(), "25:02:23");
    time.setFullTime(23, 2, 23);  // 2000 is leap.
    ASSERT_EQ(time.getFullTime(), "23:02:23");
}

TEST(TimeTest, TimeFormatTest) {
    Time time;
    time.setFullTime(16, 30, 00);
    time.setTimeFormat(Format12h);
    ASSERT_EQ(time.getFullTime(), "04:30:00 PM");
    time.setTimeFormat(Format24h);
    ASSERT_EQ(time.getFullTime(), "16:30:00");
}