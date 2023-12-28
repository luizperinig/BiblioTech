CC=g++
CFLAGS=-std=c++11 -Wall
TARGET=program
TARGET_TESTS=test

BUILD_DIR	= ./Build/
SRC_DIR     = ./Src
MODULE_DIR  = ./Src/Modulos
INCLUDE_DIR	= ./Include

$(TARGET): ${BUILD_DIR}/Login.o ${BUILD_DIR}/Usuario.o ${BUILD_DIR}/Livro.o ${BUILD_DIR}/Gerente.o ${BUILD_DIR}/Emprestimo.o ${BUILD_DIR}/Cliente.o ${BUILD_DIR}/Bibliotecario.o ${BUILD_DIR}/Acervo.o ${BUILD_DIR}/BancoFuncionarios.o ${BUILD_DIR}/BancoClientes.o ${BUILD_DIR}/BancoEmprestimos.o ${BUILD_DIR}/Data.o ${BUILD_DIR}/main.o
	${CC} ${CFLAGS} -o ${TARGET} ${BUILD_DIR}/*.o

${BUILD_DIR}/Login.o: ${INCLUDE_DIR}/Login.hpp ${MODULE_DIR}/Login.cpp
	${CC} ${CFLAGS} -I ${INCLUDE_DIR} -c ${MODULE_DIR}/Login.cpp -o ${BUILD_DIR}/Login.o

${BUILD_DIR}/Usuario.o: ${INCLUDE_DIR}/Usuario.hpp ${MODULE_DIR}/Usuario.cpp
	${CC} ${CFLAGS} -I ${INCLUDE_DIR} -c ${MODULE_DIR}/Usuario.cpp -o ${BUILD_DIR}/Usuario.o

${BUILD_DIR}/Livro.o: ${INCLUDE_DIR}/Livro.hpp ${MODULE_DIR}/Livro.cpp
	${CC} ${CFLAGS} -I ${INCLUDE_DIR} -c ${MODULE_DIR}/Livro.cpp -o ${BUILD_DIR}/Livro.o

${BUILD_DIR}/Gerente.o: ${INCLUDE_DIR}/Gerente.hpp ${MODULE_DIR}/Gerente.cpp
	${CC} ${CFLAGS} -I ${INCLUDE_DIR} -c ${MODULE_DIR}/Gerente.cpp -o ${BUILD_DIR}/Gerente.o

${BUILD_DIR}/Emprestimo.o: ${INCLUDE_DIR}/Emprestimo.hpp ${MODULE_DIR}/Emprestimo.cpp
	${CC} ${CFLAGS} -I ${INCLUDE_DIR} -c ${MODULE_DIR}/Emprestimo.cpp -o ${BUILD_DIR}/Emprestimo.o

${BUILD_DIR}/Cliente.o: ${INCLUDE_DIR}/Cliente.hpp ${MODULE_DIR}/Cliente.cpp
	${CC} ${CFLAGS} -I ${INCLUDE_DIR} -c ${MODULE_DIR}/Cliente.cpp -o ${BUILD_DIR}/Cliente.o

${BUILD_DIR}/Bibliotecario.o: ${INCLUDE_DIR}/Bibliotecario.hpp ${MODULE_DIR}/Bibliotecario.cpp
	${CC} ${CFLAGS} -I ${INCLUDE_DIR} -c ${MODULE_DIR}/Bibliotecario.cpp -o ${BUILD_DIR}/Bibliotecario.o

${BUILD_DIR}/Acervo.o: ${INCLUDE_DIR}/Acervo.hpp ${MODULE_DIR}/Acervo.cpp
	${CC} ${CFLAGS} -I ${INCLUDE_DIR} -c ${MODULE_DIR}/Acervo.cpp -o ${BUILD_DIR}/Acervo.o

${BUILD_DIR}/BancoFuncionarios.o: ${INCLUDE_DIR}/BancoFuncionarios.hpp ${MODULE_DIR}/BancoFuncionarios.cpp
	${CC} ${CFLAGS} -I ${INCLUDE_DIR} -c ${MODULE_DIR}/BancoFuncionarios.cpp -o ${BUILD_DIR}/BancoFuncionarios.o

${BUILD_DIR}/BancoClientes.o: ${INCLUDE_DIR}/BancoClientes.hpp ${MODULE_DIR}/BancoClientes.cpp
	${CC} ${CFLAGS} -I ${INCLUDE_DIR} -c ${MODULE_DIR}/BancoClientes.cpp -o ${BUILD_DIR}/BancoClientes.o

${BUILD_DIR}/BancoEmprestimos.o: ${INCLUDE_DIR}/BancoEmprestimos.hpp ${MODULE_DIR}/BancoEmprestimos.cpp
	${CC} ${CFLAGS} -I ${INCLUDE_DIR} -c ${MODULE_DIR}/BancoEmprestimos.cpp -o ${BUILD_DIR}/BancoEmprestimos.o

${BUILD_DIR}/Data.o: ${INCLUDE_DIR}/Data.hpp ${MODULE_DIR}/Data.cpp
	${CC} ${CFLAGS} -I ${INCLUDE_DIR} -c ${MODULE_DIR}/Data.cpp -o ${BUILD_DIR}/Data.o

${BUILD_DIR}/main.o: ${INCLUDE_DIR}/Login.hpp ${INCLUDE_DIR}/Usuario.hpp ${INCLUDE_DIR}/Livro.hpp ${INCLUDE_DIR}/Gerente.hpp ${INCLUDE_DIR}/Emprestimo.hpp ${INCLUDE_DIR}/Cliente.hpp ${INCLUDE_DIR}/Bibliotecario.hpp ${INCLUDE_DIR}/Acervo.hpp ${INCLUDE_DIR}/BancoFuncionarios.hpp ${INCLUDE_DIR}/BancoClientes.hpp ${INCLUDE_DIR}/BancoEmprestimos.hpp ${INCLUDE_DIR}/Data.hpp ${SRC_DIR}/main.cpp
	${CC} ${CFLAGS} -I ${INCLUDE_DIR} -c ${SRC_DIR}/main.cpp -o ${BUILD_DIR}/main.o