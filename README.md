# Qt-contact-list

## To-do

### Layout e Funcionalidade (Qt Creator)

- [x] Layout da tela principal
- [x] Funcionalidade da tela principal
- [x] Layout da tela, criar contato
- [x] Funcionalidade da tela, criar contato
- [ ] Layout da tela, Detalhes Contato
- [ ] Funcionalidade da tela, Detalhes Contato
- [ ] Layout da tela, Editar Contato
- [ ] Funcionalidade da tela, Editar Contato
- [ ] Layout da tela, Apagar Contato
- [ ] Funcionalidade da tela, Apagar Contato

### Manipulação e estruturas das informações (C/C++)

- [ ] Definir estrutura principal que carrega as informações do contato do banco de dados(essa estrutura ira receber as informações vidas do banco)
- [ ] Função para criar contato utilizando a estrutura, o contato deve ser adicionado no banco(Atualizar contato com as novas informações)
- [ ] Função para lê contato especifico da lista pelo banco de dados(Atualizar o layoyt com as novas informações)
- [ ] Função para atualizar informações especificas de um contato especifico do banco (atualizar layout com as novas informações)
- [ ] Função para remover contato do banco(atualizar o Layout com as novas informações)

### Integração com banco (SQLite)

- [x] Inicializar obanco de dados com SQLite
- [x] Criar a tabela com os dados do contato
- [x] Integrar o banco de dados com a aplicação

---

<!-- Create struct with linked list -->

## Estrutura de dados

```c
typdef struct {
    int id; // gerar automaticamente a cada inserção
	char *name;
	int birthdayDay, birthdayMonth;
	
	char *avatarImagePath;
} tContactData;

typedef struct no {
    tContactData contact;
    struct no next;
} tContactList, *pContactList;


pContactList contactList = malloc(sizeof(tContactList));

```

<!-- Insertion of elements based on algorithm by insertion -->

## CRUD

### CREATE
Função para criar contato utilizando a estrutura

void add

### READ
Função para lê contato especifico da lista de contato

### UPDATE
Função para atualizar informações especificas de um contato especifico

### DELETE
Função para remover contato da lista de contato
