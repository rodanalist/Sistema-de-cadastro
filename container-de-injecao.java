public class Ambientes { public Ambiente desenvolvimento() { return homologacao().com(OpenIdLogin.class); }

public Ambiente homologacao() { return producao().com(ExcelExport.class); }

public Ambiente producao() { return new Ambiente(new Container()).com(ClienteController.class).e(ProjetoController.class).e(LoginController.class); } } 