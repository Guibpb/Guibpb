def doidera(palavra):
    print(f"eu amo {palavra.upper()} demais da conta\n")

def printa(palavra):
    print("eu amo ", palavra, " demais da conta\n")
    doidera(palavra)

if __name__ == '__main__':
    teste = input("Insira algo fds kk\n")

    printa(teste)