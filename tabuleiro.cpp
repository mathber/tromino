#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

void inicializaTabuleiro(vector<vector<int>> &tabuleiro, int n)
{
    int tam = pow(2, n);
    tabuleiro.resize(tam);
    for (int i = 0; i < tam; i++)
    {
        tabuleiro[i].resize(tam, 0);
    }
}

void imprimeTabuleiro(vector<vector<int>> &tabuleiro, int tam)
{
    cout << "Tabuleiro:" << endl << endl << "   ";
    for(int i = 0; i < tam; i++){
        cout << i << " ";
    }
    cout << endl << endl;
    for (int i = 0; i < tam; i++)
    {
        cout << i << "  ";
        for (int j = 0; j < tam; j++)
        {
            cout << tabuleiro[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void tromino(vector<vector<int>> &tabuleiro, int x, int y, int tam, int cont_x, int cont_y)
{
    if (tam == 2)
    {        
        cout << "> Posicione o tromino ocupando as posicoes " ;
        for (int i = 0; i < 2; i++)
        {
            for (int j = 0; j < 2; j++)
            {
                if (tabuleiro[cont_x + i][cont_y + j] == 0)
                {
                    tabuleiro[cont_x + i][cont_y + j] = 1;
                    cout << "[" << cont_x + i << ", " << cont_y + j << "]";
                }
            }
        }

        cout << "\n\n";
        imprimeTabuleiro(tabuleiro, tabuleiro.size());

        return;
    }
    else
    {
        tam = tam / 2;

        int x_aux = tam + cont_x;
        int y_aux = tam + cont_y;

        int x1, y1, x2, y2, x3, y3, x4, y4;

        // Primeiro Quadrante
        if (x < x_aux and y >= y_aux)
        {
            x1 = x;
            y1 = y;
            x2 = x_aux - 1;
            y2 = y_aux - 1;
            x3 = x_aux;
            y3 = y_aux - 1;
            x4 = x_aux;
            y4 = y_aux;

            tabuleiro[x2][y2] = 1;
            tabuleiro[x3][y3] = 1;
            tabuleiro[x4][y4] = 1;

            cout << "> Posicione o tromino ocupando as posicoes [" << x2 << ", " << y2 << "]" << "[" << x3 << ", " << y3 << "]" << "[" << x4 << ", " << y4 << "]\n\n";
        }
        // Segundo Quadrante
        else if (x < x_aux and y < y_aux)
        {
            x1 = x_aux - 1;
            y1 = y_aux;
            x2 = x;
            y2 = y;
            x3 = x_aux;
            y3 = y_aux - 1;
            x4 = x_aux;
            y4 = y_aux;

            tabuleiro[x1][y1] = 1;
            tabuleiro[x3][y3] = 1;
            tabuleiro[x4][y4] = 1;

            cout << "> Posicione o tromino ocupando as posicoes [" << x1 << ", " << y1 << "]" << "[" << x3 << ", " << y3 << "]" << "[" << x4 << ", " << y4 << "]\n\n";
        }
        // Terceiro Quadrante
        else if (x >= x_aux and y < y_aux)
        {
            x1 = x_aux - 1;
            y1 = y_aux;
            x2 = x_aux - 1;
            y2 = y_aux - 1;
            x3 = x;
            y3 = y;
            x4 = x_aux;
            y4 = y_aux;

            tabuleiro[x1][y1] = 1;
            tabuleiro[x2][y2] = 1;
            tabuleiro[x4][y4] = 1;

            cout << "> Posicione o tromino ocupando as posicoes [" << x1 << ", " << y1 << "]" << "[" << x2 << ", " << y2 << "]" << "[" << x4 << ", " << y4 << "]\n\n";
        }
        // Quarto Quadrante
        else if (x >= x_aux and y >= y_aux)
        {
            x1 = x_aux - 1;
            y1 = y_aux;
            x2 = x_aux - 1;
            y2 = y_aux - 1;
            x3 = x_aux;
            y3 = y_aux - 1;
            x4 = x;
            y4 = y;

            tabuleiro[x1][y1] = 1;
            tabuleiro[x2][y2] = 1;
            tabuleiro[x3][y3] = 1;

            cout << "> Posicione o tromino ocupando as posicoes [" << x1 << ", " << y1 << "]" << "[" << x2 << ", " << y2 << "]" << "[" << x3 << ", " << y3 << "]\n\n";
        }

        imprimeTabuleiro(tabuleiro, tabuleiro.size());

        tromino(tabuleiro, x1, y1, tam, cont_x, cont_y+tam);
        tromino(tabuleiro, x2, y2, tam, cont_x, cont_y);
        tromino(tabuleiro, x3, y3, tam, cont_x+tam, cont_y);
        tromino(tabuleiro, x4, y4, tam, cont_x+tam, cont_y+tam);
    }
}

int main()
{

    int n, x_p, y_p;
    vector<vector<int>> tabuleiro;

    cout << "Insira um numero 'n' tal que 2 elevado a n seja o tamanho do tabuleiro: ";
    cin >> n;

    inicializaTabuleiro(tabuleiro, n);
    imprimeTabuleiro(tabuleiro, pow(2, n));

    cout << "Insira um valor x e y que represente uma posicao preenchida no tabuleiro:" << endl;
    cout << "X: ";
    cin >> x_p;
    cout << "Y: ";
    cin >> y_p;

    tabuleiro[x_p][y_p] = 9;
    tromino(tabuleiro, x_p, y_p, pow(2, n), 0, 0);
    
}