#include "Esfera.h"
void Esfera::SetColor(unsigned char r, unsigned char v, unsigned char a)
{
	rojo = r;
	verde = v;
	azul = a;
}
void Esfera::SetRadio(float r) {//si me empeño en dejarlo en radio en vez de r 
	radio = r;
	//this->radio = radio;
}
void Esfera::SetPos(float ix, float iy, float iz) {
	x = ix;
	y = iy;
	z = iz;
}
void Esfera::Dibuja()//e solo sirve internamente, desdefuera te pasan la esfera que quieran. se puede pner como metodo. Ya no tienes que poner otra vexz el glutsolidsfere
{
	glColor3ub(rojo, verde, azul);//no necesitas que sea un puntero si no modificas los punteros de la clase. 
	glTranslatef(x, y, 0);
	glutSolidSphere(radio, 20, 20);
	glTranslatef(-x, -y, 0);
}
void Esfera::Mueve()//cambia radio, no hemos cambiadp el de esferea que es este, ha sido el de mundo
{
	radio += 0.01f;
	if (radio > 2)
		radio = 0.5f;
}
float Esfera::GetRadio()
{
	return radio;
}
