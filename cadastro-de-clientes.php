<!DOCTYPE html>
<html>
<head>
    <meta charset="UTF-8">
    <title>Cadastro de Cliente</title>
</head>
<body>

<?php
// Verifica se o formulário foi submetido
if ($_SERVER["REQUEST_METHOD"] == "POST") {
    // Obtém os dados do formulário
    $nome = $_POST["nome"];
    $email = $_POST["email"];
    $telefone = $_POST["tel"];

    // Validação simples dos campos (pode ser melhorado)
    if (empty($nome) || empty($email) || empty($telefone)) {
        echo "Por favor, preencha todos os campos obrigatórios.";
    } else {
        // Conexão com o banco de dados (substitua os valores pelas suas credenciais)
        $servidor = "localhost";
        $usuario = "seu_usuario";
        $senha = "sua_senha";
        $banco = "seu_banco";

        $conexao = mysqli_connect($servidor, $usuario, $senha, $banco);

        if (!$conexao) {
            die("Falha na conexão: " . mysqli_connect_error());
        }

        // Insere os dados na tabela de clientes (substitua 'clientes' pelo nome da sua tabela)
        $sql = "INSERT INTO clientes (nome, email, telefone) VALUES ('$nome', '$email', '$telefone')";

        if (mysqli_query($conexao, $sql)) {
            echo "Cadastro realizado com sucesso!";
        } else {
            echo "Erro ao cadastrar: " . mysqli_error($conexao);
        }

        // Fecha a conexão com o banco de dados
        mysqli_close($conexao);
    }
}
?>

<h2>Cadastro de Cliente</h2>
<form method="POST" action="<?php echo $_SERVER["PHP_SELF"]; ?>">
    <label for="nome">Nome:</label>
    <input type="text" name="nome" id="nome" required><br>

    <label for="email">Email:</label>
    <input type="email" name="email" id="email" required><br>

    <label for="telefone">Telefone:</label>
    <input type="text" name="telefone" id="telefone" required><br>

    <input type="submit" value="Cadastrar">
</form>

</body>
</html>
