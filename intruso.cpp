#include "intruso.hpp"
using namespace std;

void Intruso::set_senha_vazada(string vazou){ //1 7 3 9 0 8 5 6 2 4 B C E A E B 
                                              //9 0 7 5 8 4 6 2 3 1 E C C B D A
    letraA= letraA + vazou[0] + vazou[1]; // 1 7 9 0 // 0 1 2 3
    letraB= letraB + vazou[2] + vazou[3];
    letraC= letraC + vazou[4] + vazou[5];
    letraD= letraD + vazou[6] + vazou[7];
    letraE= letraE + vazou[8] + vazou[9];
    int i;
    for(i=10; i<vazou.size(); i++){
        if(vazou[i]=='A'){
            possi_senha=possi_senha + letraA[2*contador + 0] + letraA[2*contador + 1];
        }
        if(vazou[i]=='B'){
            possi_senha=possi_senha + letraB[2*contador + 0] + letraB[2*contador + 1];
        }
        if(vazou[i]=='C'){
            possi_senha=possi_senha + letraC[2*contador + 0] + letraC[2*contador + 1];
        }
        if(vazou[i]=='D'){
            possi_senha=possi_senha + letraD[2*contador + 0] + letraD[2*contador + 1];
        }
        if(vazou[i]=='E'){
            possi_senha=possi_senha + letraE[2*contador + 0] + letraE[2*contador + 1];
        }
    }
    //no final da segunda vez que for rodado possi_senha vai ser igual a 3 9 0 8 2 4 1 7 2 4 3  9/  3  1  8  4  8  4  7  5  6  2  9  0
    contador++;                                                      //  0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23
} 
                                                // 12*(i-1) + j  == 12*i + j        2 == 14 
string Intruso::crack_senha(){                  // 12*(i-1) + i + j == 12*i + 1 + j    3 == 15          2   14
    int nume_entradas, i, j;                    // 12*(i-1) + j == 12*i + i + j    2 == 15              3   15
                                                // 12*(i-1) + i + j == 12*i + j    3 == 14
    std::string senha_correta;
    nume_entradas =  (possi_senha.size())/12;
    for(i=1; i<nume_entradas; i++){
       for(j=0; j< 12; j+2){
            if(possi_senha[12*(i-1) + j] == possi_senha[12*i + j]){
                senha_correta=senha_correta + possi_senha[12*i + j];
            }
            if(possi_senha[12*(i-1) + i + j ] == possi_senha[12*i + 1 + j ]){
                senha_correta=senha_correta + possi_senha[12*i + 1 + j ];
            }
            if(possi_senha[12*(i-1) + j] == possi_senha[12*i + i + j]){
                senha_correta=senha_correta + possi_senha[12*i + i + j];
            }
            if(possi_senha[12*(i-1) + i + j] == possi_senha[12*i + j]){
                senha_correta=senha_correta + possi_senha[12*i + j];
            }
            
       }
    }
    return senha_correta;
}