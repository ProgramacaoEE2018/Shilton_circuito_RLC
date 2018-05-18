#include<iostream>
#include<complex>
#include<vector>
#include"Classes_cirkt.h"
using namespace std;

int main() {
	int esc,i;
	char comp;
	float A, B, C, w,valor;
	float real, img;
	complex<double> E1;//fasor da fonte
	complex<double> E2;
	complex<double> E3;
	complex<double> I;
	vector<Resistor> res;
	vector<Capacitor> cap;
	vector<Indutor> ind;

	//entrada: amplitude fonte e valor da frequencia angular(w)
	cout << "************FONTE:***************" << endl;
	cout << "1: A*exp(Bt)sen(wt+C)" << endl;
	cout << "2: A*exp(Bt)cos(wt+C)" << endl;
	cout << "*********************************" << endl;
	label:
	cout << "Escolha a fonte (1 ou 2):";
	cin >> esc;
	if (esc == 1) {//sen(x)=cos(90-x)
		cout << "Valor de C em graus:";
		cin >> C;
		C = C - 90;
	}
	if (esc == 2) {
		cout << "Valor de C em graus:";
		cin >> C;
	}else{
		cout << "Opcao invalida. Tente novamente" << endl;
		goto label;
	}
	cout << "Valor de A:";
	cin >> A;
	cout << "Valor de B:";
	cin >> B;
	cout << "Valor de w em graus:";
	cin >> w;

	//componentes
	cout << "********************************"<<endl;
	cout << "Este programa trabalha apenas com os seguintes componentes em série" << endl;
	cout << "R-	Resistor" << endl;
	cout << "C-	Capacitor" << endl;
	cout << "I-	Indutor" << endl;
	cout << "(Para sair tecle digite s)" << endl;
	comp = 0;

	while (comp != 's') {
		cout << "Escolha o componente:";
		cin >> comp;
		if (comp == 'R' || comp == 'r') {
			cout << "Digite o valor da resistencia:";
			cin >> valor;
			Resistor Obj(valor);
			Obj.set_imp(w);
			res.push_back(Obj);//adiciona no fim do vetor de resistores
		}
		if (comp == 'C' || comp == 'c') {
			cout << "Digite o valor da capacitancia:";
			cin >> valor;
			Capacitor Obj(valor);
			Obj.set_imp(w);
			cap.push_back(Obj);//adiciona no fim do vetor de capacitores
		}
		if (comp == 'I' || comp == 'i') {
			cout << "Digite o valor da indutancia:";
			cin >> valor;
			Indutor Obj(valor);
			Obj.set_imp(w);
			ind.push_back(Obj);//adiciona no fim do vetor de indutores
		}
		if (comp == 's') {

		}
		else {
			cout << "Opcao invalida. Tente novamente"<<endl;
		}
	}

	//calcula corrente no circuito(complexos)
	
	//calcula cada tensao(complex polar)
	
	//transforma fasor da tensao em função de cosseno
	
	//imprime grafico de cada tensao
	
	system("pause");
	return 0;
}