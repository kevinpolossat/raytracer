#include "Setting.hh"

Setting*	settings = Setting::getSetting();

Setting::Setting()
{
  _Epsilon		= 0.0001;
  _Depth		= 2;
  _refractionIndex     	= 1.0f;
  _nbTrianglesPerLeaf	= 10;
  _nbJob		= 2000;
  _nbThread		= 1;
  _Sample		= 1;
}

Setting::~Setting()
{
}

Setting*	Setting::getSetting()
{
  static Setting*	settings = new Setting;
  return settings;
}

void		Setting::setEpsilon(float Epsilon)
{
  _Epsilon = Epsilon;
}

float		Setting::Epsilon() const
{
  return _Epsilon;
}

void		Setting::setDepth(uint32_t Depth)
{
  _Depth = Depth;
}

uint32_t	Setting::Depth() const
{
  return _Depth;
}

void		Setting::setSample(uint32_t Sample)
{
  _Sample = Sample;
}

uint32_t	Setting::Sample() const
{
  return _Sample;
}

void		Setting::setEnvRefractionIndex(float n)
{
  _refractionIndex = n;
}

float		Setting::envRefractionIndex() const
{
  return _refractionIndex;
}

void		Setting::setNbTrianglesPerLeaf(int32_t n)
{
  _nbTrianglesPerLeaf = n;
}

int32_t		Setting::nbTrianglesPerLeaf() const
{
  return _nbTrianglesPerLeaf;
}

void		Setting::setNbThread(uint32_t nbThread)
{
  _nbThread = nbThread;
}

uint32_t	Setting::nbThread() const
{
  return _nbThread;
}

void		Setting::setNbJob(uint32_t nbJob)
{
  _nbJob = nbJob;
}

uint32_t	Setting::nbJob() const
{
  return _nbJob;
}
