public class Pessoa implements testavel {
    private String nome = "Guilherme";

    Pessoa(String nome){
        this.nome = nome;
    }

    public String getDados(){
        return this.nome;
    }
}