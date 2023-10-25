#include <iostream>
#include <vector>

using namespace std;

class Paciente {
private:
    string nome;
    string cpf;
    string dataNascimento;
    string convenio;

public:
//Construtor
   Paciente(string nome, string cpf, string dataNascimento, string convenio)
        : nome(nome), cpf(cpf), dataNascimento(dataNascimento), convenio(convenio) {
    }
    /// Metodos Getters
    string getNome()const{  return nome; }
    string getCPF() const { return cpf; }
    string getDataNascimento() const { return dataNascimento; }
    string getConvenio() const {return convenio;}

    // Métodos Setters
    void setNome(string& nome) {this->nome = nome; }
    void setCPF(string& cpf) {this->cpf = cpf;}
    void setDataNascimento(string& dataNascimento) { this->dataNascimento = dataNascimento;}
    void setConvenio(string& convenio) {  this->convenio = convenio;}

 };       
class Medico {
private:
    string nome;
    string crm;
    string especialidade;

public:
//construtor
    Medico(string nome, string crm,string especialidade)
        : nome(nome), crm(crm) , especialidade(especialidade){
    }
    /// Metodos Getters
    string getNome()const{  return nome; }
    string getCRM() const { return crm; }
    string getEspecialidade() const { return especialidade;}
 // Métodos Setters
    void setNome(string& nome) {this->nome = nome; }
    void setCRM(string& crm) {this->crm = crm;}
    void setEspecialidade(string& especialidade) {this->especialidade = especialidade;}
};

vector<Paciente> pacientes;
vector<Medico> medicos;

void incluirPaciente() {
    string nome, cpf, dataNascimento, convenio;
    
    cout << "Nome do paciente: ";
    cin >> nome;
    cout << "CPF do paciente: ";
    cin >> cpf;
    cout << "Data de nascimento (DD/MM/AAAA): ";
    cin >> dataNascimento;
    cout << "Convenio: ";
    cin >> convenio;
    
    Paciente paciente(nome, cpf, dataNascimento, convenio);
    pacientes.push_back(paciente);
    
    cout << "Paciente incluido com sucesso." << endl;
}

void excluirPaciente() {
    string cpf;
    cout << "CPF do paciente a ser excluído: ";
    cin >> cpf;
    for (size_t i = 0; i < pacientes.size(); ++i) {
        if (pacientes[i].getCPF() == cpf) {
            pacientes.erase(pacientes.begin() + i);
            cout << "Paciente excluido com sucesso." << endl;
            return;
        }
    }
    cout << "Paciente não encontrado." << endl;
}

void alterarPaciente() {
    string cpf;
    cout << "CPF do paciente a ser alterado: ";
    cin >> cpf;
    for (size_t i = 0; i < pacientes.size(); ++i) {
        if (pacientes[i].getCPF() == cpf) {
            cout << "Dados atuais do paciente:" << endl;
            cout << "Nome: " << pacientes[i].getNome() << endl;
            cout << "Data de nascimento: " << pacientes[i].getDataNascimento() << endl;
            char opcao;
            cout << "Deseja alterar o nome (S/N)? ";
            cin >> opcao;
            if (opcao == 'S' || opcao == 's') {
                string novoNome;
                cout << "Novo nome: ";
                cin >> novoNome;
                pacientes[i].setNome(novoNome);
            }
            string novaData;
            cout << "Deseja alterar a Data de Nascimento (S/N)? ";
            cin >> opcao;
            if (opcao == 'S' || opcao == 's')
            {
                cout << "Nova Data de Nascimento (DD/MM/AAAA): ";
                cin >> novaData;
                pacientes[i].setDataNascimento(novaData);
            }
            cout << "Paciente alterado com sucesso." << endl;
            return;
        }
    }
    cout << "Paciente não encontrado." << endl;
}

void listarPacientes() {
    if (pacientes.empty()) {
        cout << "Nenhum paciente cadastrado." << endl;
    } else {
        cout << "Lista de pacientes:" << endl;
        for (const Paciente& paciente : pacientes) {
            cout << "Nome: " << paciente.getNome() << ", CPF: " << paciente.getCPF() << ", Data de Nascimento: " << paciente.getDataNascimento() << ", Convenio: " << paciente.getConvenio() << endl;
        }
    }
}


void localizarPaciente() {
    string cpf;
    cout << "CPF do paciente a ser localizado: ";
    cin >> cpf;

    for (const Paciente& paciente : pacientes) {
        if (paciente.getCPF() == cpf) {
            cout << "Paciente encontrado:" << endl;
            cout << "Nome: " << paciente.getNome() << endl;
            cout << "CPF: " << paciente.getCPF() << endl;
            cout << "Data de Nascimento: " << paciente.getDataNascimento() << endl;
            cout << "Convênio: " << paciente.getConvenio() << endl;
            return;
        }
    }

    cout << "Paciente não encontrado." << endl;
}

void incluirMedico() {
    string nome, crm,especialidade;

    
    cout << "Nome do médico: ";
    cin >> nome;
    cout << "CRM do médico: ";
    cin >> crm;
    cout << "Especialidade do medico: ";
    cin >> especialidade;
    Medico medico(nome, crm, especialidade);
    medicos.push_back(medico);
    cout << "Medico incluido com sucesso." << endl;
}



void excluirMedico() {
    string crm;
    cout << "CRM do medico a ser excluído: ";
    cin >> crm;
    for (size_t i = 0; i < medicos.size(); ++i) {
        if (medicos[i].getCRM() == crm) {
            medicos.erase(medicos.begin() + i);
            cout << "Medico excluido com sucesso." << endl;
            return;
        }
    }
    cout << "Medico não encontrado." << endl;
}

void alterarMedico() {
    string crm;
    cout << "CRM do medico a ser alterado: ";
    cin >> crm;
    for (size_t i = 0; i < medicos.size(); ++i) {
        if (medicos[i].getCRM() == crm) {
            cout << "Dados atuais do médico:" << endl;
            cout << "Nome: " << medicos[i].getNome() << endl;
            cout << "Especialidade: " << medicos[i].getEspecialidade() << endl;
            char opcao;
            cout << "Deseja alterar o nome (S/N)? ";
            cin >> opcao;
            if (opcao == 'S' || opcao == 's') {
                string novoNome;
                cout << "Novo nome: ";
                cin >> novoNome;
                medicos[i].setNome(novoNome);
                
            }
            cout << "Deseja alterar a Especialidade (S/N)? ";
            char escolha;
            cin >> escolha;
            if (escolha == 'S' || escolha == 's')
            {
                cout << "Nova Especialidade: ";
                string novaEspecialidade;
                cout << "Nova especialidade: ";
                cin >> novaEspecialidade;
                medicos[i].setEspecialidade(novaEspecialidade);
            }
            cout << "Medico alterado com sucesso." << endl;
            return;
        }
    }
    cout << "Medico não encontrado." << endl;
}

void listarMedicos() {
    if (medicos.empty()) {
        cout << "Nenhum medico cadastrado." << endl;
    } else {
        cout << "Lista de medicos:" << endl;
        for (const Medico& medico : medicos) {
            cout << "Nome: " << medico.getNome() << ", CRM: " << medico.getCRM() << endl;
        }
    }
}

void localizarMedico() {
    string crm;
    cout << "CRM do medico a ser localizado: ";
    cin >> crm;
    for (const Medico& medico : medicos) {
        if (medico.getCRM() == crm) {
            std::cout << "Nome: " << medico.getNome() << endl;
            return;
        }
    }
    cout << "Médico não encontrado." << endl;
}

int main() {
    while (true) {
        cout << "\n--------Bem vindo a Clinica Medica Sem Dodoi Ltda----------" << endl;
        cout << "Menu de Opcoes:" << endl;
        cout << "1. Pacientes" << endl;
        cout << "2. Medicos" << endl;
        cout << "0. Sair" << endl;
        cout << "-------------------------------------------------------------" << endl;
        int menu;
        cin >> menu;

        if (menu == 1) {
            while (true) {
                cout << "\nMenu de Pacientes:" << endl;
                cout << "1. Incluir" << endl;
                cout << "2. Excluir" << endl;
                cout << "3. Alterar" << endl;
                cout << "4. Listar" << endl;
                cout << "5. Localizar" << endl;
                cout << "0. Voltar" << endl;

                int opcao_pacientes;
                cin >> opcao_pacientes;

                if (opcao_pacientes == 1) {
                    incluirPaciente();
                } else if (opcao_pacientes == 2) {
                    excluirPaciente();
                } else if (opcao_pacientes == 3) {
                    alterarPaciente();
                } else if (opcao_pacientes == 4) {
                    listarPacientes();
                } else if (opcao_pacientes == 5) {
                    localizarPaciente();
                } else if (opcao_pacientes == 0) {
                    break;
                } else {
                    cout << "Opção inválida. Tente novamente." << endl;
                }
            }
        } else if (menu == 2) {
            while (true) {
                cout << "\nMenu de Medicos:" << endl;
                cout << "1. Incluir" << endl;
                cout << "2. Excluir" << endl;
                cout << "3. Alterar" << endl;
                cout << "4. Listar" << endl;
                cout << "5. Localizar" << endl;
                cout << "0. Voltar" << endl;

                int opcao_medicos;
                cin >> opcao_medicos;

                if (opcao_medicos == 1) {
                    incluirMedico();
                } else if (opcao_medicos == 2) {
                    excluirMedico();
                } else if (opcao_medicos == 3) {
                    alterarMedico();
                } else if (opcao_medicos == 4) {
                    listarMedicos();
                } else if (opcao_medicos == 5) {
                    localizarMedico();
                } else if (opcao_medicos == 0) {
                    break;
                } else {
                    cout << "Opção inválida. Tente novamente." << endl;
                }
            }
        } else if (menu == 0) {
            break;
        } else {
            cout << "Opção inválida. Tente novamente." << endl;
        }
    }

    return 0;
}
