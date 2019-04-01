#pragma once
#include"glut.h"
class Esfera
{
private:
	float radio;
	float x;
	float y;
	float z;
	unsigned char rojo;
	unsigned char verde;
	unsigned char azul;
public:
	void SetColor(unsigned char r, unsigned char v, unsigned char a);//prototipos, punto y coma SIEMPRE
	void SetRadio(float radio);
	void SetPos(float x, float y, float z);
	float GetX() { return x; }//cambiar
	float GetY() { return y; }
	float GetZ() { return z; }
	void Dibuja();//no necesita argumentos porque dentro de si misma tya tiene todo lo que necesita
	void Mueve();
	float GetRadio();
}; 
