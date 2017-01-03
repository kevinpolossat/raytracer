//
// Noise.cpp for Noise.cpp in /home/poloss_k/epitech/Infographie/gfx_raytracer2
//
// Made by kevin POLOSSAT
// Login   <poloss_k@epitech.net>
//
// Started on  Thu Apr 28 17:56:11 2016 kevin POLOSSAT
// Last update Wed Jun  8 14:29:26 2016 polossat
//

#include       		"Noise.hh"

static const uint8_t		g_perm[512] =
  {
    151,160,137,91,90,15,131,13,201,95,96,53,194,233,7,225,140,
    36,103,30,69,142,8,99,37,240,21,10,23,190,6,148,247,120,234,
    75,0,26,197,62,94,252,219,203,117,35,11,32,57,177,33,88,237,
    149,56,87,174,20,125,136,171,168,68,175,74,165,71,134,139,
    48,27,166,77,146,158,231,83,111,229,122,60,211,133,230,220,
    105,92,41,55,46,245,40,244,102,143,54,65,25,63,161,1,216,80,
    73,209,76,132,187,208,89,18,169,200,196,135,130,116,188,159,
    86,164,100,109,198,173,186,3,64,52,217,226,250,124,123,5,
    202,38,147,118,126,255,82,85,212,207,206,59,227,47,16,58,17,
    182,189,28,42,223,183,170,213,119,248,152,2,44,154,163,70,
    221,153,101,155,167,43,172,9,129,22,39,253,19,98,108,110,79,
    113,224,232,178,185,112,104,218,246,97,228,251,34,242,193,
    238,210,144,12,191,179,162,241,81,51,145,235,249,14,239,107,
    49,192,214,31,181,199,106,157,184,84,204,176,115,121,50,45,
    127,4,150,254,138,236,205,93,222,114,67,29,24,72,243,141,
    128,195,78,66,215,61,156,180,151,160,137,91,90,15,131,13,201,
    95,96,53,194,233,7,225,140,36,103,30,69,142,8,99,37,240,21,10,
    23,190,6,148,247,120,234,75,0,26,197,62,94,252,219,203,117,35,
    11,32,57,177,33,88,237,149,56,87,174,20,125,136,171,168,68,175,
    74,165,71,134,139,48,27,166,77,146,158,231,83,111,229,122,60,
    211,133,230,220,105,92,41,55,46,245,40,244,102,143,54,65,25,63,
    161,1,216,80,73,209,76,132,187,208,89,18,169,200,196,135,130,116,
    188,159,86,164,100,109,198,173,186,3,64,52,217,226,250,124,123,5,
    202,38,147,118,126,255,82,85,212,207,206,59,227,47,16,58,17,
    182,189,28,42,223,183,170,213,119,248,152,2,44,154,163,70,
    221,153,101,155,167,43,172,9,129,22,39,253,19,98,108,110,79,
    113,224,232,178,185,112,104,218,246,97,228,251,34,242,193,
    238,210,144,12,191,179,162,241,81,51,145,235,249,14,239,107,
    49,192,214,31,181,199,106,157,184,84,204,176,115,121,50,45,
    127,4,150,254,138,236,205,93,222,114,67,29,24,72,243,141,
    128,195,78,66,215,61,156,180
  };

static const int32_t		g_gradient[12][3] =
  {
    {1,1,0},{-1,1,0},{1,-1,0},{-1,-1,0},
    {1,0,1},{-1,0,1},{1,0,-1},{-1,0,-1},
    {0,1,1},{0,-1,1},{0,1,-1},{0,-1,-1}
  };

int32_t				Noise::_fastFloor(double x)
{
  return x > 0 ? (int32_t)x : (int32_t)x - 1;
}

double				Noise::_dotProduct(const int32_t* grad,
						   double x,
						   double y,
						   double z)
{
  if (!grad)
    return 0;
  return grad[0] * x + grad[1] * y + grad[2] * z;
}

double				Noise::_linearInterpolation(double a,
							    double b,
							    double t)
{
  return (1 - t) * a + t * b;
}

double				Noise::_fade(double t)
{
  return t * t * t * (t * (t * 6 - 15) + 10);
}

double				Noise::noise(double x,
					     double y,
					     double z)
{

  //separate deciaml part and fractional part
  int32_t			xI = _fastFloor(x);
  int32_t			yI = _fastFloor(y);
  int32_t			zI = _fastFloor(z);

  x = x - xI;
  y = y - yI;
  z = z - zI;

  // get period on perm size
  xI &= 255;
  yI &= 255;
  zI &= 255;
  // get gradient indice % 12 all over the corner of the cube!
  int32_t			gi000	= g_perm[xI +	g_perm[yI +	g_perm[zI	]]] % 12;
  int32_t			gi001	= g_perm[xI +	g_perm[yI +	g_perm[zI + 1	]]] % 12;
  int32_t			gi010	= g_perm[xI +	g_perm[yI + 1 + g_perm[zI	]]] % 12;
  int32_t			gi011	= g_perm[xI +	g_perm[yI + 1 + g_perm[zI + 1	]]] % 12;
  int32_t			gi100	= g_perm[xI + 1 + g_perm[yI +	g_perm[zI	]]] % 12;
  int32_t			gi101	= g_perm[xI + 1 + g_perm[yI +	g_perm[zI + 1	]]] % 12;
  int32_t			gi110	= g_perm[xI + 1 + g_perm[yI + 1 + g_perm[zI	]]] % 12;
  int32_t			gi111	= g_perm[xI + 1 + g_perm[yI + 1 + g_perm[zI + 1	]]] % 12;

  // dot product to compute contribution from each corner previously computed ...
  double			dot000	= _dotProduct(g_gradient[gi000], x	, y	, z	);
  double			dot100	= _dotProduct(g_gradient[gi100], x - 1	, y	, z	);
  double			dot010	= _dotProduct(g_gradient[gi010], x	, y - 1	, z	);
  double			dot110	= _dotProduct(g_gradient[gi110], x - 1	, y - 1 , z	);
  double			dot001	= _dotProduct(g_gradient[gi001], x	, y	, z - 1	);
  double			dot101	= _dotProduct(g_gradient[gi101], x - 1	, y	, z - 1	);
  double			dot011	= _dotProduct(g_gradient[gi011], x	, y - 1	, z - 1 );
  double			dot111	= _dotProduct(g_gradient[gi111], x - 1	, y - 1	, z - 1	);

  double			u	= _fade(x);
  double			v	= _fade(y);
  double			w	= _fade(z);

  //_linearInterpolation == lerp || mix ...
  double			nx00	= _linearInterpolation(dot000, dot100, u);
  double			nx01	= _linearInterpolation(dot001, dot101, u);
  double			nx10	= _linearInterpolation(dot010, dot110, u);
  double			nx11	= _linearInterpolation(dot011, dot111, u);

  double			nxy0	= _linearInterpolation(nx00, nx10, v);
  double			nxy1	= _linearInterpolation(nx01, nx11, v);

  return _linearInterpolation(nxy0, nxy1, w);
}

double				Noise::smoothNoise(double x,
						   double y,
						   double z,
						   uint32_t octave,
						   double persistence,
						   double scale,
						   double low,
						   double high)
{
  double			tot		= 0;
  double			maxValue	= 0;
  double			Hz		= scale;
  double			Lambda		= 1.f;

  for (uint32_t i = 0; i < octave; ++i) {

    tot		+= Noise::noise(x * Hz, y * Hz, z * Hz) * Lambda;
    maxValue	+= Lambda;
    Lambda	*= persistence;
    Hz		*= 2.f;
  }
  tot /= maxValue;
  tot = tot * (high - low) / 2 + (high + low) / 2;
  return tot;
}

double				Noise::turbulence(double x,
						  double y,
						  double z,
						  uint32_t octave,
						  double Hz,
						  double persistence)
{
  double			tot = 0;
  double			scale = 1.f;
  double			Lambda = persistence;

  for (uint32_t i = 0; i < octave; ++i) {
    tot += Noise::noise(x * scale, y * scale, z * scale) * Lambda;
    scale *= Hz;
    Lambda *= persistence;
  }
  return fabs(tot);
}

Noise::Noise()
{

}

Noise::~Noise()
{

}
