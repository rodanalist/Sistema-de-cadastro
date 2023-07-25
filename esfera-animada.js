<!DOCTYPE html>
<html lang="pt-br">
<head>
  <meta charset="UTF-8">
  <meta name="viewport" content="width=device-width, initial-scale=1.0">
  <title>Esfera Animada</title>
  <style>
    body {
      margin: 0;
      overflow: hidden;
    }
    canvas {
      display: block;
    }
  </style>
</head>
<body>
  <canvas id="canvas"></canvas>

  <script>
    const canvas = document.getElementById('canvas');
    const ctx = canvas.getContext('2d');

    // Define o tamanho do canvas
    canvas.width = window.innerWidth;
    canvas.height = window.innerHeight;

    // Define a posição inicial da esfera
    let x = canvas.width / 2;
    let y = canvas.height / 2;

    // Define o tamanho e velocidade da esfera
    const radius = 50;
    const speedX = 2;
    const speedY = 2;

    function animate() {
      requestAnimationFrame(animate);

      // Limpa o canvas a cada frame
      ctx.clearRect(0, 0, canvas.width, canvas.height);

      // Desenha a esfera
      ctx.beginPath();
      ctx.arc(x, y, radius, 0, Math.PI * 2);
      ctx.fillStyle = 'blue';
      ctx.fill();

      // Verifica as colisões com as bordas do canvas
      if (x + radius > canvas.width || x - radius < 0) {
        speedX *= -1;
      }

      if (y + radius > canvas.height || y - radius < 0) {
        speedY *= -1;
      }

      // Atualiza a posição da esfera
      x += speedX;
      y += speedY;
    }

    animate();
  </script>
</body>
</html>
