#pragma once

#include "ModelTechnique.h"

class AnimatedModelTechnique : public ModelTechnique 
{
public:
    static const uint MAX_BONES = 100;

    AnimatedModelTechnique();
	/**
	* Funkcja inicjalizująca shadery służace do wyświetlania modeli z animacją szkieletową.
	*/
    virtual bool Init();

	/**
	* Funkcja przekazująca do shaderów transformacje danej kości.
	*/
	void SetBoneTransform(uint Index, const Matrix4f& Transform);
private:
    GLuint m_boneLocation[MAX_BONES];
};
