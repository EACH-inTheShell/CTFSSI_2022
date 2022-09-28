<!DOCTYPE html>
<html>
	<head>
		<meta charset="UTF-8">
		<title>title</title>
	</head>
	<body>
		<?php
			if (isset($_POST["enviar"]) && isset($_FILES)) {
				if ($_FILES["arquivo"]["size"] < 10_000) { // 10K
					$tmp_dir = getcwd().uniqid("/upload/");
					$file_name = $tmp_dir."/".$_FILES["arquivo"]["name"];
					mkdir($tmp_dir, 0777, true);
					move_uploaded_file($_FILES["arquivo"]["tmp_name"], $file_name);

					echo "<pre>\n";
					system("cd $tmp_dir && unzip -qq $file_name && rm $file_name");
					passthru("cat $tmp_dir/*");
					echo "</pre>\n";
				}
			}
		?>
		<form method="post" enctype="multipart/form-data">
			<input type="file" name="arquivo">
			<input type="submit" name="enviar" value="enviar">
		</form>
	</body>
</html>
