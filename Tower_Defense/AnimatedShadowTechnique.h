#pragma once

#include <assert.h>
#include "ShadowTechnique.h"

class AnimatedShadowTechnique : public ShadowTechnique
{
public:
	static const uint MAX_BONES = 100;

	AnimatedShadowTechnique();
	~AnimatedShadowTechnique();
	/**
	* Funkcja inicjalizująca shadery służace do wyświetlania cieni animowanych obiektów.
	*/
	virtual bool Init();
	/**
	* Funkcja przekazująca do shaderów transformacje danej kości.
	*/
	void SetBoneTransform(uint Index, const Matrix4f& Transform);
private:
	GLuint m_boneLocation[MAX_BONES];
};

