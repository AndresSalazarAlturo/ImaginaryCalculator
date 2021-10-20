#include<iostream>
#include <sstream>
#include <conio.h>
#include <math.h>
#include <fstream>

using namespace std;

class numero_Irracional{
	private:
		double real, imaginario;
	public:
		numero_Irracional();
		numero_Irracional(double, double);
		void set_Irracional(double);
		void set_Real(double);
		double get_Irracional();
		double get_Real();		
};

//Constructores//

numero_Irracional::numero_Irracional(){
	real = 0;
	imaginario = 0;
}

numero_Irracional::numero_Irracional(double nreal, double nimaginario){
	real = nreal;
	imaginario = nimaginario;
}

void numero_Irracional::set_Irracional(double nimaginario){
	imaginario = nimaginario;
}

void numero_Irracional::set_Real(double nreal){
	real = nreal;
}

double numero_Irracional::get_Irracional(){
	return imaginario;
}

double numero_Irracional::get_Real(){
	return real;
}

class calculadora{
	private:
		numero_Irracional x1, x2;
	public:
		calculadora();
		calculadora(numero_Irracional, numero_Irracional);
		void set_x1(double, double);
		void set_x2(double, double);
		numero_Irracional get_x1();
		numero_Irracional get_x2();
		
		numero_Irracional suma();
		numero_Irracional resta();
		numero_Irracional multi();
		numero_Irracional multi(numero_Irracional, numero_Irracional);
		numero_Irracional divi();
};

//Constructores//

calculadora::calculadora(){
	x1 = numero_Irracional();
	x2 = numero_Irracional();
}

calculadora::calculadora(numero_Irracional rx1, numero_Irracional rx2){
	x1 = rx1;
	x2 = rx2;
}

void calculadora::set_x1(double rx1, double ix2){
	x1.set_Real(rx1);
	x2.set_Irracional(ix2);
}

void calculadora::set_x2(double rx1, double ix2){
	x1.set_Real(rx1);
	x2.set_Irracional(ix2);
}

numero_Irracional calculadora::get_x1(){
	return x1;
}

numero_Irracional calculadora::get_x2(){
	return x2;
}

numero_Irracional calculadora::suma(){
	numero_Irracional c;
	double rx, ix;
	rx = x1.get_Real() + x2.get_Real();
	ix = x1.get_Irracional() + x2.get_Irracional();
	c.set_Real(rx);
	c.set_Irracional(ix);
	return c;
}

numero_Irracional calculadora::resta(){
	numero_Irracional c;
	double rx, ix;
	rx = x1.get_Real() - x2.get_Real();
	ix = x1.get_Irracional() - x2.get_Irracional();
	c.set_Real(rx);
	c.set_Irracional(ix);
	return c;
}

numero_Irracional calculadora::multi(){
	numero_Irracional res_multi = numero_Irracional();
	double ac, bd, ad, bc, r, i;
	
	ac = x1.get_Real() * x2.get_Real();
	bd = x1.get_Irracional() * x2.get_Irracional();
	ad = x1.get_Real() * x2.get_Irracional();
	bc = x1.get_Irracional() * x2.get_Real();
	
	r = ac - bd;
	i = ad + bc;
	
	res_multi.set_Real(r);
	res_multi.set_Irracional(i);
	
	return res_multi;	
}

numero_Irracional calculadora::multi(numero_Irracional nx1, numero_Irracional nx2){
	numero_Irracional res_multi = numero_Irracional();
	double ac, bd, ad, bc, r, i;
	
	ac = nx1.get_Real() * nx2.get_Real();
	bd = nx1.get_Irracional() * nx2.get_Irracional();
	ad = nx1.get_Real() * nx2.get_Irracional();
	bc = nx1.get_Irracional() * nx2.get_Real();
	
	r = ac - bd;
	i = ad + bc;
	
	res_multi.set_Real(r);
	res_multi.set_Irracional(i);
	
	return res_multi;	
}

numero_Irracional calculadora::divi(){
	double denominador, r, i;
	numero_Irracional res_divi = numero_Irracional();
	numero_Irracional num_conj = numero_Irracional(x2.get_Real(), -x2.get_Irracional());
	
	numero_Irracional numerador = multi(x1, num_conj);
	
	denominador = pow(x2.get_Real(),2) + pow(x2.get_Irracional(),2);
	
	r = numerador.get_Real() / denominador;
	i = numerador.get_Irracional() / denominador;
	
	res_divi.set_Real(r);
	res_divi.set_Irracional(i);
	
	return res_divi;
		
}

int main(){
	
	int opc, sn, s;
	bool salir=false;
	
	ofstream salida ("Resultados.txt");
	
	while(!salir){
		
		double r1, i1, r2, i2;
		cout<<"**********Bienvenido a la calculadora de numero complejos************"<<endl;
		cout<<"Ingrese la parte real del primer numero complejo: "<<endl;
		cin>>r1;
		cout<<"Ingrese la parte imaginaria del primer numero complejo: "<<endl;
		cin>>i1;
		cout<<"Ingrese la parte real del segundo numero complejo: "<<endl;
		cin>>r2;
		cout<<"Ingrese la parte imaginaria del segundo numero complejo: "<<endl;
		cin>>i2;
		
		cout<<"Que operacion desea realizar?"<<endl;
		
		cout<<"1. Operacion suma\n";
		cout<<"2. Operacion resta\n";
		cout<<"3. Operacion multiplicacion\n";
		cout<<"4. Operacion division\n";
		cout<<"5. Salir\n";
		cin>>opc;
		
		numero_Irracional x1 = numero_Irracional(r1,i1);
		numero_Irracional x2 = numero_Irracional(r2,i2);
		calculadora calcular = calculadora(x1, x2);
		
		numero_Irracional res_sum = calcular.suma();
		numero_Irracional res_res = calcular.resta();
		numero_Irracional res_multi = calcular.multi();
		numero_Irracional res_divi = calcular.divi();
		
		switch(opc){
			case 1:
				cout<<"El resultado de la suma = "<< res_sum.get_Real() << ", " << res_sum.get_Irracional()<< "i" <<endl;
				salida<<"El resultado de la suma = "<< res_sum.get_Real() << ", " << res_sum.get_Irracional()<< "i" <<endl;
				cout<<"Desea realizar una nueva operacion? 1. si; 2. no"<<endl;
				cin>>sn;
				switch(sn){
					case 1:
						break;
					case 2:
						salir=true;
				}
				break;
			case 2:
				cout<<"El resultado de la resta = "<< res_res.get_Real() << ", " << res_res.get_Irracional()<< "i" <<endl;
				salida<<"El resultado de la resta = "<< res_res.get_Real() << ", " << res_res.get_Irracional()<< "i" <<endl;
				cout<<"Desea realizar una nueva operacion? 1. si; 2. no"<<endl;
				cin>>sn;
				switch(sn){
					case 1:
						break;
					case 2:
						salir=true;
				}
				break;
			case 3:
				cout<<"El resultado de la multiplicacion = "<< res_multi.get_Real() << ", " << res_multi.get_Irracional()<< "i" <<endl;
				salida<<"El resultado de la multiplicacion = "<< res_multi.get_Real() << ", " << res_multi.get_Irracional()<< "i" <<endl;
				cout<<"Desea realizar una nueva operacion? 1. si; 2. no"<<endl;
				cin>>sn;
				switch(sn){
					case 1:
						break;
					case 2:
						salir=true;
				}
				break;
			case 4:
				cout<<"El resultado de la division = "<< res_divi.get_Real() << ", " << res_divi.get_Irracional()<< "i" <<endl;
				salida<<"El resultado de la division = "<< res_divi.get_Real() << ", " << res_divi.get_Irracional()<< "i" <<endl;
				cout<<"Desea realizar una nueva operacion? 1. si; 2. no"<<endl;
				cin>>sn;
				switch(sn){
					case 1:
						break;
					case 2:
						salir=true;
				}
				break;
			case 5:
				cout<<"Gracias por usar esta calculadora :)";
				salir=true;
				break;				
		}	
 	}
 	cout<<"Gracias por usar esta calculadora :)";
 	getch();
}

//Andres Sebastian Salazar Alturo

























