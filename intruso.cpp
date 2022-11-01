#include "intruso.hpp"
#include <string>
#include <iostream>
#include <vector>
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
            possi_senha[i-10]=possi_senha[i-10] + letraA[2*contador] + letraA[2*contador + 1];
        }
        if(vazou[i]=='B'){
            possi_senha[i-10]=possi_senha[i-10] + letraB[2*contador] + letraB[2*contador + 1];
        }
        if(vazou[i]=='C'){
            possi_senha[i-10]=possi_senha[i-10] + letraC[2*contador] + letraC[2*contador + 1];
        }
        if(vazou[i]=='D'){
            possi_senha[i-10]=possi_senha[i-10] + letraD[2*contador] + letraD[2*contador + 1];
        }
        if(vazou[i]=='E'){
            possi_senha[i-10]=possi_senha[i-10] + letraE[2*contador] + letraE[2*contador + 1];
        }
    }

    //no final da segunda vez que for rodado possi_senha vai ser igual a 3 9 0 8 2 4 1 7 2 4 3  9/  3  1  8  4  8  4  7  5  6  2  9  0
    contador++;                                                      //  0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23
} 
                                                // 12*(i-1) + j  == 12*i + j        2 == 14 
string Intruso::crack_senha(){                  // 12*(i-1) + i + j == 12*i + 1 + j    3 == 15          2   14
    int nume_entradas, i, j;                    // 12*(i-1) + j == 12*i + i + j    2 == 15              3   15
                                               // 12*(i-1) + i + j == 12*i + j    3 == 14

    string senha_correta; 
    int contador[6][10],maior, posMaior;//posicao versus a quantidade de cada numero
    //achando um erro nessa função
    for(i=0; i<6; i++){
        for(j=0; j<10; j++){
            contador[i][j]=0;
        }
    }

    for(i=0; i<6; i++){
       for(j=0; possi_senha[i][j]!='\0'; j++){
           if(possi_senha[i][j]=='0'){
            contador[i][0]++;//corresponde a quantas vezes repete o número 0;
           }
           if(possi_senha[i][j]=='1'){
            contador[i][1]++;//corresponde a quantas vezes repete o número 0;
           }
           if(possi_senha[i][j]=='2'){
            contador[i][2]++;//corresponde a quantas vezes repete o número 0;
           }
           if(possi_senha[i][j]=='3'){
            contador[i][3]++;//corresponde a quantas vezes repete o número 0;
           }
           if(possi_senha[i][j]=='4'){
            contador[i][4]++;//corresponde a quantas vezes repete o número 0;
           }
           if(possi_senha[i][j]=='5'){
            contador[i][5]++;//corresponde a quantas vezes repete o número 0;
           }
           if(possi_senha[i][j]=='6'){
            contador[i][6]++;//corresponde a quantas vezes repete o número 0;
           }
           if(possi_senha[i][j]=='7'){
            contador[i][7]++;//corresponde a quantas vezes repete o número 0;
           }
           if(possi_senha[i][j]=='8'){
            contador[i][8]++;//corresponde a quantas vezes repete o número 0;
           }
           if(possi_senha[i][j]=='9'){
            contador[i][9]++;//corresponde a quantas vezes repete o número 0;
           }
       }
        maior=contador[i][0];
        posMaior=0;
        for(j=0;j<10; j++){
            if(contador[i][j]>maior){
                maior=contador[i][j];
                posMaior=j+48;
            }
        }
        //cout<<posMaior<< " ";
        senha_correta=senha_correta + (char)posMaior;
    }
    /*cout<<" local da suposta senha:"<<senha_correta<<"apareceu algo?"<<endl;
    for(i=0; i<6; i++){
        for(j=0; j<10; j++){
            cout<<contador[i][j]<<" ";
        }
        cout<<endl;
    }*/
    return senha_correta;
}