#ifndef		__SETTING_HH__
#define		__SETTING_HH__

#include	<cstdint>

class Setting
{
public:
  static Setting*	getSetting();

  void			setEpsilon(float Epsilon);
  float			Epsilon() const;
  
  void			setDepth(uint32_t Depth);
  uint32_t     	        Depth() const;
  
  void			setSample(uint32_t Sample);
  uint32_t     		Sample() const;

  void			setEnvRefractionIndex(float n);
  float			envRefractionIndex() const;

  void			setNbTrianglesPerLeaf(int32_t n);
  int32_t		nbTrianglesPerLeaf() const;

  void			setNbThread(uint32_t nbThread);
  uint32_t		nbThread() const;

  void			setNbJob(uint32_t nbJob);
  uint32_t		nbJob() const;
  
private:
  Setting();
  ~Setting();

  float			_Epsilon;
  float			_refractionIndex;
  uint32_t		_Depth;
  uint32_t		_Sample;
  int32_t		_nbTrianglesPerLeaf;
  uint32_t		_nbThread;
  uint32_t		_nbJob;
};

extern Setting*		settings;

#endif		/* __SETTING_HH__ */
