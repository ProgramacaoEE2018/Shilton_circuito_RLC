#pragma once
#include <complex>
using namespace std;
//usar a heranca de Componente nao ajudou muito
complex<double> aux;

class Resistor {
private:
	float resist;//valor da resistencia
	complex<double> imp;//impedancia

public:
	Resistor(float valor);
	void set_imp(complex<double> s);
	float get_resist();
	complex<double> get_imp();
};
Resistor::Resistor(float valor) {resist = valor;}
void Resistor::set_imp(complex<double> s) {imp = complex<double>(resist, 0);}
float Resistor::get_resist() {return resist;}
complex<double> Resistor::get_imp() { return imp; }


class Capacitor {
private:
	float capacit;//valor da capacitancia
	complex<double> imp;//impedancia

public:
	Capacitor(float valor);
	void set_imp(complex<double> s);
	float get_capacit();
	complex <double> get_imp();
 };
Capacitor::Capacitor(float valor) {capacit = valor;}
void Capacitor::set_imp(complex<double> s) {imp = complex<double>(1,0)/(s * complex<double>(capacit,0));}
float Capacitor::get_capacit() {return capacit;}
complex<double> Capacitor::get_imp() { return imp; }

class Indutor {
private:
	float indutancia;//valor da indutancia
	complex<double> imp;//impedancia

public:
	Indutor(float valor);
	void set_imp(complex<double> s);
	float get_indutor();
	complex<double> get_imp();
};
Indutor::Indutor(float valor) {indutancia = valor;}
void Indutor::set_imp(complex<double> s) {imp = s*complex<double>(indutancia,0);}
float Indutor::get_indutor() {return indutancia;}
complex<double> Indutor::get_imp() { return imp;}

class Tensao {
private:
	complex<double> valor;//fasor
public:
	Tensao(complex<double> corrente, complex<double> impedance);
	complex<double> get_valor();
};
Tensao::Tensao(complex<double> corrente, complex<double> impedance) { valor = corrente * impedance; };
complex<double> Tensao::get_valor() { return valor; }