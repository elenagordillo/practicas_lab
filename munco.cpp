#include"Mundo.h"
#include<math.h>
void Mundo::RotarOjo()//sin parámetros igual que lo esfera (ya pertenecen a mundo)
{
	float d, teta;
	d = sqrt(x*x+y*y+z*z);
	teta = atan2(z,x);
	teta += 0.01;//LAS PUTAS COMASS VAN CON PUNTO Y NO CON COMA

	x = d * (cos(teta));
	z = d * (sin(teta));


}
void Mundo::Inicializa() {

	x = 6;
	y = 1;
	z = 0;

	esfera1.SetColor(200, 0, 0);
	esfera1.SetRadio(1);
	esfera1.SetPos(2, 0, 0);
	esfera2.SetColor(0, 200, 0);
	esfera2.SetRadio(1);
	esfera2.SetPos(3, 0, 0);

}
void Mundo::Dibuja() {
	
	//plano de colores origen l=10
	glBegin(GL_POLYGON);//le doy los vertices del planohorario
		glColor3ub(255, 0, 0);//dice que proximos vertices son de este color 
		glVertex3f(-5.0f, 0.0f, -5.0f);//da este vértice. Vertex=vertice, 3f=3 float->pistas
		glColor3ub(255, 255, 0);
		glVertex3f(-5.0f, 0.0f, 5.0f);
		glColor3ub(255, 255, 255);
		glVertex3f(5.0f, 0.0f, 5.0f);
		glColor3ub(0, 255, 255);
		glVertex3f(5.0f, 0.0f, -5.0f);
	glEnd();
	glColor3ub(0, 250, 0);
	esfera1.Dibuja();//porque estás llamando al método de la clase
	esfera2.Dibuja();//antes ponía mundo1.esfera2.Dubuja() pero le quitas el mundo 1 porqur YA estás en mundo 1

}
void Mundo::Mueve() {

	//mundo1.esfera2.Mueve();
	//Mueve(&mundocamara); ahora esto es mundo//esto es porque la funcion está definida por un puntero, hay que hacerlo así para que me pueda cambiar parámetros
	//mundo1.RotarOjo();
	esfera2.Mueve();
	RotarOjo();
	
}
void Mundo::Tecla(unsigned char key) {

	if (key == 'r')
		esfera1.SetColor(255, 0, 0);
	if (key == 'g')
		esfera1.SetColor(0, 255, 0);
	if (key == 'b')
		esfera1.SetColor(0, 0, 255);

	if (key == '+' && esfera1.GetRadio() < 3)//crece
		//esfera1.GetRadio() += 0.5f; no puedes hacerlo así porque al tenerlo en privado tienes que modificarlo a través de los métodos
		esfera1.SetRadio(esfera1.GetRadio() + 0.5f);
	if (key == '-' && esfera1.GetRadio() > 1)//decrece
		esfera1.SetRadio(esfera1.GetRadio() - 0.5f);
	//tener en cuenta que faltan get-sets de los ifs del main
	if (key == 'd')//dcha,revisar `para entenderlo bien
		esfera1.SetPos(esfera1.GetX() + 0.1f, esfera1.GetY(),esfera1.GetZ());
	if (key == 's')//abajo
		esfera1.SetPos(esfera1.GetX(), esfera1.GetY() - 0.1f, esfera1.GetZ());
	if (key == 'w')//arriba
		esfera1.SetPos(esfera1.GetX(), esfera1.GetY() +0.1f, esfera1.GetZ());
	if (key == 'a')//izqu
		esfera1.SetPos(esfera1.GetX() - 0.1f, esfera1.GetY(), esfera1.GetZ());

}
