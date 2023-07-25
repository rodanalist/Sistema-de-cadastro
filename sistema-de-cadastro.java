import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class CadastroClientes {
    private static List<Cliente> clientes = new ArrayList<>();

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        boolean continuar = true;

        while (continuar) {
            System.out.println("===== Sistema de Cadastro de Clientes =====");
            System.out.println("1 - Cadastrar cliente");
            System.out.println("2 - Exibir clientes cadastrados");
            System.out.println("3 - Sair");
            System.out.print("Escolha uma opção: ");
            int opcao = scanner.nextInt();

            switch (opcao) {
                case 1:
                    cadastrarCliente(scanner);
                    break;
                case 2:
                    exibirClientes();
                    break;
                case 3:
                    continuar = false;
                    break;
                default:
                    System.out.println("Opção inválida. Tente novamente.");
            }
        }

        scanner.close();
    }

    private static void cadastrarCliente(Scanner scanner) {
        System.out.print("Digite o nome do cliente: ");
        String nome = scanner.next();

        System.out.print("Digite o CPF do cliente: ");
        String cpf = scanner.next();

        System.out.print("Digite o endereço do cliente: ");
        String endereco = scanner.next();

        System.out.print("Digite o telefone do cliente: ");
        String telefone = scanner.next();

        Cliente cliente = new Cliente(nome, cpf, endereco, telefone);
        clientes.add(cliente);

        System.out.println("Cliente cadastrado com sucesso!\n");
    }

    private static void exibirClientes() {
        if (clientes.isEmpty()) {
            System.out.println("Não há clientes cadastrados.\n");
            return;
        }

        System.out.println("===== Clientes cadastrados =====");
        for (Cliente cliente : clientes) {
            System.out.println("Nome: " + cliente.getNome());
            System.out.println("CPF: " + cliente.getCpf());
            System.out.println("Endereço: " + cliente.getEndereco());
            System.out.println("Telefone: " + cliente.getTelefone());
            System.out.println("-----------------------------");
        }
        System.out.println();
    }
}

class Cliente {
    private String nome;
    private String cpf;
    private String endereco;
    private String telefone;

    // Construtor
    public Cliente(String nome, String cpf, String endereco, String telefone) {
        this.nome = nome;
        this.cpf = cpf;
        this.endereco = endereco;
        this.telefone = telefone;
    }

    // Métodos getters e setters
    public String getNome() {
        return nome;
    }

    public void setNome(String nome) {
        this.nome = nome;
    }

    public String getCpf() {
        return cpf;
    }

    public void setCpf(String cpf) {
        this.cpf = cpf;
    }

    public String getEndereco() {
        return endereco;
    }

    public void setEndereco(String endereco) {
        this.endereco = endereco;
    }

    public String getTelefone() {
        return telefone;
    }

    public void setTelefone(String telefone) {
        this.telefone = telefone;
    }
}
