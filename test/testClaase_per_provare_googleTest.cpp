#include "gtest/gtest.h"

#include "../Headers/claase_per_provare_googleTest.h"

TEST(claase_per_provare_googleTest, costruttore) {
    claase_per_provare_googleTest cappero(5);
    ASSERT_EQ(5, cappero.getNumero());
    ASSERT_NE('PIPPO', cappero.getNumero());
}
