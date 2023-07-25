def exibir_tabuleiro(tabuleiro):
    print(tabuleiro[0] + '|' + tabuleiro[1] + '|' + tabuleiro[2])
    print('-+-+-')
    print(tabuleiro[3] + '|' + tabuleiro[4] + '|' + tabuleiro[5])
    print('-+-+-')
    print(tabuleiro[6] + '|' + tabuleiro[7] + '|' + tabuleiro[8])

def verificar_vitoria(tabuleiro, jogador):
    linhas_vitoria = [
        [0, 1, 2], [3, 4, 5], [6, 7, 8],  # linhas
        [0, 3, 6], [1, 4, 7], [2, 5, 8],  # colunas
        [0, 4, 8], [2, 4, 6]  # diagonais
    ]

    for linha in linhas_vitoria:
        if tabuleiro[linha[0]] == tabuleiro[linha[1]] == tabuleiro[linha[2]] == jogador:
            return True
    return False

def jogo_da_velha():
    tabuleiro = [" "] * 9
    jogador_atual = "X"
    jogo_em_andamento = True

    while jogo_em_andamento:
        print("\nTabuleiro atual:")
        exibir_tabuleiro(tabuleiro)

        while True:
            escolha = input(f"Jogador {jogador_atual}, escolha uma posição (0-8): ")
            if not escolha.isdigit() or int(escolha) < 0 or int(escolha) > 8 or tabuleiro[int(escolha)] != " ":
                print("Jogada inválida. Tente novamente.")
            else:
                break

        escolha = int(escolha)
        tabuleiro[escolha] = jogador_atual

        if verificar_vitoria(tabuleiro, jogador_atual):
            print("\nTabuleiro final:")
            exibir_tabuleiro(tabuleiro)
            print(f"Jogador {jogador_atual} venceu!")
            jogo_em_andamento = False
        elif " " not in tabuleiro:
            print("\nTabuleiro final:")
            exibir_tabuleiro(tabuleiro)
            print("Empate!")
            jogo_em_andamento = False
        else:
            jogador_atual = "X" if jogador_atual == "O" else "O"

if __name__ == "__main__":
    print("Bem-vindo ao Jogo da Velha!")
    jogo_da_velha()
