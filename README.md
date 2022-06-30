# Qt-contact-list

## To-do

### Layout e Funcionalidade (Qt Creator)

- [x] Layout da tela principal
- [x] Funcionalidade da tela principal
- [x] Layout da tela, criar contato
- [x] Funcionalidade da tela, criar contato
- [x] Layout da tela, Detalhes Contato
- [x] Funcionalidade da tela, Detalhes Contato
- [x] Layout da tela, Editar Contato
- [x] Funcionalidade da tela, Editar Contato
- [x] Layout da tela, Apagar Contato
- [x] Funcionalidade da tela, Apagar Contato

### Manipulação e estruturas das informações (C/C++)

- [x] Definir estrutura principal que carrega as informações do contato do banco de dados(essa estrutura ira receber as informações vidas do banco)
- [x] Função para criar contato utilizando a estrutura, o contato deve ser adicionado no banco(Atualizar contato com as novas informações)
- [x] Função para lê contato especifico da lista pelo banco de dados(Atualizar o layoyt com as novas informações)
- [x] Função para atualizar informações especificas de um contato especifico do banco (atualizar layout com as novas informações)
- [x] Função para remover contato do banco(atualizar o Layout com as novas informações)

### Integração com banco (SQLite)

- [x] Inicializar obanco de dados com SQLite
- [x] Criar a tabela com os dados do contato
- [x] Integrar o banco de dados com a aplicação

---

<!-- Create struct with linked list -->

## Estrutura de dados

```c
struct tContactData {
    int id;
    QString name;
    QString birthdayDay, birthdayMonth;
    QString pathImage = ":/images/assets/person-circle.png";
};
```
