#include <iostream>
#include <vector>
#include <string>

void bubbleSort(std::vector<std::string> &nomes, std::vector<float> &notas) {
    int N = nomes.size();
    for (int i = 0; i < N - 1; ++i) {
        for (int j = 0; j < N - i - 1; ++j) {
            if (nomes[j] > nomes[j + 1]) {
                std::swap(nomes[j], nomes[j + 1]);
                std::swap(notas[j * 2], notas[j * 2 + 1]);
            }
        }
    }
}

int main() {
    int N;
    std::cout << "Digite o limite de alunos (N): ";
    std::cin >> N;

    std::vector<std::string> nomes;
    std::vector<float> notas;

    char incluirMais;
    do {
        std::string nome;
        float nota1, nota2;

        std::cout << "Digite o nome do aluno: ";
        std::cin.ignore(); // Limpar o buffer de entrada
        std::getline(std::cin, nome);

        std::cout << "Digite a primeira nota do aluno: ";
        std::cin >> nota1;

        std::cout << "Digite a segunda nota do aluno: ";
        std::cin >> nota2;

        nomes.push_back(nome);
        notas.push_back(nota1);
        notas.push_back(nota2);

        // Ordenar os nomes dos alunos lexicograficamente
        bubbleSort(nomes, notas);

        std::cout << "Deseja incluir mais alunos (s/n)? ";
        std::cin >> incluirMais;
    } while (incluirMais == 's' || incluirMais == 'S');

    std::cout << "\nResultado final dos alunos:\n";
    for (int i = 0; i < nomes.size(); ++i) {
        float media = (notas[i * 2] + notas[i * 2 + 1]) / 2.0;
        std::cout << "Aluno: " << nomes[i] << ", Nota 1: " << notas[i * 2] << ", Nota 2: " << notas[i * 2 + 1] << ", Média: " << media << " - ";
        if (media >= 7) {
            std::cout << "Aprovado\n";
        } else {
            std::cout << "Reprovado\n";
        }
    }

    return 0;
}
