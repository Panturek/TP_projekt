<?php
	session_start();
	if(!($_SESSION['zalogowany']==true)){
		header('Location: loginpanel.php');
		exit();
	}
	$color = '#00aa00';
	if(!isset($_SESSION['dodano'])){
		$msg = "";
	}
	else if($_SESSION['dodano'] = true){
		$msg = "Dodano pomyślnie";
	}
	else{
		$msg = "Nie udało się dodać pomyślnie";
		$color = '#aa0000';
	}
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
<header>

<main>
	<section>
		
	<div id="okno_rejestracji" class="col-md-6 offset-md-3">
		<br/><br/>
		
		<form action="dodajsub.php" method="POST">
			<div class="field">
				<input type="text" class="zapiszka" id="front" name="front" 
				placeholder="Przód karty" autocomplete="off" required />
				<br/><br/>
			</div>

			<div class="field">
				<input type="text" class="zapiszka" id="back" name="back"
				placeholder="Tył karty" autocomplete="off" required />
				<br/><br/>
			</div>
			
			<div id='form-message'>
			<?php
				echo '<span style="color: '.$color.';">'.$msg.'</span>';
			?>
			</div>

			<div class="field">
				<button class="addBtn" type="submit" style="padding:0;">Zapisz</button>
			</div>
		</form>	
		
		<a class="addBtn" href="fiszki.php">Powrót</a>
		

	</div>
	
	</section>		
	
</main>
	

<footer>
	<?php include("./footer.php"); ?>
</footer>

</body>
</html>