// Lista 3, exercicio 3

public class Mesa {
    private final int MAX_PESSOAS_POR_MESA = 10; // capacidade maxima de pessoas por mesa
    private Cliente [] clientes;

    public Mesa() {
        this.clientes = new Cliente[MAX_PESSOAS_POR_MESA];
    }

    // Adiciona pessoa na mesa, adicionando novo nome
    public void addPessoaNaMesa(String nome_cliente) {
        if (Cliente.getNroClientes() < this.MAX_PESSOAS_POR_MESA) { // se ainda houver espaco na mesa
            Cliente novo_cliente = new Cliente(nome_cliente);
            this.clientes[Cliente.getNroClientes()-1] = novo_cliente;
        }
    }

    // Remove pessoa na mesa, dado seu nome
    public double removePessoaNaMesa(String nome_cliente){
        double valor_total_conta = 0;

        for (int i = 0; i < Cliente.getNroClientes(); i++) {
            if (this.clientes[i].getNome().equals(nome_cliente)) {
                valor_total_conta = this.clientes[i].calculaTotalConta();
                this.clientes[i] = null; // remove cliente

                for (int j = i; j < Cliente.getNroClientes() - 1; j++) {
                    this.clientes[j] = this.clientes[j + 1]; // realoca demais clientes
                }
                
                Cliente.decrementaClientes(); // decrementa o contador de clientes
                break;
            }
        }

        return valor_total_conta;
    }

    // Adiciona novo item à mesa, e divide os valores entre os clientes atuais
    public void adicionaItemConta(double valor) {
        for (int i = 0; i < Cliente.getNroClientes(); i++) {
            // adiciona o valor a cada pessoa na mesa, correspondente à divisão do valor total
            this.clientes[i].adicionaValor(valor / Cliente.getNroClientes());
        }
    }

    // Exibe o total de todos da mesa
    public void fechaConta(){
        System.out.println("--");
        System.out.println("\nFechamento da conta\n");
        
        for (int i = 0; i < Cliente.getNroClientes(); i++) {
            System.out.println("\t - Cliente: " + this.clientes[i].getNome() + " \t Total da conta: " + this.clientes[i].calculaTotalConta());
        }
        System.out.println("--");
    }
}