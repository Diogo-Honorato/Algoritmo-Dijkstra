COMPILADORC = gcc

CFLAGS = -Wall -Wextra -march=native -O2 -g -lm

# Nome do executável
EXECUTABLE = tp1.exe

# Diretórios
HEADER_DIR = Programa/Headers
SRC_DIR = Programa/Sources
OBJ_DIR = Programa/Objetos

# Obter automaticamente todos os arquivos .c no diretório source
SRCS = $(wildcard $(SRC_DIR)/**/*.c)

# Gerar nomes de arquivos .o a partir dos arquivos .c
OBJS = $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRCS))

# Regra para compilar todos os arquivos .o a partir dos arquivos .c
all: $(EXECUTABLE)


$(EXECUTABLE): $(OBJS)
	@$(COMPILADORC) $(CFLAGS) $^ -o $@

# Regra para criar diretórios e compilar cada arquivo .c em um arquivo .o correspondente
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | obj_dirs
	@$(COMPILADORC) $(CFLAGS) -I $(HEADER_DIR) -c $< -o $@

# Criação dos diretórios necessários para armazenar os arquivos .o
obj_dirs:
	@mkdir -p $(dir $(OBJS))

run:$(EXECUTABLE)
	@./$(EXECUTABLE)

leak:$(EXECUTABLE)
	@valgrind --leak-check=full ./$(EXECUTABLE)

debug:$(EXECUTABLE)
	gdb ./$(EXECUTABLE)

DDD:$(EXECUTABLE)
	ddd $(EXECUTABLE)

# Limpar arquivos objeto e o executável
clean:
	@rm -rf $(OBJ_DIR) $(EXECUTABLE)