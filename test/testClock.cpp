#include "gtest/gtest.h"
#include "../Headers/Clock.h"
#include <QDate>
#include <QApplication>

using namespace std;

TEST(ClockTest, DefaultConstructorTest) {
    Clock clock;

    QDate qDate = QDate::currentDate();
    std::string currentDate = clock.getDate();
    std::string currentDay = currentDate.substr(0, 2);
    std::string currentMonth = currentDate.substr(3, 2);
    std::string currentYear = currentDate.substr(6, 4);
    ASSERT_EQ(currentDay, to_string(qDate.day()));
    ASSERT_EQ(currentMonth, to_string(qDate.month()));
    ASSERT_EQ(currentYear, to_string(qDate.year()));

    QTime qTime = QTime::currentTime();
    std::string currentTime = clock.getTime();
    int currentSecond = stoi(currentTime.substr(6, 2));
    ASSERT_NEAR(currentSecond, qTime.second(), 2);
    int currentMinute = stoi(currentTime.substr(3, 2));
    ASSERT_NEAR(currentMinute, qTime.minute(), 1);
    int currentHour = stoi(currentTime.substr(0, 2));
    ASSERT_NEAR(currentHour, qTime.hour(), 1);
}

TEST(ClockTest, SetDateTest) {
    Clock clock;
    clock.setDate(24, 04, 1998);
    std::string clockDate = clock.getDate();
    ASSERT_EQ(clockDate, "24/04/1998");

    clock.setDate(31, 2, 1998);
    ASSERT_NE(clock.getDate(), "31/02/1998");
}

TEST(ClockTest, SetTimeTest) {
    Clock clock;
    clock.setTime(16, 30, 00);
    std::string clockTime = clock.getTime();
    int currentSecond = stoi(clockTime.substr(6, 2));
    ASSERT_NEAR(currentSecond, 00, 2);
    int currentMinute = stoi(clockTime.substr(3, 2));
    ASSERT_NEAR(currentMinute, 30, 1);
    int currentHour = stoi(clockTime.substr(0, 2));
    ASSERT_NEAR(currentHour, 16, 1);

    clock.setTime(26, 61, 00);
    ASSERT_NE(clock.getTime(), "26:61:00");

}