package main

import (
	"fmt"
	"gonum.org/v1/gonum/stat"
)

func main() {
	// Dados de exemplo (amostra de uma população hipotética)
	dados := []float64{10, 15, 20, 25, 30}

	// Calculando a média dos dados
	media := stat.Mean(dados, nil)

	// Calculando o desvio padrão dos dados
	desvioPadrao := stat.StdDev(dados, nil)

	// Exibindo os resultados
	fmt.Printf("Média: %.2f\n", media)
	fmt.Printf("Desvio Padrão: %.2f\n", desvioPadrao)
}

