#include "StateMachine.hpp"
#include "NOPState.hpp"
#include "PNOState.hpp"
#include "POState.hpp"
#include "PWTState.hpp"
#include <gtest/gtest.h>

TEST(StateMachineTest, InitialStateIsNOP) {
  StateMachine sm(std::make_unique<NOPState>());
  EXPECT_EQ(sm.getCurrentState(), "NOP");
}

TEST(StateMachineTest, TransitionFromNOPToPNO) {
  StateMachine sm(std::make_unique<NOPState>());
  sm.handleEvent("E1");
  EXPECT_EQ(sm.getCurrentState(), "PNO");
}

TEST(StateMachineTest, InvalidEventInNOP) {
  StateMachine sm(std::make_unique<NOPState>());
  sm.handleEvent("E3");
  EXPECT_EQ(sm.getCurrentState(), "NOP");
}

// Adicionar mais testes para outros estados e transições

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
