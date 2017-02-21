#include "object.h"
#include "tree.h"
#include "treeNode.h"
#include "Person.h"
#include "employee.h"
#include <iostream>
#include <stdlib.h>
#include <string>
#include <vector>
#include <fstream>	
#define RESET   "\033[0m"
#define RED     "\033[31m"      /* Red */
#define GREEN   "\033[32m"      /* Green */
#define BLUE    "\033[34m"      /* Blue */
#define CLEAR "\033[2J"  // clear screen escape code 
using namespace std;

Tree* getStudentsFile();

int main(int argc, char const *argv[]){
	Tree* organigrama;
	bool respuesta = true;
	int opcion;
	int cargado = 0;
	while(respuesta){
		cout<<GREEN<<"Que desea hacer: "<<endl;
		cout<<"1-Cargar arbol"<<endl;
		cout<<"2-Imprimir"<<endl;
		cout<<"3-Salir"<<RESET<<endl;
		cin>>opcion;
		switch(opcion){
			case 1:{
				if(organigrama=getStudentsFile()){
					cout <<BLUE<<"Cargado con exito"<<RESET<<endl;
					cargado = 1;
				}else{
					cout <<BLUE<< "no se pudo cargar"<<RESET<<endl;
					cargado = 0;
				}
				break;
			}

			case 2:{
				if(cargado == 1){
					cout<<"-------------------------"<<endl;
					cout<<"-------"<<RED<<"Organigrama"<<RESET<<"-------"<<endl;
					cout<<"-------------------------"<<endl;
					cout << organigrama->toString()<<endl;
				}else{
					cout <<BLUE<< "Tiene que cargar el arbol primero"<<RESET<<endl;
				}
				break;
			}

			case 3:{
				exit(1);
			}
		}
	cout<<"Desea continuar[0/1]: ";
	cin>>respuesta;
	}
	return 0;
}

/*Metodo getStudentsFile lee el archivo de texto
	y separa los hijos dependiendo de cuantas tabulaciones tenga
	y asi los mete al padre, luego se hace un objeto Tree, el cual recibe el nodo raiz*/
Tree* getStudentsFile() {
	ifstream treeFile;
	string texto;
	TreeNode* root;
	TreeNode* neo;
	string acc="";
	char delimiter =',';
	string line="";
	vector<string>vectorString;
	VArrayList* temp = new VArrayList(100);
	if(ifstream("personas.txt")){
	    fstream treeFile("personas.txt");
	    int total = 0;
	    while(getline(treeFile, line)) {
	    	if (total == 0) {
	    		/*Si total es igual a 0 significa que esta dentro de la raiz, si no es igual a 0
	    		entra al else que es donde se miran los hijos por tabulaciones*/
	    		for (int i = 0; i < line.size(); ++i){
	    			if(line[i]==delimiter){
	    				vectorString.push_back(acc);
	    				acc = "";
	    			}else{
	    				acc+=line[i];
	    			}
	    		}
	    		double salary = atof(acc.c_str());
	    		employee* empleado = new employee(vectorString.at(1),vectorString.at(0),salary);
	    		vectorString.clear();
	    		acc = "";
	    		root = new TreeNode(empleado,line);
	    		total++;
	    	} else {
				int pos = 0;
				/*Se mira si Line.at(pos) es igual a un tab, para asi poder avanzar
				dentro del archivo de texto*/
				while (line.at(pos) == '\t') {
					pos++;
				}
				if (pos == 1) {
					/*Si pos es igual 1 significa que el nodo en esa posicion tiene de ancestro a Root
					si no es igual a 1, entra al else*/
					string dos=line.substr(pos, line.size());
					for (int i = 0; i < dos.size(); ++i){
	    				if(dos[i]==delimiter){
	    					vectorString.push_back(acc);
	    					acc = "";
	    				}else{
	    					acc+=dos[i];
	    				}
	    			}
	    			double salary2= atof(acc.c_str());
	    			employee* empleado2 = new employee(vectorString.at(1),vectorString.at(0),salary2);
	    			vectorString.clear();
	    			acc = "";	
					TreeNode* nearestSon = new TreeNode(empleado2,dos);
					root->addSon(nearestSon);
					temp->clear();
					temp->insert(nearestSon, 0);
				} else {
					/*Como la posicion no es igual a 1 significa que esta dentro de otro nivel,
					por lo tanto se tiene que ver quien es el padre de dicho nodo*/
					string tres = line.substr(pos,line.size());
					for (int i = 0; i < tres.size(); ++i){
	    				if(tres[i]==delimiter){
	    					vectorString.push_back(acc);
	    					acc = "";
	    				}else{
	    					acc+=tres[i];
	    				}
	    			}
	    			double salary3= atof(acc.c_str());
	    			employee* empleado3 = new employee(vectorString.at(1),vectorString.at(0),salary3);
	    			vectorString.clear();
	    			acc="";
					neo = new TreeNode(empleado3,tres);
					if (pos >= temp->size()) {
						temp->insert(neo, pos - 1);
					} else {
						temp->remove(pos - 1);
						temp->insert(neo, pos - 1);
					}
					static_cast<TreeNode*> (temp->get(pos - 2))->addSon(neo);
				}
			}
			treeFile.clear();
	    }
	}
	Tree* myTree = new Tree(root);
	return myTree;
}
