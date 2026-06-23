#include <iostream>
#include <string>
 
int main() {
    
    std::string vetorNome[10];
    int vetorCartel[10];
    std::string vetorData[10];
    std::string vetorStatus[10];
    int totalRegistros = 0; 
    int opcao = 0;
 
    
    while (opcao != 6) {
        std::cout << "--- Selva TopFightMMA ---" << std::endl;
        std::cout << "1 - Registrar lutador pelo nome" << std::endl;
        std::cout << "2 - retirar do evento" << std::endl;
        std::cout << "3 - Buscar lutador pelo nome" << std::endl;
        std::cout << "4 - Listar todos os lutadores" << std::endl;
        std::cout << "5 - Exibir todos os lutadores ativos" << std::endl;
        std::cout << "6 - Sair" << std::endl;
        std::cout << "Escolha uma opcao: ";
        std::cin >> opcao;
        std::cin.ignore();
 
        if (opcao == 1) {
            
            if (totalRegistros < 10) {
                std::cout << "Nome do lutador: ";
                std::getline(std::cin, vetorNome[totalRegistros]);
                std::cout << "Cartel: ";
                std::cin >> vetorCartel[totalRegistros];
                std::cin.ignore();
                std::cout << "tempo de treino: ";
                std::getline(std::cin, vetorData[totalRegistros]);
                vetorStatus[totalRegistros] = "Ativo";
                totalRegistros++;
                std::cout << "lutador entrou no evento " << std::endl;
            } else {
                std::cout << "Erro: Time lotado" << std::endl;
            }
        } 
        else if (opcao == 2) {
          
            std::cout << "Digite o nome para cancelar: ";
            std::string nomeBusca;
            std::getline(std::cin, nomeBusca);
            int achou = 0;
            for (int i = 0; i < totalRegistros; i++) {
                if (vetorNome[i] == nomeBusca) {
                    vetorStatus[i] = "Cancelada";
                    achou = 1;
                    std::cout << "lutador retirado" << std::endl;
                }
            }
            if (achou == 0) {
                std::cout << "lutador não encontrado" << std::endl;
            }
        } 
        else if (opcao == 3) {
            
            std::cout << "Digite o nome do lutador para buscar: ";
            std::string nomeBusca;
            std::getline(std::cin, nomeBusca);
            int achou = 0;
            for (int i = 0; i < totalRegistros; i++) {
                if (vetorNome[i] == nomeBusca) {
                    std::cout << "Nome: " << vetorNome[i] << std::endl;
                    std::cout << "Cartel: " << vetorCartel[i] << std::endl;
                    std::cout << "Tempo de treino: " << vetorData[i] << std::endl;
                    std::cout << "Status: " << vetorStatus[i] << std::endl;
                    achou = 1;
                }
            }
            if (achou == 0) {
                std::cout << "lutador nao encontrado" << std::endl;
            }
        } 
        else if (opcao == 4) {
            
            std::cout << "--- LISTA DE LUTADORES ---" << std::endl;
            if (totalRegistros == 0) {
                std::cout << "Nenhum lutador cadastrado." << std::endl;
            } else {
                for (int i = 0; i < totalRegistros; i++) {
                    std::cout << "Lutador: " << vetorNome[i] << "  Cartel: " << vetorCartel[i] << "  Tempo de treino: " << vetorData[i] << "  Status: " << vetorStatus[i] << std::endl;
                }
            }
        } 
        else if (opcao == 5) {
          
            int contAtivas = 0;
            for (int i = 0; i < totalRegistros; i++) {
                if (vetorStatus[i] == "Ativos") {
                    contAtivas++;
                }
            }
            std::cout << "Total de lutadores ativos: " << contAtivas << std::endl;
        } 
        else if (opcao == 6) {
            std::cout << "Fim!" << std::endl;
        } 
        else {
            std::cout << "Opcao incorreta!" << std::endl;
        }
    }
 
    return 0;
}