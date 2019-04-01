#pragma once//ya define la clase for ever and ever(solo permite que se defina una vez) SOLO EN .H
#include "glut.h"
#include"esfera.h"//ahora si que tiene que saber lo que es una esfera
class Mundo {
public:
	float x;
	float y;
	float z;
	void RotarOjo();
	Esfera esfera1;//ahora las esferas cuelgan de mundo en vez de de main
	Esfera esfera2;
	void Inicializa();
	void Dibuja();// recordar que no tiene esferas de argumento porque el mundo YA tiene las esferas dentro
	void Mueve();
	void Tecla(unsigned char key);
};
