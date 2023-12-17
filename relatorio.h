#ifndef relatorio_h
#define relatorio_h

void relatorios_filtro_ativos(void);
int relatorios();
int relatorios_filtro(void);
void relatorios_filtro_inativo(void);
void exibir_cliente_tabela(void);
int relatorio_tabela(void);
void exibir_funcionario_tabela(void);
void gerar_lista_cliente(Cliente **list);
void apagar_lista_cliente(Cliente **list);
void exibir_lista_cliente(Cliente *aux);
void list_alf_cliente(void);
int relatorios_ordenados(void);


#endif