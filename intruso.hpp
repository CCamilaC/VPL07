#include <string>
#include <map>
#include <vector>

class Intruso{
    /*Continue a implementação da classe Intruso*/
    private:
        std::map<char,std::vector<int>> _letras;

    public:
        void set_senha_vazada(std::string vazou);
        std::string crack_senha();
};