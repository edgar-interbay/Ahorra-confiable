// Proyecto COMP 2120 – Ahorra Confiable

// Integrantes: Javier, Sergio, Edgar

#include <iostream>
#include <unistd.h>     
#include <string>
#include <cmath>        
#include <algorithm>    

using namespace std;

int main () 
{
    // Esta parte del codigo la hizo Edgar
    
    const int dias_ano = 365;
    const int dias_mes = 30;

    int modo_ahorro, objeto, inversion, precio_articulo;
    double dias_por_periodo;
    string continuar = "si";

    // Precios segun PR
    
    int precio_min[4] = {80, 500, 1000, 200000};
    int precio_max[4] = {200, 1500, 500000, 1000000};

    string modosAhorro[4] = {"Semanal", "Bisemanal", "Mensual", "6 meses"};
    string objetos[4] = {
        "Un detalle/regalo para ti o alguna persona",
        "Algun dispositivo electronico",
        "Un carro",
        "Una casa"
    };

    // Esta parte la realizo Sergio
    
    
    while (continuar == "si") {
        cout<<"=============================="<<"\n";
        cout<<" Bienvenido a Ahorra Confiable"<<"\n";
        cout<<"=============================="<<"\n";
        cout<<"Este programa te ayudara a calcular el tiempo que debes ahorrar para comprar algo."<<"\n";
        sleep(2);

    
        while (true) {
            cout<<"\nElija su preferencia de ahorro (1-4)\n";
            for(int i = 0; i < 4; i++){
                cout << i+1 << ". " << modosAhorro[i] << "\n";
            }

            cin>>modo_ahorro;

            if (cin.fail() || modo_ahorro < 1 || modo_ahorro > 4) {
                cin.clear();
                cin.ignore(2000, '\n');
                cout << "Opcion invalida.. Seleccione una de las presentadas en pantalla" << "\n";
            } else {
                cout << "\nHas escogido ahorro " << modosAhorro[modo_ahorro - 1] << "\n";
                break;
            }
        }

        //Edgar
        
        while (true) {
            cout<<"\nCuanto puedes ahorrar por periodo?\n";
            cin>>inversion;

            if (cin.fail() || inversion <= 0) {
                cin.clear();
                cin.ignore(2000,'\n');
                cout << "Error: debe ingresar un numero valido." << "\n";
                sleep(2);
            } else {
                break;
            }
        }

        //Javier
        
        while (true) {
            cout << "\nPara que quiere ahorrar (1-4)?\n";
            for(int i = 0; i < 4; i++){
                cout << i+1 << ". " << objetos[i] << "\n";
            }

            cin >> objeto;

            if (cin.fail() || objeto < 1 || objeto > 4) {
                cin.clear();
                cin.ignore(2000, '\n');
                cout << "Opcion invalida.. Seleccione una de las presentadas en pantalla" << "\n";
                sleep(2);
            } else {
                cout << "\nHas escogido la opcion de " << objetos[objeto - 1] << "." << "\n";
                break;
            }
        }

        //Javier
        
        while (true) {
            cout << "\nCuanto cuesta el articulo que quieres comprar?\n";
            cin >> precio_articulo;

            if (cin.fail()) {
                cin.clear();
                cin.ignore(2000, '\n');
                cout << "Error: debe ingresar un numero valido.\n";
                continue;
            }

            //se uso clamp para validar que el input del usuario estuviera en nuestro rango
            
            precio_articulo = clamp(precio_articulo, precio_min[objeto - 1], precio_max[objeto - 1]);
            cout << "El precio ajustado es: " << precio_articulo << " dolares.\n";
            break;
        }

        // Javier y Sergio
        
        switch(modo_ahorro){
            case 1: dias_por_periodo = 7; break;
            case 2: dias_por_periodo = 14; break;
            case 3: dias_por_periodo = 30; break;
            case 4: dias_por_periodo = 180; break;
        }

        double dias_necesarios = (double)precio_articulo / inversion * dias_por_periodo;
        int anos = floor(dias_necesarios / dias_ano);
        int meses = floor((dias_necesarios - anos * dias_ano) / dias_mes);

        //Resultados : Edgar y Sergio
        
        cout<<"\nPara comprar " << objetos[objeto - 1]<<" que cuesta = "<< precio_articulo<<", ahorrando = "<< inversion <<" dolares "<< modosAhorro[modo_ahorro - 1]<<", tardarias aproximadamente:\n";
        cout<<"\n" << anos << " años y " << meses << " meses.\n";

    
        cout<<"\nQuieres intentar otra vez con otro modo o cantidad? (si/no): ";
        cin>>continuar;
    }

    cout<<"\nGracias por usar Ahorra Confiable.\n";

    return 0;
}
