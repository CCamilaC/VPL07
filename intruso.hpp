#include <iostream> 
#include <string>
#include <map>
#include <vector>
#define TAM 25

class Intruso{
    /*Continue a implementação da classe Intruso*/
    private:
        std::map<char,std::vector<int>> _letras;

        std::string letraA;
        std::string letraB;
        std::string letraC;
        std::string letraD;
        std::string letraE;
        std::string possi_senha[TAM];
        //std::string posicao_senha[TAM];
    

        int contador=0;

    public:
        void set_senha_vazada(std::string vazou);
        std::string crack_senha();
};