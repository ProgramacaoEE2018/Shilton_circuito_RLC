#include<complex>
using namespace std;
class Resistor {
private:
	float resist;//valor da resistencia
	complex<double> imp;//impedancia
	
public:
	Resistor(float valor);
	void set_imp(float w);
};
Resistor::Resistor(float valor) {
	resist = valor;
}
void Resistor::set_imp(float w) {
	imp = complex<double>(resist, 0);
}

class Capacitor {
private:
	float capacit;//valor da capacitancia
	complex<double> imp;//impedancia

public:
	Capacitor(float valor);
	void set_imp(float w);
};
Capacitor::Capacitor(float valor) {
	capacit = valor;
}
void Capacitor::set_imp(float w) {
	imp = complex<double>(0, -1 / (w*capacit));
}

class Indutor{
private:
	float indut;//valor da resistencia
	complex<double> imp;//impedancia

public:
	Indutor(float valor);
	void set_imp(float w);
};
Indutor::Indutor(float valor) {
	indut = valor;
}
void Indutor::set_imp(float w) {
	imp = complex<double>(0, (w*indut));
}