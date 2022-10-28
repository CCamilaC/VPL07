#include "intruso.hpp"
using namespace std;

void Intruso::set_senha_vazada(string vazou){ 
    
    letras ['A'] = {1,7};
    letras ['B'] = {3,9};
    letras ['C'] = {0,8};
    letras ['D'] = {5,6};
    letras ['E'] = {2,4};
    _letras = vazou;
} 