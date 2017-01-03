//
// Noise.hh for Noise.hh in /home/poloss_k/epitech/Infographie/gfx_raytracer2
//
// Made by kevin POLOSSAT
// Login   <poloss_k@epitech.net>
//
// Started on  Thu Apr 28 17:54:13 2016 kevin POLOSSAT
// Last update Wed Jun  8 14:27:50 2016 polossat
//

#ifndef			__NOISE_HH__
#define			__NOISE_HH__

#include		<cstdint>
#include		<cmath>

class Noise
{
public :
  Noise();
  ~Noise();

  static double		turbulence(double x,
				   double y,
				   double z,
				   uint32_t octace,
				   double Hz,
				   double persistence);
  static double		smoothNoise(double x,
				    double y,
				    double z,
				    uint32_t octave,
				    double persistence,
				    double scale,
				    double low,
				    double high);
  static double		marble(double x,
			       double y,
			       double z);
  static double		wood(double x,
			     double y,
			     double z);
  static double		cloud(double x,
			      double y,
			      double z);
  static double		noise(double x,
			      double y,
			      double z);

private:
  static int32_t       	_fastFloor(double x);
  static double		_dotProduct(const int32_t* grad,
				    double x,
				    double y,
				    double z);
  static double		_linearInterpolation(double a,
					     double b,
					     double t);
  static double		_fade(double t);
};

#endif			// __NOISE_HH__
