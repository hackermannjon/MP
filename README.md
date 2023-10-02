# MP
 Trabalhos para Métodos em Programação
 
# README - Compilação e Execução do Projeto

Este README fornece instruções resumidas sobre como compilar e executar o projeto usando o Makefile fornecido. Certifique-se de ter o GCC (GNU Compiler Collection) e o utilitário Make instalados no seu sistema. O projeto já depende da biblioteca Google Test para testes.

Para compilar o projeto, abra um terminal, navegue até o diretório raiz do projeto e execute `make`. Após a compilação, execute o programa com `./testa_velha`. Use `make clean` para limpar os arquivos de compilação e `make coverage` para executar testes de cobertura (opcional). O Valgrind pode ser usado com `make valgrind` para detecção de vazamento de memória (opcional).
