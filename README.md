### Projeto DGEMM - Arquitetura de Computadores

Este projeto tem como objetivo implementar a multiplicação de matrizes (DGEMM) utilizando diferentes linguagens de programação. A multiplicação de matrizes é uma operação fundamental em diversas áreas, como ciência da computação, engenharia e matemática, e otimizar essa operação pode levar a melhorias significativas no desempenho de algoritmos que dependem dela.

Esse projeto se baseia no livro "Computer Organization and Design RISC-V Edition: The Hardware Software Interface", mais especificamente nos capítulos "Going Faster" dos tópicos do livro. A cada tópico, implementamos a multiplicação de matrizes, porém com diferentes abordagens (tanto de linguagem de programação quanto de otimização). O objetivo é comparar o desempenho das diferentes implementações e entender as vantagens e desvantagens de cada abordagem.

#### Linguagens Utilizadas

- Python
- C

#### Estrutura do Projeto

O projeto está organizado da seguinte maneira:

```
EEL580-DEGEMM/
├─ src/
│  ├─ Capítulo 1/
│  │  ├─ logs.txt
│  │  └─ python_dgemm.py
│  ├─ Capítulo 1 (extra)/
│  │  ├─ logs.txt
│  │  └─ numpy_dgemm.py
│  └─ Capítulo 2/
│     ├─ c_dgemm
│     ├─ logs.txt
│     └─ c_dgemm.c
├─ Dados_Coletados.ods
└─ README.md
```

### Implementações

1. **Capítulo 1 - Python DGEMM**: Implementação da multiplicação de matrizes utilizando Python puro.
2. **Capítulo 1 (extra) - NumPy DGEMM**: Implementação da multiplicação de matrizes utilizando a biblioteca NumPy, que é otimizada para operações de álgebra linear.
3. **Capítulo 2 - C DGEMM**: Implementação da multiplicação de matrizes utilizando a linguagem C pura.

### Coleta de Dados

Para cada implementação, foram coletados dados de desempenho, como tempo de execução e tempo de uso da CPU. Esses dados estão registrados nos arquivos `logs.txt` correspondentes a cada implementação e também estão organizados no arquivo `Dados_Coletados.ods` para facilitar a análise comparativa.

### Tasks List

- [x] Implementar DGEMM em Python
- [x] Implementar DGEMM utilizando NumPy
- [x] Implementar DGEMM em C
- [ ] Implementar otimizações para a versão em C
- [ ] Coletar dados de desempenho para cada implementação

### Conclusão

Este projeto permite uma comparação direta entre diferentes abordagens para a multiplicação de matrizes, destacando as vantagens e desvantagens de cada linguagem e técnica de otimização. A análise dos dados coletados ajudará a entender melhor como as escolhas de implementação afetam o desempenho em operações de álgebra linear.

