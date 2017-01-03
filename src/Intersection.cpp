#include "Intersection.hh"

Intersection::Intersection()
{
  hitDist = std::numeric_limits<float>::max();
  material = 0;
}

Intersection::~Intersection()
{

}
