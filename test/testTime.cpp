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
    ASSERT_EQ(time0.getFullTime(Format24h), "13:10:43");
    ASSERT_EQ(time1.getFullTime(Format24h), "00:04:04");
    ASSERT_EQ(time2.getFullTime(Format24h), "18:02:59");
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
    ASSERT_THROW(time.setFullTime(25, 2, 23), std::invalid_argument); // hour < 24
    ASSERT_NO_THROW(time.setFullTime(23, 2, 23));  // time is valid
}

TEST(TimeTest, TimeFormatTest) {
    Time time;
    time.setFullTime(16, 30, 00);
    ASSERT_EQ(time.getFullTime(Format12h), "04:30:00");
    ASSERT_EQ(time.getFullTime(Format24h), "16:30:00");
}