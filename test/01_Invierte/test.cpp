#include <climits>
#include "gtest/gtest.h"
#include "../../01_Invierte/fnInvierte.h"
#include "../../Lista/Lista.h"
#include <stdint.h>

TEST(test_01_Invierte, Invertir50) {
    Lista<uint8_t> l;

    for (int i = 0; i < 50; i++)
        l.insertarUltimo(i);

    fnInvierte(&l);

    for (int i = 0; i < 50; i++) {
        EXPECT_EQ(l.getDato(i), 49 - i);
    }
}


TEST(test_01_Invierte, InvertirVacia) {
    Lista<uint8_t> l;
    fnInvierte<uint8_t>(&l);
    EXPECT_EQ(l.esVacia(), true);
}