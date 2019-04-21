#ifndef TEST_MENU_H
#define TEST_MENU_H

#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>
#include "../../../domain/seat_list.h"
#include "../../../domain/seat.h"

using namespace testing;

void test(std::map<int, Seat> * seats){
    Seat s(3, false);
    seats->insert(std::pair<int, Seat>(1,s));
}

TEST(TestSeatList, first)
{
    std::map<int, Seat> * seats = new std::map<int, Seat>;
    test(seats);
    std::map<int,Seat>::iterator it = seats->begin();
    ASSERT_FALSE(it->second.isUsed());
    ASSERT_EQ(3,it->second.getId());
}


#endif // TEST_MENU_H
