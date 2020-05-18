<?php
	session_start();
	$_SESSION['pageid'] = 'zdjecia';
?>

<!DOCTYPE HTML>
<html lang="pl">
<head>
	<meta charset="utf-8">
	
	<title>Projekt zaliczeniowy z przedmiotu aplikacje mobilne i internetowe </title>
	<meta name="description" content="Projekt zaliczeniowy">
	<meta name="keywords" content="projekt, zaliczenie, wykładu">
	<meta name="author" content="Jan Hałasiński">
	<meta http-equiv="X-Ua-Compatible" content="IE=edge">
	<meta name="viewport" content="width=device-width, initial-scale=1, shrink-to-fit=no">

	
	<link rel="stylesheet" href="css/bootstrap.min.css">
	<link rel="stylesheet" href="main.css">
	<link rel="stylesheet" type="text/css" href="img/sliderstyle.css" />
	<link href="https://fonts.googleapis.com/css?family=Open+Sans:400,700&amp;subset=latin-ext" rel="stylesheet">

	<script src="https://code.jquery.com/jquery-3.3.1.slim.min.js" integrity="sha384-q8i/X+965DzO0rT7abK41JStQIAqVgRVzpbzo5smXKp4YfRvH+8abtTE1Pi6jizo" crossorigin="anonymous"></script>
	
	<script src="https://cdnjs.cloudflare.com/ajax/libs/popper.js/1.14.3/umd/popper.min.js" integrity="sha384-ZMP7rVo3mIykV+2+9J3UJ46jBk0WLaUAdn689aCwoqbBJiSnjAK/l8WvCWPIPm49" crossorigin="anonymous"></script>
	
	<script src="js/bootstrap.min.js"></script>
	
	<script src="http://code.jquery.com/jquery-1.11.2.min.js"></script>
	
	
</head>

<body>
<header>
	<?php
		include('./nav.php');
	?>
</header>

<main>
	<div id="container" class="col-md-10 col-xl-8 offset-md-1 offset-xl-2">
	
	<div id="slideshow">
			<ul class="slides">
				<li><img src="img/photos/1.jpg" width="620" height="320"  /></li>
				<li><img src="img/photos/2.jpg" width="620" height="320"  /></li>
				<li><img src="img/photos/3.jpg" width="620" height="320"  /></li>
				<li><img src="img/photos/4.jpg" width="620" height="320"  /></li>
			</ul>

			<span class="arrow previous"></span>
			<span class="arrow next"></span>
		</div>
	</div>
	<script src="jssrc/sliderscript.js"></script>		
</main>

<footer>
	<?php include("./footer.php"); ?>
</footer>

</body>
</html>