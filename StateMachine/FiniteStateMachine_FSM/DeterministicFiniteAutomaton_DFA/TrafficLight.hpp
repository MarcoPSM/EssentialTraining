#ifndef TRAFFICLIGHT_HPP
#define TRAFFICLIGHT_HPP

#include <string>

enum class State { Green, Yellow, Red };

class TrafficLight {
public:
  TrafficLight();
  void changeState();
  std::string getState() const;

private:
  State currentState;
};

#endif // TRAFFICLIGHT_HPP
