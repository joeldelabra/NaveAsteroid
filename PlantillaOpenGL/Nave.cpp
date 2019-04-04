#include "stdafx.h"
#include "Nave.h"

Nave::Nave()
{
	angulo = 0.0f;
	coordenadas = vec3(0.0f, 0.0f, 0.0f);
	// Establece el valor como una matriz identidad
	transformaciones = mat4(1.0f);
}

void Nave::rotar(Direccion direccion)
{
	float rotacion = velocidadAngular;
	if (direccion == Direccion::Derecha){
		rotacion = -rotacion;
	}

	angulo += rotacion;
	actualizarMatrizTransformacion();
}

void Nave::avanzar() {
	vec3 traslacion = vec3
	(cos(angulo * 3.14159 / 180.0f) * velocidadNormal, sin(angulo*3.14159 / 180.0f) * velocidadNormal, 0.0f);
	coordenadas += traslacion;
	actualizarMatrizTransformacion();
}

void Nave::actualizarMatrizTransformacion()
{
	// Partir de una matriz identidad
	transformaciones = mat4(1.0f);
	// Aplicar transformaciones
	tranformaciones = translate(transformaciones, coordenadas);
	
}