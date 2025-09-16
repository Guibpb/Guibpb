// Lista 3, exercicio 3

import java.util.Scanner;

public class TesteContaMesa {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        Mesa mesa = new Mesa();
        int opcao = 0;
        boolean comanda_aberta = true;
        String nome;
        
        while (comanda_aberta){
            
            printaMenu();
            
			opcao = Integer.parseInt(sc.nextLine());

            switch (opcao){
                case 0:
                    comanda_aberta=false;
                    break;
                case 1:
                    System.out.println("\n>Digite o nome do cliente:");
                    nome = sc.nextLine();
                    mesa.addPessoaNaMesa(nome);
                    break;
                case 2:
                    System.out.println("\n>Digite o nome do cliente a ser removido:");
                    nome = sc.nextLine();
                    double total_cliente = mesa.removePessoaNaMesa(nome);
                    System.out.println("\n\t Total da conta do cliente: " + total_cliente);
                    break;
                case 3:
                    System.out.println("\n>Digite o valor total do item:");
                    double valor = Double.parseDouble(sc.nextLine());
                    mesa.adicionaItemConta(valor);
                    break;
                case 4:
                    mesa.fechaConta();
                    comanda_aberta = false;
                    break;
                default:
                    System.out.println("Opção invalida");
                    break;
            }

            System.out.println();
            
        }
    }

    private static void printaMenu(){
        System.out.println("\n------ MENU ------");
        System.out.println("Digite a opção desejada:");
        System.out.println("1. Adicionar cliente na mesa");
        System.out.println("2. Remover cliente da mesa e fechar sua conta");
        System.out.println("3. Adicionar item a conta");
        System.out.println("4. Encerrar");
        System.out.println("------------------");
        System.out.println();
        System.out.print(">> Opcao: ");
    }
}