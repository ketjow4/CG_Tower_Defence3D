#ifndef ENGINE_H
#define ENGINE_H

#include "util.h"
#include "BasicLighting.h"
#include "SkinningTechnique.h"
#include "PickingTechnique.h"
#include "PickingTexture.h"


class Engine
{
public:
	Engine();
	~Engine();

	Engine(const Engine &e) {}


	static long long m_startTime;


	static float GetRunningTime();

	static BasicLightingTechnique* light;		//use this shaders for static objects
	static SkinningTechnique* m_pEffect;
	static PickingTexture* m_pickingTexture;
	static PickingTechnique* m_pickingEffect;

	

	BasicLightingTechnique* getLight() { return light; }	
	SkinningTechnique* getEffect() {return m_pEffect;}
	PickingTexture* getpickingTexture() {return m_pickingTexture;}
	PickingTechnique* getpickingEffect() { return m_pickingEffect;}

	//use only this to get something from engine
	static Engine getEngine()
	{
		static Engine en;
		if(en.light == NULL)
		{
			Init();
		}
		return en;
	}

private:
	static void Init();
};





#endif