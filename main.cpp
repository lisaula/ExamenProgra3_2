// queue::push/pop

#include <iostream>
#include <list>
#include <fstream>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include "Celular.h"
#include "Evaluador.h"
#include "NodoBinario.h"

using namespace std;

//Escribe los datos del objeto celular (dado) en un archivo binario con el nombre dado en la posicion dada
//Nota: Se deben poder agregar varios celulares en un solo archivo
void escribir(string nombre_archivo, Celular*celular, int posicion)
{
    /*
        nombre 20
        modelo 4
        precio 8
        total 32
    */
    ofstream out(nombre_archivo.c_str(),ios::in);
    out.seekp(posicion*32);
    out.write(celular->nombre.c_str(),20);
    out.write((char*)&celular->modelo,4);
    out.write((char*)&celular->precio,8);
    out.close();
}

//Devuelve un celular previamente escrito (con la funcion escribir()) en un archivo binario con nombre dado en la posicion dada
//Nota: Se deben poder leer varios celulares de un solo archivo
Celular* leer(string nombre_archivo, int posicion)
{

    ifstream in(nombre_archivo.c_str());
    char nombre[20];
    int modelo;
    double precio;
    in.seekg(posicion*32);
    in.read(nombre,20);
    in.read((char*)&modelo,4);
    in.read((char*)&precio,8);
    in.close();
    Celular *c = new Celular(nombre,modelo,precio);
    return c;
}

//Devuelve el precio del celular en la ultima posicion del archivo con nombre dado
double getUltimoPrecio(string nombre_archivo)
{
    ifstream in(nombre_archivo.c_str());
    in.seekg(-8,ios::end);
    double precio;
    in.read((char*)&precio,8);
    return precio;
}

//Convierte la cola (dada) en una pila los datos deben de quedar en el mismo orden
//Nota: El tope de la pila debe de ser el frente de la cola
stack<char> convertirAPila(queue<char> mi_cola)
{
    stack<char> resultado;
    stack<char> resultado2;
    while(!mi_cola.empty()){
        resultado.push(mi_cola.front());
        mi_cola.pop();
    }
    while(!resultado.empty()){
        resultado2.push(resultado.top());
        resultado.pop();
    }
    return resultado2;
}

//Devuelve true si el set esta ordenado, de lo contrario devuelve false
bool estaOrdenado(set<int> mi_set)
{
    return true;
}

//Devuelve las tablas de los numeros del 1 al 10
//La llave es el numero de la tabla, el valor asociado es un vector que contiene la tabla de dicho numero
map<int,vector<int> > getTablas()
{
    vector<int>tabla1,tabla2,tabla3,tabla4,tabla5,tabla6,tabla7,tabla8,tabla9,tabla10;
    int num=1;
    for(int i=1; i<=10;i++)
    {
        tabla1.push_back(i*num);
        tabla2.push_back(i*(num+1));
        tabla3.push_back(i*(num+2));
        tabla4.push_back(i*(num+3));
        tabla5.push_back(i*(num+4));
        tabla6.push_back(i*(num+5));
        tabla7.push_back(i*(num+6));
        tabla8.push_back(i*(num+7));
        tabla9.push_back(i*(num+8));
        tabla10.push_back(i*(num+9));
    }
    map<int,vector<int> > mi_mapa;
    mi_mapa[1]=tabla1;
    mi_mapa[2]=tabla2;
    mi_mapa[3]=tabla3;
    mi_mapa[4]=tabla4;
    mi_mapa[5]=tabla5;
    mi_mapa[6]=tabla6;
    mi_mapa[7]=tabla7;
    mi_mapa[8]=tabla8;
    mi_mapa[9]=tabla9;
    mi_mapa[10]=tabla10;
    return mi_mapa;
}

void getSuma(int *suma, NodoBinario* raiz){
    if(raiz !=NULL){
        *suma += raiz->valor;
        getSuma(suma,raiz->hijo_der);
        getSuma(suma,raiz->hijo_izq);
    }
}
//Devuelve la suma de todos los valores almacenados en el arbol con raiz dada
int getSuma(NodoBinario* raiz)
{
    int suma=0;
    getSuma(&suma,raiz);
    return suma;
}
bool esPrimo(int num){
    int cont=1,primo=0;

    while(cont<=num){
        if(num%cont==0){
            primo++;
        }
        cont++;
    }
    if(primo==2)
    return true;

    return false;
}
void sonPrimos(bool *vari,NodoBinario* raiz ){
    if(raiz !=NULL){
      *vari = esPrimo(raiz->valor);
      if(*vari==true){
        sonPrimos(vari,raiz->hijo_der);
        sonPrimos(vari,raiz->hijo_izq);
      }
    }
}
//Devuelve true si todos los valores de los nodos son primos, de lo contrario devuelve false
bool sonPrimos(NodoBinario* raiz)
{
    bool variante=true;
    sonPrimos(&variante,raiz);
    return variante;
}



int main ()
{
    //Funcion evaluadora
    evaluar();
    return 0;
}

