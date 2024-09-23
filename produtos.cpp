#include <iostream>

using namespace std;

struct produto { // Estrutura que armazena as informações do produto
    string nome;
    float preco;
    int quantidade;
};

void adicionarProduto(produto produtos[], int& quantidadeAtual) { 
    cout << "Introduza o nome do produto: ";
    cin >> produtos[quantidadeAtual].nome;
    cout << "Introduza o preço do produto: ";
    cin >> produtos[quantidadeAtual].preco;
    cout << "Quantidade em stock: ";
    cin >> produtos[quantidadeAtual].quantidade;
    quantidadeAtual++; // Incrementa a quantidade de produtos no stock
}

void exibirProdutos(const produto produtos[], int quantidadeAtual) { 
    if (quantidadeAtual == 0) {
        cout << "Não há produtos no stock!" << endl;
        return;
    }
    for (int i = 0; i < quantidadeAtual; i++) {
        cout << "Produto " << (i + 1) << ":" << endl;
        cout << "Nome: " << produtos[i].nome << endl;
        cout << "Preço: " << produtos[i].preco << " €" << endl;
        cout << "Quantidade: " << produtos[i].quantidade << endl;
        cout << "------------------------" << endl;
    }
}

float calcularValorTotal(const produto produtos[], int quantidadeAtual) { 
    float valorTotal = 0.0;
    for (int i = 0; i < quantidadeAtual; i++) {
        valorTotal += produtos[i].preco * produtos[i].quantidade; // Calcula o valor total do stock
    }
    return valorTotal;
}

int main() {
    produto maxProdutos[100]; // Array para armazenar até 100 produtos
    int quantidadeAtual = 0;  // Contagem dos produtos inseridos no stock
    int escolha;

    do {
        cout << "\nMenu de Opções:" << endl;
        cout << "1. Adicionar Produto" << endl;
        cout << "2. Exibir Produtos" << endl;
        cout << "3. Calcular Valor Total do Stock" << endl;
        cout << "0. Sair" << endl;
        cout << "Escolha uma opção: ";
        cin >> escolha;

        switch (escolha) {
            case 1:
                adicionarProduto(maxProdutos, quantidadeAtual);
                break;
            case 2:
                exibirProdutos(maxProdutos, quantidadeAtual);
                break;
            case 3:
                cout << "Valor total do stock: " << calcularValorTotal(maxProdutos, quantidadeAtual) << " €" << endl;
                break;
            case 0:
                cout << "A sair do programa..." << endl;
                break;
            default:
                cout << "Opção inválida, tente outra vez." << endl;
        }
    } while (escolha != 0);

    return 0;
}
