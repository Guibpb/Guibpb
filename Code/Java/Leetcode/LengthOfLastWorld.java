package Leetcode;
public class LengthOfLastWorld {
    public static void main(String[] args){
        String s = "tentando tentando testeabb";
        String a[] = s.split(" ");
        int tamanho = 0;
        int tamanhoString = a.length;
        tamanho = a[tamanhoString - 1].length();
        /*for(String palavra : a){
            tamanho = palavra.length();
        }*/
        System.out.println(tamanho);
    }
}
