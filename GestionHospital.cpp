/*
Desarrollado por: Brenda Romina Loaiza Vargas
Fecha: 2024/07/21

Problema Planteado:
Desarrolle un sistema de gestión para un hospital que administre información de pacientes, doctores y citas médicas. 
El sistema debe permitir registrar, modificar, buscar, listar y eliminar pacientes y doctores, así como programar y 
gestionar citas médicas. Además, debe ser capaz de guardar y cargar todos estos datos desde archivos.

Funcionalidades del Sistema:

Pacientes:
Registrar Paciente
Modificar Paciente
Buscar Paciente
Listar Pacientes
Eliminar Paciente

Doctores:
Registrar Doctor
Modificar Doctor
Buscar Doctor
Listar Doctores
Eliminar Doctor

Citas:
Programar Cita
Modificar Cita
Buscar Cita
Listar Citas
Eliminar Cita
Ficheros:

Guardar Datos
Cargar Datos
*/

#include <iostream>

using namespace std;

struct Paciente {
    string Ci;
    string nombre;
    string apellido;
};

struct Doctor {
    string Ci;
    string nombre;
    string apellido;
};

struct Cita {
    string CiPaciente;
    string CiDoctor;
    string fecha;
    string hora;
};

//Operaciones de Pacientes
void registrarPaciente(Paciente pacientes[], int &n);
void modificarPaciente(Paciente pacientes[], int n);
void buscarPaciente(Paciente pacientes[], int n);
void listarPacientes(Paciente pacientes[], int n);
void eliminarPaciente(Paciente pacientes[], int &n);

//Operaciones de Doctores 
void registrarDoctor(Doctor doctores[], int &n);
void modificarDoctor(Doctor doctores[], int n);
void buscarDoctor(Doctor doctores[], int n);
void listarDoctores(Doctor doctores[], int n);
void eliminarDoctor(Doctor doctores[], int &n);

//Operaciones de Citas
void programarCita(Cita citas[], int &n);
void modificarCita(Cita citas[], int n);
void buscarCita(Cita citas[], int n);
void listarCitas(Cita citas[], int n);
void eliminarCita(Cita citas[], int &n);

//Ficheros
void guardarDatos(Paciente pacientes[], int n, Doctor doctores[], int m, Cita citas[], int o);
void cargarDatos(Paciente pacientes[], int &n, Doctor doctores[], int &m, Cita citas[], int &o);

// Se debe pedir al usuario al incio del programa que ingrese la cantidad de pacientes, doctores y citas que el programa va a manejar

int main() {
    Paciente pacientes[100];
    Doctor doctores[100];
    Cita citas[100];
    int n = 0, m = 0, o = 0;
    int opcion;

    cout  << "________________________________________________________" << endl;
    cout  << " Bienvenido al Sistema de Gestion del IESS" << endl;
    cout  << "________________________________________________________" << endl;
    system("pause");
    system("cls");



    do {
        cout << "\n________________________________________________________" << endl;
        cout << "Menu Principal" << endl;
        cout << "________________________________________________________" << endl;
        cout << "Seleccione una opcion: " << endl;
        cout << "\n1. Pacientes" << endl; // \n funciona igual que endl 
        cout << "2. Doctores" << endl;
        cout << "3. Citas" << endl;
        cout << "4. Guardar Datos" << endl;
        cout << "5. Cargar Datos" << endl;
        cout << "6. Salir" << endl;
        cout << "Opcion: ";
        cin >> opcion;
        system("cls");

        switch(opcion) {
            case 1:
                cout << "\n________________________________________________________" << endl;   
                cout << "Menu Pacientes" << endl;
                cout << "________________________________________________________" << endl;
                cout << "\n1. Registrar Paciente" << endl;
                cout << "2. Modificar Paciente" << endl;
                cout << "3. Buscar Paciente" << endl;
                cout << "4. Listar Pacientes" << endl;
                cout << "5. Eliminar Paciente" << endl;
                cout << "Opcion: ";
                cin >> opcion;

                switch(opcion) {
                    case 1:
                        registrarPaciente(pacientes, n);
                        break;
                    case 2:
                        modificarPaciente(pacientes, n);
                        break;
                    case 3:
                        buscarPaciente(pacientes, n);
                        break;
                    case 4:
                        listarPacientes(pacientes, n);
                        break;
                    case 5:
                        eliminarPaciente(pacientes, n);
                        break;
                    default:
                        cout << "Opcion no valida" << endl;
                }
                break;
            case 2:
                cout << "\n________________________________________________________" << endl;
                cout << "Menu Doctores" << endl;
                cout << "________________________________________________________" << endl;
                cout << "\n1. Registrar Doctor" << endl;
                cout << "2. Modificar Doctor" << endl;
                cout << "3. Buscar Doctor" << endl;
                cout << "4. Listar Doctores" << endl;
                cout << "5. Eliminar Doctor" << endl;
                cout << "Opcion: ";
                cin >> opcion;

                switch(opcion) {
                    case 1:
                        registrarDoctor(doctores, m);
                        break;
                    case 2:
                        modificarDoctor(doctores, m);
                        break;
                    case 3:
                        buscarDoctor(doctores, m);
                        break;
                    case 4:
                        listarDoctores(doctores, m);    
                        break;
                    case 5:
                        eliminarDoctor(doctores, m);
                        break;
                    default:
                        cout << "Opcion no valida" << endl;
                }
                break;
            case 3:     
                cout << "\n________________________________________________________" << endl;
                cout << "Menu Citas" << endl;
                cout << "________________________________________________________" << endl;
                cout << "\n1. Programar Cita" << endl;
                cout << "2. Modificar Cita" << endl;
                cout << "3. Buscar Cita" << endl;
                cout << "4. Listar Citas" << endl;
                cout << "5. Eliminar Cita" << endl;
                cout << "Opcion: ";
                cin >> opcion;

                switch(opcion) {
                    case 1:
                        programarCita(citas, o);
                        break;
                    case 2:
                        modificarCita(citas, o);
                        break;
                    case 3:
                        buscarCita(citas, o);
                        break;
                    case 4:
                        listarCitas(citas, o);
                        break;
                    case 5:
                        eliminarCita(citas, o);
                        break;
                    default:
                        cout << "Opcion no valida" << endl;
                }
                break;
            case 4:
                guardarDatos(pacientes, n, doctores, m, citas, o);
                break;
            case 5:
                cargarDatos(pacientes, n, doctores, m, citas, o);
                break;
            case 6:
                cout << "Saliendo..." << endl;
                break;
            default:
                cout << "Opcion no valida" << endl;
                cout << "Por favor, ingrese una opcion valida" << endl;
                system("pause");
                system("cls");
        }
    } while(opcion != 6);

    return 0;
}

void registrarPaciente(Paciente pacientes[], int &n) {
    cout << "________________________________________________________" << endl;
    cout << "Registrar Paciente" << endl;
    cout << "________________________________________________________" << endl;
    cout << "Ingrese CI: ";
    cin >> pacientes[n].Ci;
    cout << "Ingrese Nombre: ";
    cin >> pacientes[n].nombre;
    cout << "Ingrese Apellido: ";
    cin >> pacientes[n].apellido;
    n++;
    cout << "Paciente registrado correctamente" << endl;
    system("pause");
    system("cls");
}

void modificarPaciente(Paciente pacientes[], int n) {
    cout << "________________________________________________________" << endl;
    cout << "Modificar Paciente" << endl;
    cout << "________________________________________________________" << endl;
    string Ci;
    cout << "Ingrese CI del paciente a modificar: ";
    cin >> Ci;

    for(int i = 0; i < n; i++) {
        if(pacientes[i].Ci == Ci) {
            cout << "Ingrese nuevo CI: ";
            cin >> pacientes[i].Ci;
            cout << "Ingrese nuevo Nombre: ";
            cin >> pacientes[i].nombre;
            cout << "Ingrese nuevo Apellido: ";
            cin >> pacientes[i].apellido;
            cout << "Paciente modificado correctamente" << endl;
            system("pause");
            system("cls");
            break;
        }
    }
    cout << "Paciente no encontrado" << endl;
    system("pause");
    system("cls");
}

void buscarPaciente(Paciente pacientes[], int n) {
    cout << "________________________________________________________" << endl;
    cout << "Buscar Paciente" << endl;
    cout << "________________________________________________________" << endl;
    string Ci;
    cout << "Ingrese CI del paciente a buscar: ";
    cin >> Ci;

    for(int i = 0; i < n; i++) {
        if(pacientes[i].Ci == Ci) {
            cout << "________________________________________________________" << endl;
            cout << "Paciente encontrado" << endl;
            cout << "________________________________________________________" << endl;
            cout << "CI: " << pacientes[i].Ci << endl;
            cout << "Nombre: " << pacientes[i].nombre << endl;
            cout << "Apellido: " << pacientes[i].apellido << endl;
            system("pause");
            system("cls");
            break;
        }
    }
    cout << "Paciente no encontrado" << endl;
    system("pause");
    system("cls");
}

void listarPacientes(Paciente pacientes[], int n) {
    cout << "________________________________________________________" << endl;
    cout << "Listar Pacientes" << endl;
    cout << "________________________________________________________" << endl;

    for(int i = 0; i < n; i++) {
        cout << "Paciente : " << i + 1 << endl;
        cout << "CI: " << pacientes[i].Ci << endl;
        cout << "Nombre: " << pacientes[i].nombre << endl;
        cout << "Apellido: " << pacientes[i].apellido << endl;
        cout << "________________________________________________________" << endl;
    }
    system("pause");
    system("cls");

}   

void eliminarPaciente(Paciente pacientes[], int &n) {
    cout << "________________________________________________________" << endl;
    cout << "Eliminar Paciente" << endl;
    cout << "________________________________________________________" << endl;
    
    string Ci;
    cout << "Ingrese CI del paciente a eliminar: ";
    cin >> Ci;

    for(int i = 0; i < n; i++) {
        if(pacientes[i].Ci == Ci) {
            for(int j = i; j < n - 1; j++) {
                pacientes[j] = pacientes[j + 1]; // se reemplaza el paciente a eliminar por el siguiente paciente
            }
            n--;
            cout << "Paciente eliminado correctamente" << endl;
            system("pause");
            system("cls");
            break;
        }
    }
    cout << "Paciente no encontrado" << endl;
    system("pause");
    system("cls");
}

void registrarDoctor(Doctor doctores[], int &n) {
    cout << "________________________________________________________" << endl;
    cout << "Registrar Doctor" << endl;
    cout << "________________________________________________________" << endl;
    cout << "Ingrese CI: ";
    cin >> doctores[n].Ci;
    cout << "Ingrese Nombre: ";
    cin >> doctores[n].nombre;
    cout << "Ingrese Apellido: ";
    cin >> doctores[n].apellido;
    n++;
    cout << "Doctor registrado correctamente" << endl;
    system("pause");
    system("cls");
}

void modificarDoctor(Doctor doctores[], int n) {
    cout << "________________________________________________________" << endl;
    cout << "Modificar Doctor" << endl;
    cout << "________________________________________________________" << endl;
    string Ci;
    cout << "Ingrese CI del doctor a modificar: ";
    cin >> Ci;

    for(int i = 0; i < n; i++) {
        if(doctores[i].Ci == Ci) {
            cout << "Ingrese nuevo CI: ";
            cin >> doctores[i].Ci;
            cout << "Ingrese nuevo Nombre: ";
            cin >> doctores[i].nombre;
            cout << "Ingrese nuevo Apellido: ";
            cin >> doctores[i].apellido;
            cout << "Doctor modificado correctamente" << endl;
            system("pause");
            system("cls");
            break;
        }
    }
    cout << "Doctor no encontrado" << endl;
    system("pause");
    system("cls");
}

void buscarDoctor(Doctor doctores[], int n) {
    cout << "________________________________________________________" << endl;
    cout << "Buscar Doctor" << endl;
    cout << "________________________________________________________" << endl;
    string Ci;
    cout << "Ingrese CI del doctor a buscar: ";
    cin >> Ci;

    for(int i = 0; i < n; i++) {
        if(doctores[i].Ci == Ci) {
            cout << "Doctor encontrado" << endl;
            cout << "CI: " << doctores[i].Ci << endl;
            cout << "Nombre: " << doctores[i].nombre << endl;
            cout << "Apellido: " << doctores[i].apellido << endl;
            system("pause");
            system("cls");
            break;
        }
    }
    cout << "Doctor no encontrado" << endl;
    system("pause");
    system("cls");
}

void listarDoctores(Doctor doctores[], int n) {
    cout << "________________________________________________________" << endl;
    cout << "Listar Doctores" << endl;
    cout << "________________________________________________________" << endl;

    for(int i = 0; i < n; i++) {
        cout << "Doctor : " << i + 1 << endl;
        cout << "CI: " << doctores[i].Ci << endl;
        cout << "Nombre: " << doctores[i].nombre << endl;
        cout << "Apellido: " << doctores[i].apellido << endl;
        cout << "________________________________________________________" << endl;
    }
    system("pause");
    system("cls");
}

void eliminarDoctor(Doctor doctores[], int &n) {
    cout << "________________________________________________________" << endl;
    cout << "Eliminar Doctor" << endl;
    cout << "________________________________________________________" << endl;
    string Ci;
    cout << "Ingrese CI del doctor a eliminar: ";
    cin >> Ci;

    for(int i = 0; i < n; i++) {
        if(doctores[i].Ci == Ci) {
            for(int j = i; j < n - 1; j++) {
                doctores[j] = doctores[j + 1]; // se reemplaza el doctor a eliminar por el siguiente doctor
            }
            n--;
            cout << "Doctor eliminado correctamente" << endl;
            system("pause");
            system("cls");
            break;
        }
    }
    cout << "Doctor no encontrado" << endl;
    system("pause");
    system("cls");
}

void programarCita(Cita citas[], int &n) {
    cout << "________________________________________________________" << endl;
    cout << "Programar Cita" << endl;
    cout << "________________________________________________________" << endl;
    cout << "Ingrese CI del paciente: ";
    cin >> citas[n].CiPaciente;
    cout << "Ingrese CI del doctor: ";
    cin >> citas[n].CiDoctor;
    cout << "Ingrese fecha: ";
    cin >> citas[n].fecha;
    cout << "Ingrese hora: ";
    cin >> citas[n].hora;
    n++;
    cout << "Cita programada correctamente" << endl;
    system("pause");
    system("cls");
}

void modificarCita(Cita citas[], int n) {
    cout << "________________________________________________________" << endl;
    cout << "Modificar Cita" << endl;
    cout << "________________________________________________________" << endl;
    string CiPaciente, CiDoctor;
    cout << "Ingrese CI del paciente: ";
    cin >> CiPaciente;
    cout << "Ingrese CI del doctor: ";
    cin >> CiDoctor;

    for(int i = 0; i < n; i++) {
        if(citas[i].CiPaciente == CiPaciente && citas[i].CiDoctor == CiDoctor) {
            cout << "Ingrese nueva fecha: ";
            cin >> citas[i].fecha;
            cout << "Ingrese nueva hora: ";
            cin >> citas[i].hora;
            cout << "Cita modificada correctamente" << endl;
            system("pause");
            system("cls");
            break;
        }
    }
    cout << "Cita no encontrada" << endl;
    system("pause");
    system("cls");
}

void buscarCita(Cita citas[], int n) {
    cout << "________________________________________________________" << endl;
    cout << "Buscar Cita" << endl;
    cout << "________________________________________________________" << endl;
    string CiPaciente, CiDoctor;
    cout << "Ingrese CI del paciente: ";
    cin >> CiPaciente;
    cout << "Ingrese CI del doctor: ";
    cin >> CiDoctor;
    for(int i = 0; i < n; i++) {
        if(citas[i].CiPaciente == CiPaciente && citas[i].CiDoctor == CiDoctor) {
            cout << "Cita encontrada" << endl;
            cout << "CI del paciente: " << citas[i].CiPaciente << endl;
            cout << "CI del doctor: " << citas[i].CiDoctor << endl;
            cout << "Fecha: " << citas[i].fecha << endl;
            cout << "Hora: " << citas[i].hora << endl;
            system("pause");
            system("cls");
            break;
        }
    }
    cout << "Cita no encontrada" << endl;
    system("pause");
    system("cls");
}

void listarCitas(Cita citas[], int n) {
    cout << "________________________________________________________" << endl;
    cout << "Listar Citas" << endl;
    cout << "________________________________________________________" << endl;
    for(int i = 0; i < n; i++) {
        cout << "Cita : " << i + 1 << endl;
        cout << "CI del paciente: " << citas[i].CiPaciente << endl;
        cout << "CI del doctor: " << citas[i].CiDoctor << endl;
        cout << "Fecha: " << citas[i].fecha << endl;
        cout << "Hora: " << citas[i].hora << endl;
        cout << "________________________________________________________" << endl;
    }
    system("pause");
    system("cls");
}

void eliminarCita(Cita citas[], int &n) {
    cout << "________________________________________________________" << endl;
    cout << "Eliminar Cita" << endl;
    cout << "________________________________________________________" << endl;
    string CiPaciente, CiDoctor;
    cout << "Ingrese CI del paciente: ";
    cin >> CiPaciente;
    cout << "Ingrese CI del doctor: ";
    cin >> CiDoctor;

    for(int i = 0; i < n; i++) {
        if(citas[i].CiPaciente == CiPaciente && citas[i].CiDoctor == CiDoctor) {
            for(int j = i; j < n - 1; j++) {
                citas[j] = citas[j + 1]; // se reemplaza la cita a eliminar por la siguiente cita
            }
            n--;
            cout << "Cita eliminada correctamente" << endl;
            system("pause");
            system("cls");
            break;
        }
    }
    cout << "Cita no encontrada" << endl;
    system("pause");
    system("cls");
}


void guardarDatos(Paciente pacientes[], int n, Doctor doctores[], int m, Cita citas[], int o) {
    cout << "Guardando datos..." << endl;
    FILE *archivo = fopen("datos.txt", "w");

    if(archivo == NULL) {
        cout << "Error al abrir el archivo" << endl;
        return;
    }

    fprintf(archivo, "%d\n", n);
    for(int i = 0; i < n; i++) {
        fprintf(archivo, "%s %s %s\n", pacientes[i].Ci.c_str(), pacientes[i].nombre.c_str(), pacientes[i].apellido.c_str());
    }

    fprintf(archivo, "%d\n", m);
    for(int i = 0; i < m; i++) {
        fprintf(archivo, "%s %s %s\n", doctores[i].Ci.c_str(), doctores[i].nombre.c_str(), doctores[i].apellido.c_str());
    }

    fprintf(archivo, "%d\n", o);
    for(int i = 0; i < o; i++) {
        fprintf(archivo, "%s %s %s %s\n", citas[i].CiPaciente.c_str(), citas[i].CiDoctor.c_str(), citas[i].fecha.c_str(), citas[i].hora.c_str());
    }

    fclose(archivo);
    cout << "Datos guardados correctamente" << endl;
}

void cargarDatos(Paciente pacientes[], int &n, Doctor doctores[], int &m, Cita citas[], int &o) {
    cout << "Cargando datos..." << endl;
    FILE *archivo = fopen("datos.txt", "r");

    if(archivo == NULL) {
        cout << "Error al abrir el archivo" << endl;
        return;
    }

    fscanf(archivo, "%d\n", &n);
    for(int i = 0; i < n; i++) {
        fscanf(archivo, "%s %s %s\n", pacientes[i].Ci.c_str(), pacientes[i].nombre.c_str(), pacientes[i].apellido.c_str());
    }

    fscanf(archivo, "%d\n", &m);
    for(int i = 0; i < m; i++) {
        fscanf(archivo, "%s %s %s\n", doctores[i].Ci.c_str(), doctores[i].nombre.c_str(), doctores[i].apellido.c_str());
    }

    fscanf(archivo, "%d\n", &o);
    for(int i = 0; i < o; i++) {
        fscanf(archivo, "%s %s %s %s\n", citas[i].CiPaciente.c_str(), citas[i].CiDoctor.c_str(), citas[i].fecha.c_str(), citas[i].hora.c_str());
    }

    fclose(archivo);
    cout << "Datos cargados correctamente" << endl;
}




