public class Aluno extends Pessoa{
    private String matricula = "123";

    public Aluno(String nome, String matricula){
        super(nome);
        this.matricula = matricula;
    }

    @Override
    public String getDados(){
        String dados = super.getDados() + matricula;
        return dados;
    }
}
