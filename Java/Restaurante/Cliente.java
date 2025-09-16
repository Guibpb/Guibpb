
// Lista 3, exercicio 3

public class Cliente {
    private String nome;
    private double valor_conta;
    private static int nro_clientes = 0;

    public Cliente(String nome) {
        this.nome = nome;
        this.valor_conta = 0;
        nro_clientes++;
    }

    public void adicionaValor(double valor) {
        this.valor_conta += valor;
    }

    public String getNome() {
        return this.nome;
    }

    public static int getNroClientes() {
        return nro_clientes;
    }

    public double calculaTotalConta() {
        return (this.valor_conta + (this.valor_conta * 0.1)); // adiciona os 10% de servico
    }

    public static void decrementaClientes() {
        nro_clientes--;
    }
}