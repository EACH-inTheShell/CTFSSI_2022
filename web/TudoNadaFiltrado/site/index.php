<?php
	$flag = "eits{b3m_v1nd0s_4_lf1}";
	$pagina = "home";
	if (!empty($_GET["pagina"])) {
		$pagina = $_GET["pagina"];
	}
?>

<!DOCTYPE html>
<html>
	<head>
		<meta charset="UTF-8">
		<title>Pagina</title>
	</head>
	<body>
		<nav>
			<a href="/index.php?pagina=home">home</a>
			<a href="/index.php?pagina=sobre">sobre</a>
		</nav>
		<h1><?php echo $pagina; ?></h1>
		<?php include($pagina.".php"); ?>
	</body>
</html>
