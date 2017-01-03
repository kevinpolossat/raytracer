#include <random>
#include "Random.hh"

Random::Random()
{
}

Random::~Random()
{
}

float Random::uniformRand()
{
  static std::default_random_engine generator;
  static std::uniform_real_distribution<float> distribution(0.0,1.0);
  return distribution(generator);
}
