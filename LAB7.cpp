#include <iostream>
#include <fstream>
#include <sstream>
#include <unordered_map>
#include <queue>
#include <string>

struct HuffmanNode {
    char simbolo;
    int frecuencia;
    HuffmanNode* izquierda;
    HuffmanNode* derecha;

    HuffmanNode(char s, int f) : simbolo(s), frecuencia(f), izquierda(nullptr), derecha(nullptr) {}
};

struct Comparador {
    bool operator()(HuffmanNode* a, HuffmanNode* b) {
        return a->frecuencia > b->frecuencia;
    }
};

std::unordered_map<char, int> contarFrecuencias(const std::string& texto) {
    std::unordered_map<char, int> frecuencias;
    for (char c : texto) {
        frecuencias[c]++;
    }
    return frecuencias;
}

HuffmanNode* construirArbol(const std::unordered_map<char, int>& frecuencias) {
    std::priority_queue<HuffmanNode*, std::vector<HuffmanNode*>, Comparador> cola;
    for (auto par : frecuencias) {
        cola.push(new HuffmanNode(par.first, par.second));
    }

    while (cola.size() > 1) {
        HuffmanNode* izq = cola.top(); cola.pop();
        HuffmanNode* der = cola.top(); cola.pop();
        HuffmanNode* nodo = new HuffmanNode('\0', izq->frecuencia + der->frecuencia);
        nodo->izquierda = izq;
        nodo->derecha = der;
        cola.push(nodo);
    }

    return cola.top();
}

void generarCodigos(HuffmanNode* nodo, std::string codigo, std::unordered_map<char, std::string>& codigos) {
    if (!nodo) return;
    if (!nodo->izquierda && !nodo->derecha) {
        codigos[nodo->simbolo] = codigo;
    }
    generarCodigos(nodo->izquierda, codigo + "0", codigos);
    generarCodigos(nodo->derecha, codigo + "1", codigos);
}

std::string codificarTexto(const std::string& texto, const std::unordered_map<char, std::string>& codigos) {
    std::string resultado;
    for (char c : texto) {
        resultado += codigos.at(c);
    }
    return resultado;
}

std::string decodificarTexto(const std::string& binario, HuffmanNode* raiz) {
    std::string resultado;
    HuffmanNode* actual = raiz;
    for (char bit : binario) {
        actual = (bit == '0') ? actual->izquierda : actual->derecha;
        if (!actual->izquierda && !actual->derecha) {
            resultado += actual->simbolo;
            actual = raiz;
        }
    }
    return resultado;
}

void calcularTasaCompresion(const std::string& original, const std::string& codificado) {
    int bits_original = original.size() * 8;
    int bits_codificado = codificado.size();
    double tasa = (double)bits_codificado / bits_original;
    std::cout << "Bits del archivo original: " << bits_original << std::endl;
    std::cout << "Bits del archivo codificado: " << bits_codificado << std::endl;
    std::cout << "Tasa de compresión: " << tasa << std::endl;
}

std::string leerArchivo(const std::string& nombre) {
    std::ifstream archivo(nombre);
    if (!archivo) {
        std::cerr << "No se pudo abrir el archivo: " << nombre << std::endl;
        exit(1);
    }
    std::stringstream buffer;
    buffer << archivo.rdbuf();
    return buffer.str();
}

void escribirArchivo(const std::string& nombre, const std::string& contenido) {
    std::ofstream archivo(nombre);
    archivo << contenido;
}

int main() {
    std::string texto = leerArchivo("texto.txt");
    auto frecuencias = contarFrecuencias(texto);
    HuffmanNode* raiz = construirArbol(frecuencias);

    std::unordered_map<char, std::string> codigos;
    generarCodigos(raiz, "", codigos);

    std::string codificado = codificarTexto(texto, codigos);
    escribirArchivo("codificado.txt", codificado);

    calcularTasaCompresion(texto, codificado);

    std::string leido = leerArchivo("codificado.txt");
    std::string decodificado = decodificarTexto(leido, raiz);

    std::cout << "\nTexto decodificado:\n" << decodificado << std::endl;

    return 0;
}
