#include <iostream>
#include <fstream>

using namespace std;

int main(){
    
    ifstream option("options.config");
    

    if (!option) {
        cerr << "No se pudo abrir el archivo\n" << "Verifica que exista y que se pueda leer\n" << endl;
        return 1;
    }
    
    pair <string, string> connection = make_pair("err","err");
    string line;
    while (getline(option, line)) {
        if (line[0] == '#') {
            continue;
        }
        // if line starts with MONGODB, copy value to first
        if (line.find("MONGO_URI") == 0) {
            connection.first = line.substr(line.find(":") + 1);

        }
        // if line starts with MONGODB_DB, copy value to second
        if (line.find("DB_NAME") == 0) {
            connection.second = line.substr(line.find(":") + 1);
    }
    }
    if (connection.first == "err" || connection.second == "err") {
        cerr << "No se pudo leer la configuracion de la base de datos\n" << "Verifica que exista y que se pueda leer\n" << endl;
        return 1;
    }
    clog << "DEBUG 1: READS " <<connection.first << " " << connection.second << endl;
    

    
    option.close();
}
